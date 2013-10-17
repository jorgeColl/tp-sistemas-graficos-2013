/*
 * figura.cpp
 *
 *  Created on: 22/09/2013
 *      Author: jorge
 */

#include "figura.h"

void Figura::agregar_figura_hija(Figura& fig) {
	figuras_hijas.push_back(&fig);
}

void Figura::animar(){}

void Figura::renderizar(glm::mat4 model_matrix) {
	this->mi_superficie->render(model_matrix);
}

void Figura::renderizar_figuras_hijas(glm::mat4 model_matrix) {
	for(unsigned int i=0; i<figuras_hijas.size();++i) {
		figuras_hijas[i]->renderizar(model_matrix);
	}
}

Superficie* Figura::crear_superficie (myWindow* ventana) {
	Curva* trayectoria = this->crear_curva_trayectoria ();
	Curva* seccion = this->crear_curva_seccion ();
	int pasosTrayectoria = this->obtener_pasos_trayectoria ();
	int pasosSeccion = this->obtener_pasos_seccion ();
	std::vector<glm::mat4> transformaciones = this->crear_transformaciones ();
	return (new SuperficieBarrido (trayectoria, seccion, pasosTrayectoria, pasosSeccion, transformaciones, ventana));
}

Curva* Figura::crear_curva_trayectoria () {
	return (new Curva(glm::vec3(0.0,0.0,0.0),glm::vec3(0.0,0.0,1.0)));
}
Curva* Figura::crear_curva_seccion () {
	return (new Curva(glm::vec3(0.0,0.0,0.0),glm::vec3(0.0,0.0,1.0)));
}

float Figura::obtener_coef_expansion() {
	return 1.0;
}

float Figura::obtener_valor_inicial_funcion() {
	return 0.0;
}

float Figura::obtener_valor_final_funcion() {
	return 0.0;
}

FuncionCurvaBezier Figura::crear_funcion () {
	std::vector<glm::vec3> puntos;
	puntos.push_back ( glm::vec3 (0.0, this->obtener_valor_inicial_funcion(), 0.0) );
	puntos.push_back ( glm::vec3 (0.03 * this->obtener_pasos_trayectoria(), 0.97 * this->obtener_coef_expansion(), 0.0) );
	puntos.push_back ( glm::vec3 (0.5 * this->obtener_pasos_trayectoria(), 1.0 * this->obtener_coef_expansion(), 0.0) );
	puntos.push_back ( glm::vec3 (0.97 * this->obtener_pasos_trayectoria(), 0.97 * this->obtener_coef_expansion(), 0.0) );
	puntos.push_back ( glm::vec3 (this->obtener_pasos_trayectoria(), this->obtener_valor_final_funcion(), 0.0) );
	return (FuncionCurvaBezier(puntos));
}

std::vector<glm::mat4> Figura::crear_transformaciones () {
	std::vector<glm::mat4> transformaciones;
	
	int pasosTrayectoria = this->obtener_pasos_trayectoria();
	FuncionCurvaBezier funcion = this->crear_funcion();
	
	for (int i = 0 ; i <= pasosTrayectoria ; i++) {
		float coef = 0.0;
		coef = funcion.evaluar_en (i * 1.0);
		if (coef < 0.0) coef *= (-1);
		glm::mat4 matriz = glm::scale ( glm::mat4 (1.0f) , glm::vec3 (coef, coef, coef));
		transformaciones.push_back(matriz);
	}
	return transformaciones;
}

std::vector<glm::mat4> Figura::transformacion_parabolica () {
	std::vector<glm::mat4> transformaciones;
	
	int pasosTrayectoria = this->obtener_pasos_trayectoria();
	float a2 = (-4.0) / Helper::potencia (pasosTrayectoria, 2);
	Parabola funcion = Parabola (0.0, pasosTrayectoria, a2 , true);
	
	for (int i = 0 ; i <= pasosTrayectoria ; i++) {
		float coef = funcion.evaluar_en (i * 1.0);
		glm::mat4 matriz = glm::scale ( glm::mat4 (1.0f) , glm::vec3 (coef, coef, coef));
		transformaciones.push_back(matriz);
	}
	return transformaciones;
}

Figura::~Figura () {
	delete this->mi_superficie;
	
	// lineas temporales
	delete this->mySphere;
	delete this->myCube;
}

// de aca para abajo, todo temporal, despues vuela
Figura::Figura (myWindow* ventana) {
	this->mySphere = new Esfera (ventana, 1.0, 32, 32);
    this->myCube = new Cubo (ventana);
}

void Figura::renderArm (glm::mat4 model_matrix) {
    this->mySphere->render(model_matrix);

    model_matrix = glm::scale(model_matrix, glm::vec3 (0.6f, 0.6f, 3.0f) );
    model_matrix = glm::translate(model_matrix , glm::vec3(0.0, 0.0, 0.5) );

    this->myCube->render(model_matrix);
}


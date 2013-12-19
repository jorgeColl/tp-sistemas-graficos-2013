/*
 * Planta.cpp
 *
 *  Created on: 10/10/2013
 *      Author: jorge
 */

#include "Planta.h"

#define PI 3.1415926f

// ****************************** PLANTA *******************************
Planta::Planta(myWindow* ventana):Figura(ventana),hoja1(ventana),hoja2(ventana),hoja3(ventana) {
	this->mi_superficie = this->crear_superficie (ventana);
}
Planta::~Planta() { }

void Planta::renderizar(glm::mat4 model_matrix) {
	glm::mat4 model_temp;
	glm::vec3 ejeX (1,0,0);

	model_temp = glm::translate(model_matrix,glm::vec3(0,0,-(hoja1.altura/2)));
	model_temp = glm::rotate(model_temp,-13.0f,ejeX);
	model_temp = glm::translate(model_temp,glm::vec3(0,0,(hoja1.altura/2)));
	hoja1.renderizar(model_temp);

	hoja2.renderizar(model_matrix);

	model_temp = glm::translate(model_matrix,glm::vec3(0,0,-(hoja3.altura/2)));
	model_temp = glm::rotate(model_temp,13.0f,ejeX);
	model_temp = glm::translate(model_temp,glm::vec3(0,0,(hoja3.altura/2)));
	hoja3.renderizar(model_temp);
}

void Planta::animar() {
	this->hoja1.animar();
	this->hoja2.animar();
	this->hoja3.animar();
}

// ************************** HOJAS DE PLANTA **************************
HojaPlanta::HojaPlanta(myWindow* ventana): Figura(ventana) {
	this->altura = Helper::num_aleatorio (1.8, 2.7);
	this->mi_superficie = this->crear_superficie (ventana);
	this->mi_superficie->nombreTextura="hoja.jpg";
	//this->mi_superficie->nombreTexturaNormal="hojaNormal.jpg";
	
	this->mi_superficie->ka = glm::vec3(0.8, 0.8, 1.0);
	this->mi_superficie->kd = glm::vec3(0.8, 0.8, 0.8);
	this->mi_superficie->ks = glm::vec3(0.3, 0.3, 0.3);
	this->mi_superficie->shininess = 35.0;
	
	
	float amplitud = Helper::num_aleatorio (0.10, 0.15);
	float numeroOnda = 2; // long de onda = PI
	float velocidad = 0.1 * PI * Helper::num_aleatorio (0.0, PI / 20.0); // atenuacion * long de onda * frecuencia
	this->mi_superficie->set_parametros_animacion (amplitud, numeroOnda, velocidad);
}
HojaPlanta::~HojaPlanta() { }

void HojaPlanta::animar() {
	this->mi_superficie->animar();
}

Curva* HojaPlanta::crear_curva_trayectoria () {
	std::vector<glm::vec3> control_trayectoria;
	
	control_trayectoria.push_back ( glm::vec3 ( 0.0, 0.0, 0.0) );
	control_trayectoria.push_back ( glm::vec3 ( 0.0, 0.0, this->altura) );
	return (new CurvaBezier (control_trayectoria, glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 0.0, 1.0)));
}
Curva* HojaPlanta::crear_curva_seccion () {
	float ancho = Helper::num_aleatorio (0.25, 0.35);
	return (new Elipse(glm::vec3(0.0,0.0,0.0), ancho, 0.02));
}
int HojaPlanta::obtener_pasos_trayectoria () {
	return 25;
}
int HojaPlanta::obtener_pasos_seccion () {
	return 50;
}

FuncionCurvaBezier HojaPlanta::crear_funcion () {
	std::vector<glm::vec3> puntos;
	puntos.push_back ( glm::vec3 (0.0, 0.15, 0.0) );
	puntos.push_back ( glm::vec3 (0.5 * this->obtener_pasos_trayectoria(), 1.0, 0.0) );
	puntos.push_back ( glm::vec3 (this->obtener_pasos_trayectoria(), 0.005, 0.0) );
	return (FuncionCurvaBezier(puntos));
}

/*
 * Planta.cpp
 *
 *  Created on: 10/10/2013
 *      Author: jorge
 */

#include "Planta.h"

// ****************************** PLANTA *******************************
Planta::Planta(myWindow* ventana):Figura(ventana),hoja1(ventana),hoja2(ventana),hoja3(ventana) {
	this->mi_superficie = this->crear_superficie (ventana);
}
Planta::~Planta() { }

void Planta::renderizar(glm::mat4 model_matrix) {
	glm::mat4 model_temp;
	glm::vec3 ejeX (1,0,0);

	model_temp = glm::translate(model_matrix,glm::vec3(0,0,-1));
	model_temp = glm::rotate(model_temp,-20.0f,ejeX);
	model_temp = glm::translate(model_temp,glm::vec3(0,0,1));
	hoja1.renderizar(model_temp);

	hoja2.renderizar(model_matrix);

	model_temp = glm::translate(model_matrix,glm::vec3(0,0,-1));
	model_temp = glm::rotate(model_temp,20.0f,ejeX);
	model_temp = glm::translate(model_temp,glm::vec3(0,0,1));
	hoja3.renderizar(model_temp);
}

// ************************** HOJAS DE PLANTA **************************
HojaPlanta::HojaPlanta(myWindow* ventana): Figura(ventana) {
	this->mi_superficie = this->crear_superficie (ventana);
}
HojaPlanta::~HojaPlanta() { }

void HojaPlanta::renderizar(glm::mat4 model_matrix) {
	model_matrix = glm::scale(model_matrix, glm::vec3 (1.0,0.02,1.0));
	Figura::renderizar(model_matrix);
}

Curva* HojaPlanta::crear_curva_trayectoria () {
	std::vector<glm::vec3> control_trayectoria;
	
	float altura = Helper::num_aleatorio (1.8, 2.7);
	control_trayectoria.push_back ( glm::vec3 ( 0.0, 0.0, 0.0) );
	control_trayectoria.push_back ( glm::vec3 ( 0.0, -0.01, altura / 2) );
	control_trayectoria.push_back ( glm::vec3 ( 0.0, 0.0, altura) );
	return (new CurvaBezier (control_trayectoria, glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 0.0, 1.0)));
}
Curva* HojaPlanta::crear_curva_seccion () {
	float radio = Helper::num_aleatorio (0.2, 0.4);
	return (new Circunferencia(glm::vec3(0.0,0.0,0.0),radio));
}
int HojaPlanta::obtener_pasos_trayectoria () {
	return 50;
}
int HojaPlanta::obtener_pasos_seccion () {
	return 100;
}
std::vector<glm::mat4> HojaPlanta::crear_transformaciones () {
	return (this->transformacion_parabolica());
}

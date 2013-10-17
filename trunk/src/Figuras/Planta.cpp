/*
 * Planta.cpp
 *
 *  Created on: 10/10/2013
 *      Author: jorge
 */

#include "Planta.h"

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

// PARA HACER !!!
Curva* Planta::crear_curva_trayectoria () {
	return (new Curva(glm::vec3(0.0,0.0,0.0),glm::vec3(0.0,0.0,1.0)));
}
Curva* Planta::crear_curva_seccion () {
	return (new Curva(glm::vec3(0.0,0.0,0.0),glm::vec3(0.0,0.0,1.0)));
}
int Planta::obtener_pasos_trayectoria () {
	return 500;
}
int Planta::obtener_pasos_seccion () {
	return 500;
}
std::vector<glm::mat4> Planta::crear_transformaciones () {
	return (std::vector<glm::mat4>());
}

// TEMPORAL!!!
Superficie* Planta::crear_superficie (myWindow* ventana) {
	return (new Esfera (ventana, 1.0, 32, 32));
}
// ############# HOJAS DE PLANTA ##################################

HojaPlanta::HojaPlanta(myWindow* ventana):Figura(ventana) {
	this->mi_superficie = this->crear_superficie (ventana);
}
HojaPlanta::~HojaPlanta() { }

void HojaPlanta::renderizar(glm::mat4 model_matrix) {
	model_matrix = glm::scale(model_matrix, glm::vec3 (0.2,0.2,1.2));
	Figura::renderizar(model_matrix);
}

// PARA HACER !!!
Curva* HojaPlanta::crear_curva_trayectoria () {
	return (new Curva(glm::vec3(0.0,0.0,0.0),glm::vec3(0.0,0.0,1.0)));
}
Curva* HojaPlanta::crear_curva_seccion () {
	return (new Curva(glm::vec3(0.0,0.0,0.0),glm::vec3(0.0,0.0,1.0)));
}
int HojaPlanta::obtener_pasos_trayectoria () {
	return 500;
}
int HojaPlanta::obtener_pasos_seccion () {
	return 500;
}
std::vector<glm::mat4> HojaPlanta::crear_transformaciones () {
	return (std::vector<glm::mat4>());
}

// TEMPORAL!!!
Superficie* HojaPlanta::crear_superficie (myWindow* ventana) {
	return (new Esfera (ventana, 1.0, 32, 32));
}

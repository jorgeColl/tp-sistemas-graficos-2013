/*
 * Pez.cpp
 *
 *  Created on: 12/10/2013
 *      Author: jorge
 */

#include "Pez.h"

// ******************************* ALETA *******************************
AletaPez::AletaPez(myWindow* ventana) :Figura(ventana) {
	this->mi_superficie = this->crear_superficie (ventana);
}
AletaPez::~AletaPez() { }
void AletaPez::renderizar(glm::mat4 model_matrix) {
	model_matrix = glm::scale(model_matrix,glm::vec3(0.5,0.5,1.5));
	Figura::renderizar(model_matrix);
}

// PARA HACER !!!
Curva* AletaPez::crear_curva_trayectoria () {
	return (new Curva(glm::vec3(0.0,0.0,0.0),glm::vec3(0.0,0.0,1.0)));
}
Curva* AletaPez::crear_curva_seccion () {
	return (new Curva(glm::vec3(0.0,0.0,0.0),glm::vec3(0.0,0.0,1.0)));
}
int AletaPez::obtener_pasos_trayectoria () {
	return 500;
}
int AletaPez::obtener_pasos_seccion () {
	return 500;
}
std::vector<glm::mat4> AletaPez::crear_transformaciones () {
	return (std::vector<glm::mat4>());
}

// TEMPORAL!!!
Superficie* AletaPez::crear_superficie (myWindow* ventana) {
	return (new Cubo (ventana));
}

// ******************************* COLA ********************************
ColaPez::ColaPez(myWindow* ventana) :Figura(ventana) {
	this->mi_superficie = this->crear_superficie (ventana);
}
ColaPez::~ColaPez() { }
void ColaPez::renderizar(glm::mat4 model_matrix) {

}

// PARA HACER !!!
Curva* ColaPez::crear_curva_trayectoria () {
	return (new Curva(glm::vec3(0.0,0.0,0.0),glm::vec3(0.0,0.0,1.0)));
}
Curva* ColaPez::crear_curva_seccion () {
	return (new Curva(glm::vec3(0.0,0.0,0.0),glm::vec3(0.0,0.0,1.0)));
}
int ColaPez::obtener_pasos_trayectoria () {
	return 500;
}
int ColaPez::obtener_pasos_seccion () {
	return 500;
}
std::vector<glm::mat4> ColaPez::crear_transformaciones () {
	return (std::vector<glm::mat4>());
}

// TEMPORAL!!!
Superficie* ColaPez::crear_superficie (myWindow* ventana) {
	return (new Cubo (ventana));
}

// ******************************* TORSO *******************************
TorsoPez::TorsoPez(myWindow* ventana) :Figura(ventana) {
	this->mi_superficie = this->crear_superficie (ventana);
}
TorsoPez::~TorsoPez() { }
void TorsoPez::renderizar(glm::mat4 model_matrix) {

}

// PARA HACER !!!
Curva* TorsoPez::crear_curva_trayectoria () {
	return (new Curva(glm::vec3(0.0,0.0,0.0),glm::vec3(0.0,0.0,1.0)));
}
Curva* TorsoPez::crear_curva_seccion () {
	return (new Curva(glm::vec3(0.0,0.0,0.0),glm::vec3(0.0,0.0,1.0)));
}
int TorsoPez::obtener_pasos_trayectoria () {
	return 500;
}
int TorsoPez::obtener_pasos_seccion () {
	return 500;
}
std::vector<glm::mat4> TorsoPez::crear_transformaciones () {
	return (std::vector<glm::mat4>());
}

// TEMPORAL!!!
Superficie* TorsoPez::crear_superficie (myWindow* ventana) {
	return (new Cubo (ventana));
}

// ******************************** PEZ ********************************
Pez::Pez(myWindow* ventana) : Figura (ventana),aleta1(ventana),aleta2(ventana),cola(ventana),torso(ventana) {
	this->mi_superficie = this->crear_superficie (ventana);
}
Pez::~Pez() {}
void Pez::renderizar(glm::mat4 model_matrix) {
	aleta1.renderizar(model_matrix);
	aleta2.renderizar(model_matrix);
	cola.renderizar(model_matrix);
	torso.renderizar(model_matrix);
}


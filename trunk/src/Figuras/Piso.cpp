/*
 * Piso.cpp
 *
 *  Created on: 10/10/2013
 *      Author: jorge
 */

#include "Piso.h"

Piso::Piso(myWindow* ventana):Figura(ventana) {
	this->mi_superficie = this->crear_superficie (ventana);
}
Piso::~Piso() { }

// PARA HACER !!!
Curva* Piso::crear_curva_trayectoria () {
	return (new Curva(glm::vec3(0.0,0.0,0.0),glm::vec3(0.0,0.0,1.0)));
}
Curva* Piso::crear_curva_seccion () {
	return (new Curva(glm::vec3(0.0,0.0,0.0),glm::vec3(0.0,0.0,1.0)));
}
int Piso::obtener_pasos_trayectoria () {
	return 500;
}
int Piso::obtener_pasos_seccion () {
	return 500;
}
std::vector<glm::mat4> Piso::crear_transformaciones () {
	return (std::vector<glm::mat4>());
}

// TEMPORAL!!!
Superficie* Piso::crear_superficie (myWindow* ventana) {
	return (new Grilla (ventana, 10));
}

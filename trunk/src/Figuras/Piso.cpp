/*
 * Piso.cpp
 *
 *  Created on: 10/10/2013
 *      Author: jorge
 */

#include "Piso.h"

const float Piso::LARGO = 100.0;
const float Piso::ANCHO = 100.0;

Piso::Piso(myWindow* ventana):Figura(ventana) {
	this->mi_superficie = this->crear_superficie (ventana);
	this->mi_superficie->nombreTextura="piso.jpg";
	//this->mi_superficie->nombreTexturaNormal="pisoNormal.jpg";
}
Piso::~Piso() { }

Curva* Piso::crear_curva_trayectoria () {
	std::vector<glm::vec3> control_trayectoria;
	control_trayectoria.push_back ( glm::vec3 ( -Piso::LARGO/2.0, 0.0, 0.0) );
	control_trayectoria.push_back ( glm::vec3 ( Piso::LARGO/2.0, 0.0, 0.0) );
	return (new CurvaBezier (control_trayectoria, glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 0.0, 1.0)));
}

Curva* Piso::crear_curva_seccion () {
	std::vector<glm::vec3> control_seccion;
	
	control_seccion.push_back ( glm::vec3 (0.0, -Piso::ANCHO/2.0 , 0.0) );
	control_seccion.push_back ( glm::vec3 (0.0,  Piso::ANCHO/2.0 , 0.0) );
	return (new CurvaBezier (control_seccion, glm::vec3(0.0, 0.0, 0.0), glm::vec3(-1.0, 0.0, 0.0)));
}

int Piso::obtener_pasos_trayectoria () {
	return Piso::LARGO;
}

int Piso::obtener_pasos_seccion () {
	return Piso::ANCHO;
}

std::vector<glm::mat4> Piso::crear_transformaciones () {
	return (std::vector<glm::mat4>());
}

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

std::vector<glm::mat4> Figura::crear_transformaciones () {
	return (std::vector<glm::mat4>());
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


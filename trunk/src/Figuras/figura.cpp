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

void Figura::renderizar_figuras_hijas(glm::mat4 model_matrix) {
	for(unsigned int i=0; i<figuras_hijas.size();++i) {
		figuras_hijas[i]->renderizar(model_matrix);
	}
}


// de aca para abajo, todo temporal, despues vuela
#include "Esfera.h"
#include "Cubo.h"

Figura::Figura (myWindow* ventana) {
	this->mi_superficie = NULL;
	this->mySphere = new Esfera (ventana, 1.0, 32, 32);
    this->myCube = new Cubo (ventana);
}

Figura::~Figura () {
	delete this->mySphere;
	delete this->myCube;
}

void Figura::renderArm (glm::mat4 model_matrix) {
    this->mySphere->render(model_matrix);

    model_matrix = glm::scale(model_matrix, glm::vec3 (0.6f, 0.6f, 3.0f) );
    model_matrix = glm::translate(model_matrix , glm::vec3(0.0, 0.0, 0.5) );

    this->myCube->render(model_matrix);
}


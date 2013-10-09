/*
 * Piedra.cpp
 *
 *  Created on: 08/10/2013
 *      Author: jorge
 */

#include "piedra.h"
#include "Esfera.h"

Piedra::Piedra(myWindow* ventana) : Figura (ventana) {
	this->mi_superficie = new Esfera (ventana, 1.0, 32, 32);
}

Piedra::~Piedra() {
	delete this->mi_superficie;
}


void Piedra::renderizar(glm::mat4 model_matrix) {
	// temporalmente aca
	model_matrix = glm::translate(model_matrix,glm::vec3(5,5,0.4));

	model_matrix = glm::scale(model_matrix,glm::vec3(0.3,0.3,0.3));
	this->mi_superficie->render(model_matrix);
}

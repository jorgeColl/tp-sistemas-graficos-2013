/*
 * Piedra.cpp
 *
 *  Created on: 08/10/2013
 *      Author: jorge
 */

#include "piedra.h"

Piedra::Piedra(myWindow* window) {
	this->window = window;
}

Piedra::~Piedra() {
}


void Piedra::renderizar(glm::mat4 model_matrix) {
	// temporalmente aca
	model_matrix = glm::translate(model_matrix,glm::vec3(5,5,0.4));

	model_matrix = glm::scale(model_matrix,glm::vec3(0.3,0.3,0.3));
	this->window->renderSpiralSphere(model_matrix);
}

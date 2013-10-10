/*
 * Planta.cpp
 *
 *  Created on: 10/10/2013
 *      Author: jorge
 */

#include "Planta.h"

Planta::Planta(myWindow* ventana):Figura(ventana) {
	this->mi_superficie = new Esfera (ventana, 1.0, 32, 32);

}

Planta::~Planta() {
	delete this->mi_superficie;
}

void Planta::renderizar(glm::mat4 model_matrix) {
	// Temporalmente aca
	model_matrix = glm::translate(model_matrix, glm::vec3 (-5.0f,5.0f,0.9f));
	model_matrix = glm::scale(model_matrix, glm::vec3 (0.2,0.2,1.2));

	this->mi_superficie->render(model_matrix);
}

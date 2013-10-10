/*
 * Escenario.cpp
 *
 *  Created on: 10/10/2013
 *      Author: jorge
 */

#include "Escenario.h"

Escenario::Escenario(myWindow* ventana):Figura(ventana),cangrejo1 (ventana), piedra1 (ventana),planta1(ventana),piso(ventana) {

}

Escenario::~Escenario() { }

void Escenario::renderizar(glm::mat4 model_matrix) {
	this->piso.renderizar(model_matrix);

	glm::mat4 model_matrix_cangrejo1 = glm::translate(model_matrix, glm::vec3 (0.0f,0.0f,1.3f));
	this->cangrejo1.renderizar(model_matrix_cangrejo1);

	glm::mat4 model_matrix_planta1 = glm::translate(model_matrix, glm::vec3 (-5.0f,5.0f,0.9f));
	this->planta1.renderizar(model_matrix_planta1);

	glm::mat4 model_matrix_piedra1 = glm::translate(model_matrix,glm::vec3(5,5,0));
	this->piedra1.renderizar(model_matrix_piedra1);
}

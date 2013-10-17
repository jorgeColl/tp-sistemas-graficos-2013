/*
 * Escenario.cpp
 *
 *  Created on: 10/10/2013
 *      Author: jorge
 */

#include "Escenario.h"

Escenario::Escenario(myWindow* ventana):Figura(ventana),pez1(ventana),cangrejo1 (ventana), piedra1 (ventana),planta1(ventana),piso(ventana) {
	pos_cangrejo1=glm::vec3 (0,0,1.3f);
	pos_pez1 = glm::vec3 (-3,0,0.4f);

	figuras.push_back(&cangrejo1);
	figuras.push_back(&pez1);
	figuras.push_back(&piedra1);
	figuras.push_back(&planta1);
	figuras.push_back(&piso);


	std::vector<glm::vec3> puntos;

	puntos.push_back(glm::vec3(0, 0, 0));
	puntos.push_back(glm::vec3(0, 0, 0));
	puntos.push_back(glm::vec3(1, 0, 0));
	puntos.push_back(glm::vec3(2, 0, 0));
	puntos.push_back(glm::vec3(3, 1, 0));
	puntos.push_back(glm::vec3(4, 2, 0));
	puntos.push_back(glm::vec3(5, 3, 0));
	puntos.push_back(glm::vec3(6, 4, 0));
	puntos.push_back(glm::vec3(7, 3, 0));
	puntos.push_back(glm::vec3(8, 2, 0));
	puntos.push_back(glm::vec3(9, 1, 0));
	puntos.push_back(glm::vec3(10, 0, 0));
	puntos.push_back(glm::vec3(11, -1, 0));
	puntos.push_back(glm::vec3(12, -2, 0));
	pez1.set_trayecto(puntos);
	
	this->grilla_debug = new Grilla (ventana, 10);
	this->mi_superficie = this->crear_superficie (ventana);
}

Escenario::~Escenario() { delete (this->grilla_debug); }

// true para ver la grilla, false para ver el piso
const bool Escenario::DEBUG = true;

void Escenario::renderizar(glm::mat4 model_matrix) {
	if (Escenario::DEBUG) this->grilla_debug->render(model_matrix);
		else this->piso.renderizar(model_matrix);

	glm::mat4 model_matrix_pez1=model_matrix;
	//model_matrix_pez1 = glm::translate(model_matrix, pos_pez1);
	this->pez1.renderizar(model_matrix_pez1);

	glm::mat4 model_matrix_cangrejo1 = glm::translate(model_matrix, pos_cangrejo1);
	//this->cangrejo1.renderizar(model_matrix_cangrejo1);

	glm::mat4 model_matrix_planta1 = glm::translate(model_matrix, glm::vec3 (-5.0f,5.0f,0.9f));
	//this->planta1.renderizar(model_matrix_planta1);

	glm::mat4 model_matrix_piedra1 = glm::translate(model_matrix,glm::vec3(5,5,0));
	//this->piedra1.renderizar(model_matrix_piedra1);
}
void Escenario::animar() {
	for (unsigned int i = 0; i<figuras.size(); ++i) {
		figuras[i]->animar();
	}
}

/*
 * Escenario.cpp
 *
 *  Created on: 10/10/2013
 *      Author: jorge
 */

#include "Escenario.h"

Escenario::Escenario(myWindow* ventana):Figura(ventana),pez1(ventana),cangrejo1 (ventana), piedra1 (ventana),planta1(ventana),piso(ventana),pos_cangrejo(0,0,1.3f) {
	figuras.push_back(&cangrejo1);
	figuras.push_back(&pez1);
	figuras.push_back(&piedra1);
	figuras.push_back(&planta1);
	figuras.push_back(&piso);
	vuelta_cangrejo = false;

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
	this->mi_superficie = this->crear_superficie (ventana);
}

Escenario::~Escenario() { }

void Escenario::renderizar(glm::mat4 model_matrix) {
	this->piso.renderizar(model_matrix);

	this->pez1.renderizar(model_matrix);

	glm::mat4 model_matrix_cangrejo1 = glm::translate(model_matrix, pos_cangrejo);
	//this->cangrejo1.renderizar(model_matrix_cangrejo1);

	glm::mat4 model_matrix_planta1 = glm::translate(model_matrix, glm::vec3 (-5.0f,5.0f,0.9f));
	//this->planta1.renderizar(model_matrix_planta1);

	glm::mat4 model_matrix_piedra1 = glm::translate(model_matrix,glm::vec3(5,5,0));
	//this->piedra1.renderizar(model_matrix_piedra1);
}
void Escenario::animar() {

	// INICIO de cosa sucia para mover el cangrejo
	//std::cout<<"pos x cangrejo"<<pos_cangrejo.x<<std::endl;

	if (vuelta_cangrejo == true) {
		pos_cangrejo.x-=0.2f;
		if( pos_cangrejo.x<=-10.0f ) {
			vuelta_cangrejo = false;
		}
	} else {
		pos_cangrejo.x+=0.2f;
		if( pos_cangrejo.x>=10.0f ) {
			vuelta_cangrejo = true;
		}
	}
	//std::cout<<"pos x cangrejo"<<pos_cangrejo.x<<std::endl;
	// FIN de cosa sucia

	for (unsigned int i = 0; i<figuras.size(); ++i) {
		figuras[i]->animar();
	}
}

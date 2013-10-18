/*
 * Escenario.cpp
 *
 *  Created on: 10/10/2013
 *      Author: jorge
 */

#include "Escenario.h"

Escenario::Escenario(myWindow* ventana):Figura(ventana),pez1(ventana),cangrejo1 (ventana),
				piedra1(ventana), piedra2(ventana), piedra3(ventana), piedra4(ventana), piedra5(ventana),
				planta1(ventana), planta2(ventana), planta3(ventana), planta4(ventana), planta5(ventana),
				piso(ventana) {
	pos_cangrejo1=glm::vec3 (0,0,1.3f);
	pos_pez1 = glm::vec3 (0,0,4.0f);

	figuras.push_back(&cangrejo1);
	figuras.push_back(&pez1);
	figuras.push_back(&piedra1);
	figuras.push_back(&piedra2);
	figuras.push_back(&piedra3);
	figuras.push_back(&piedra4);
	figuras.push_back(&piedra5);
	figuras.push_back(&planta1);
	figuras.push_back(&planta2);
	figuras.push_back(&planta3);
	figuras.push_back(&planta4);
	figuras.push_back(&planta5);
	figuras.push_back(&piso);

	std::vector<glm::vec3> puntos;
	/*puntos.push_back(glm::vec3(0, 0, 0));
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
	*/
	puntos.push_back(glm::vec3(0, 0, 0));
	puntos.push_back(glm::vec3(0, 0, 0));
	puntos.push_back(glm::vec3(0, 0, 0));
	puntos.push_back(glm::vec3(7, 0, 0));
	puntos.push_back(glm::vec3(7, 3, 0));
	puntos.push_back(glm::vec3(6, 4.5, 0));
	puntos.push_back(glm::vec3(5, 4, 0));
	puntos.push_back(glm::vec3(6, 2, 0));
	puntos.push_back(glm::vec3(7, 3, 0));
	puntos.push_back(glm::vec3(7, 5, 0));
	puntos.push_back(glm::vec3(7, 7, 0));
	puntos.push_back(glm::vec3(0, 7, 0));
	puntos.push_back(glm::vec3(-5, 7, 0));
	puntos.push_back(glm::vec3(-2, 1, 0));
	puntos.push_back(glm::vec3(0, 0, 0));
	puntos.push_back(glm::vec3(0, 0, 0));
	puntos.push_back(glm::vec3(0, 0, 0));
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
	model_matrix_pez1 = glm::translate(model_matrix, pos_pez1);
	model_matrix_pez1 = glm::rotate(model_matrix_pez1,45.0f, glm::vec3(1,1,0));

	this->pez1.renderizar(model_matrix_pez1);

	glm::mat4 model_matrix_cangrejo1 = glm::translate(model_matrix, pos_cangrejo1);
	//this->cangrejo1.renderizar(model_matrix_cangrejo1);

	bool RENDERIZAR_PLANTAS = false;
	if(RENDERIZAR_PLANTAS) {
		glm::mat4 model_matrix_planta1 = glm::translate(model_matrix,glm::vec3(-5.0f, 5.0f, 0.9f));
		this->planta1.renderizar(model_matrix_planta1);
		glm::mat4 model_matrix_planta2 = glm::translate(model_matrix,glm::vec3(-15.0f, 5.0f, 0.9f));
		this->planta2.renderizar(model_matrix_planta2);
		glm::mat4 model_matrix_planta3 = glm::translate(model_matrix,glm::vec3(-5.0f, 25.0f, 0.9f));
		this->planta3.renderizar(model_matrix_planta3);
		glm::mat4 model_matrix_planta4 = glm::translate(model_matrix,glm::vec3(-5.0f, -15.0f, 0.9f));
		this->planta4.renderizar(model_matrix_planta4);
		glm::mat4 model_matrix_planta5 = glm::translate(model_matrix,glm::vec3(13.0f, 13.0f, 0.9f));
		this->planta5.renderizar(model_matrix_planta5);
	}
	bool RENDERIZAR_PIEDRAS = false;
	if(RENDERIZAR_PIEDRAS) {
		glm::mat4 model_matrix_piedra1 = glm::translate(model_matrix,glm::vec3(5,5,0));
		this->piedra1.renderizar(model_matrix_piedra1);
		glm::mat4 model_matrix_piedra2 = glm::translate(model_matrix,glm::vec3(-5,-5,0));
		this->piedra1.renderizar(model_matrix_piedra2);
		glm::mat4 model_matrix_piedra3 = glm::translate(model_matrix,glm::vec3(1,14,0));
		this->piedra1.renderizar(model_matrix_piedra3);
		glm::mat4 model_matrix_piedra4 = glm::translate(model_matrix,glm::vec3(12,-11,0));
		this->piedra1.renderizar(model_matrix_piedra4);
		glm::mat4 model_matrix_piedra5 = glm::translate(model_matrix,glm::vec3(7,8,0));
		this->piedra1.renderizar(model_matrix_piedra5);
	}
}
void Escenario::animar() {
	for (unsigned int i = 0; i<figuras.size(); ++i) {
		figuras[i]->animar();
	}
}

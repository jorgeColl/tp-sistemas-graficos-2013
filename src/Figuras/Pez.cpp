/*
 * Pez.cpp
 *
 *  Created on: 12/10/2013
 *      Author: jorge
 */

#include "Pez.h"
AletaPez::AletaPez(myWindow* ventana) :Figura(ventana) { }
AletaPez::~AletaPez() { }
void AletaPez::renderizar(glm::mat4 model_matrix) {
	model_matrix = glm::scale(model_matrix,glm::vec3(0.5,0.5,1.5));
	this->myCube->render(model_matrix);
}

ColaPez::ColaPez(myWindow* ventana) :Figura(ventana) { }
ColaPez::~ColaPez() { }
void ColaPez::renderizar(glm::mat4 model_matrix) {

}

TorsoPez::TorsoPez(myWindow* ventana) :Figura(ventana) { }
TorsoPez::~TorsoPez() { }
void TorsoPez::renderizar(glm::mat4 model_matrix) {

}

Pez::Pez(myWindow* ventana) : Figura (ventana),aleta1(ventana),aleta2(ventana),cola(ventana),torso(ventana) { }
Pez::~Pez() {}
void Pez::renderizar(glm::mat4 model_matrix) {
	aleta1.renderizar(model_matrix);
	aleta2.renderizar(model_matrix);
	cola.renderizar(model_matrix);
	torso.renderizar(model_matrix);
}


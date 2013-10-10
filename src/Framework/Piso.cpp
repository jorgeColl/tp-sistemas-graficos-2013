/*
 * Piso.cpp
 *
 *  Created on: 10/10/2013
 *      Author: jorge
 */

#include "Piso.h"

Piso::Piso(myWindow* ventana):Figura(ventana) {
	// TODO Auto-generated constructor stub
	this->myGrid = new Grilla (ventana, 10);
}

Piso::~Piso() {
	delete this->myGrid;
}

void Piso::renderizar(glm::mat4 model_matrix){
	this->myGrid->render(model_matrix);
}


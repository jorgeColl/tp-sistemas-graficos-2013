#include "Curva.h"
#include <iostream>

Curva::Curva () {
	this->puntosControl = new std::vector<glm::vec3>();
}

Curva::Curva (std::vector<glm::vec3> ptosControl) {
	this->puntosControl = new std::vector<glm::vec3>();
	
	for (std::vector<glm::vec3>::iterator it = ptosControl.begin(); it != ptosControl.end() ; ++it) {
		glm::vec3 miPunto( (*it) );
		this->puntosControl->push_back(miPunto);
	}
}

float Curva::calcular_base (int n, int i, float u) { return 0.0; }

glm::vec3 Curva::damePunto (float u) {
	glm::vec3 puntoFinal = glm::vec3 (0,0,0);
	
	if ((u >= 0.0) && (u <= 1.0)) {
		int total = puntosControl->size();
		for ( int i = 0 ; i < total ; i++ ) {
			glm::vec3 unPunto = puntosControl->at(i);
			float unaBase = calcular_base (total-1, i, u);
			puntoFinal += (unPunto * unaBase);
		}
	}
	
	return puntoFinal;
}

void Curva::transformar (glm::mat4 matriz) {
	for (unsigned int i = 0 ; i < this->puntosControl->size() ; i++) {
		glm::vec3 punto = puntosControl->at(i);
		glm::vec4 puntoTemp (punto.x, punto.y, punto.z, 1.0);
		puntoTemp = matriz * puntoTemp;
		puntosControl->at(i) = glm::vec3 (puntoTemp.x, puntoTemp.y, puntoTemp.z);
	}
}

Curva::~Curva () {
	delete (this->puntosControl);
}

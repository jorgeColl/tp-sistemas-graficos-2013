#include "FuncionCurvaBezier.h"
#include <exception>
#include <iostream>

FuncionCurvaBezier::FuncionCurvaBezier (std::vector<glm::vec3> puntosControl) :
			mi_curva(puntosControl, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,1.0)) {
	
	if (puntosControl.size() > 0) {
		this->x_min = (puntosControl.at(0)).x;
		this->x_max = (puntosControl.at(puntosControl.size() - 1)).x;
	}
	if (puntosControl.size() > 1) {
		int cantidad = 1;
		float x_anterior = (puntosControl.at(0)).x;
		for (unsigned int i = 1 ; i < puntosControl.size() ; i++) {
			float x_actual = (puntosControl.at(i)).x;
			if (x_anterior > x_actual) throw std::exception();
			else if (x_anterior == x_actual) cantidad++;
			else cantidad = 1;
			
			if (cantidad >= 3) throw std::exception();
			x_anterior = x_actual;
		}
	}
}

float FuncionCurvaBezier::evaluar_en (float x) {
	float u = ( x - this->x_min ) / ( this->x_max - this->x_min );
	return ( (this->mi_curva.damePunto(u)).y );
}

FuncionCurvaBezier::~FuncionCurvaBezier () { }

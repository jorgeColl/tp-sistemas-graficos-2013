#include "CurvaPerturbada.h"
#include "Helper.h"
#include <iostream>

CurvaPerturbada::CurvaPerturbada (std::vector<glm::vec3> ptosControl, glm::vec3 centro, glm::vec3 orientacion, float perturbacion)
					: CurvaBSpline (CurvaPerturbada::perturbar_puntos(ptosControl, perturbacion), centro, orientacion) {
	
	this->ptosControlSinPerturbar = new std::vector<glm::vec3>(ptosControl);
	this->mi_perturbacion = perturbacion;
}

std::vector<glm::vec3> CurvaPerturbada::perturbar_puntos (std::vector<glm::vec3> ptosControl, float perturbacion) {
	std::vector<glm::vec3> puntos_perturbados = std::vector<glm::vec3>(ptosControl);
	
	for (unsigned int i = 0 ; i < puntos_perturbados.size() ; i++) {
		float num = Helper::num_aleatorio(-perturbacion, perturbacion);
		puntos_perturbados.at(i).x += num;
	}
	return puntos_perturbados;
}

void CurvaPerturbada::reset () {
	Curva::reset();
	std::vector<glm::vec3> nuevosPuntos = CurvaPerturbada::perturbar_puntos (*(this->ptosControlSinPerturbar), this->mi_perturbacion);
	this->destruir_tramos();
	this->init (nuevosPuntos, this->dameCentro(), this->dameOrientacion());
}

CurvaPerturbada::~CurvaPerturbada() {
	delete (this->ptosControlSinPerturbar);
}

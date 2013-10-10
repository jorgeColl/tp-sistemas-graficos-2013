#include "Helper.h"
#include "CurvaBSplineCubica.h"
#include "CurvaBSpline.h"
#include <exception>

const unsigned int CurvaBSpline::ORDEN = 3;

CurvaBSpline::CurvaBSpline (std::vector<glm::vec3> ptosControl, glm::vec3 centro, glm::vec3 orientacion): Curva(centro, orientacion) {
	this->tramos = new std::vector<CurvaBSplineCubica*>();
	
	if (ptosControl.size() > CurvaBSpline::ORDEN) {
		int vueltas = (ptosControl.size() - CurvaBSpline::ORDEN);
		for (int i = 0 ; i < vueltas ; i++) {
			std::vector<glm::vec3> ptosTemp;
			for (unsigned int j = 0 ; j <= CurvaBSpline::ORDEN ; j++) {
				ptosTemp.push_back ( ptosControl.at(i+j) );
			}
			this->tramos->push_back ( new CurvaBSplineCubica(ptosTemp, centro, orientacion) );
		}
	}
}

int CurvaBSpline::cantidad_tramos () {
	return (this->tramos->size());
}

glm::vec3 CurvaBSpline::damePunto (float u) {
	if ((u < 0.0) || (u > (this->cantidad_tramos()*1.0))) throw std::exception();
	
	int num_tramo = int(u);
	if (num_tramo == this->cantidad_tramos()) num_tramo--;
	Curva* tramo = this->tramos->at(num_tramo);
	return (tramo->damePunto (u - num_tramo));
}

void CurvaBSpline::transformar (glm::mat4 matriz) {
	for (int i = 0 ; i < this->cantidad_tramos() ; i++) {
		this->tramos->at(i)->transformar (matriz);
	}
}

void CurvaBSpline::reset () {
	Curva::reset();
	for (int i = 0 ; i < this->cantidad_tramos() ; i++) {
		this->tramos->at(i)->reset();
	}
}

CurvaBSpline::~CurvaBSpline () {
	Helper::destruir_elementos <std::vector<CurvaBSplineCubica*>, CurvaBSplineCubica> (this->tramos);
	delete (this->tramos);
}

#include "Helper.h"
#include "CurvaBSplineCubica.h"
#include "CurvaBSpline.h"
#include <exception>

const unsigned int CurvaBSpline::ORDEN = 3;

void CurvaBSpline::init (std::vector<glm::vec3> ptosControl, glm::vec3 centro, glm::vec3 orientacion) {
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

CurvaBSpline::CurvaBSpline (std::vector<glm::vec3> ptosControl, glm::vec3 centro, glm::vec3 orientacion): Curva(centro, orientacion) {
	this->init (ptosControl, centro, orientacion);
}

int CurvaBSpline::cantidad_tramos () {
	return (this->tramos->size());
}

glm::vec3 CurvaBSpline::dameVectorDeTramo (float u, TipoVector tipo) {
	if ((u < 0.0) || (u > (this->cantidad_tramos()*1.0))) throw std::exception();
	
	int num_tramo = int(u);
	if (num_tramo == this->cantidad_tramos()) num_tramo--;
	CurvaBSplineCubica* tramo = this->tramos->at(num_tramo);
	if (tipo == Punto)	  return (tramo->damePunto	  (u - num_tramo));
	if (tipo == Tangente) return (tramo->dameTangente (u - num_tramo));
	if (tipo == Normal)	  return (tramo->dameNormal	  (u - num_tramo));
	if (tipo == Binormal) return (tramo->dameBinormal (u - num_tramo));
	return (glm::vec3 (0.0,0.0,0.0));
}

glm::vec3 CurvaBSpline::damePunto (float u) {
	return (this->dameVectorDeTramo (u, Punto));
}

glm::vec3 CurvaBSpline::dameTangente (float u) {
	return (this->dameVectorDeTramo (u, Tangente));
}

glm::vec3 CurvaBSpline::dameNormal (float u) {
	glm::vec3 normal = this->dameVectorDeTramo (u, Normal);
	
	bool fin = false;
	float param = float(int(u));
	int vueltas = 1;
	float sentido = 1.0;
	while ((Helper::is_zero(normal)) && (!fin)) {
		try {
			normal = this->dameVectorDeTramo (param + sentido * vueltas, Normal);
			++vueltas;
		} catch (std::exception error) {
			if (sentido == 1.0) {
				param -= 0.001;
				vueltas = 1.0;
				sentido = -1.0;
			} else fin = true;
		}
	}
	return normal;
}

glm::vec3 CurvaBSpline::dameBinormal (float u) {
	return (this->dameVectorDeTramo (u, Binormal));
}

void CurvaBSpline::transformar (glm::mat4 matriz) {
	for (int i = 0 ; i < this->cantidad_tramos() ; i++) {
		this->tramos->at(i)->transformar (matriz);
	}
}

void CurvaBSpline::centrar (glm::vec3 vector) {
	for (int i = 0 ; i < this->cantidad_tramos() ; i++) {
		this->tramos->at(i)->centrar (vector);
	}
}

void CurvaBSpline::alinear (glm::vec3 vector) {
	for (int i = 0 ; i < this->cantidad_tramos() ; i++) {
		this->tramos->at(i)->alinear (vector);
	}
}

void CurvaBSpline::reset () {
	Curva::reset();
	for (int i = 0 ; i < this->cantidad_tramos() ; i++) {
		this->tramos->at(i)->reset();
	}
}

void CurvaBSpline::destruir_tramos () {
	Helper::destruir_elementos <std::vector<CurvaBSplineCubica*>, CurvaBSplineCubica> (this->tramos);
	delete (this->tramos);
}

CurvaBSpline::~CurvaBSpline () {
	this->destruir_tramos();
}

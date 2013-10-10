#include "Curva.h"
#include <iostream>
#include <exception>
#include <glm/gtc/matrix_transform.hpp>

void Curva::init (glm::vec3 centro, glm::vec3 orientacion) {
	this->puntosControl = new std::vector<glm::vec3>();
	this->miCentro = glm::vec3 (centro);
	this->miOrientacion = glm::vec3 (orientacion);
	
	this->puntosControlOriginal = new std::vector<glm::vec3>();
	this->miCentroOriginal = glm::vec3 (centro);
	this->miOrientacionOriginal = glm::vec3 (orientacion);
}

Curva::Curva (glm::vec3 centro, glm::vec3 orientacion) {
	this->init (centro, orientacion);
}

Curva::Curva (std::vector<glm::vec3> ptosControl, glm::vec3 centro, glm::vec3 orientacion) {
	this->init (centro, orientacion);
	
	for (std::vector<glm::vec3>::iterator it = ptosControl.begin(); it != ptosControl.end() ; ++it) {
		glm::vec3 miPunto( (*it) );
		this->puntosControl->push_back(miPunto);
		this->puntosControlOriginal->push_back(miPunto);
	}
}

float Curva::calcular_base (int n, int i, float u) { return 0.0; }

glm::vec3 Curva::damePunto (float u) {
	if ((u < 0.0) || (u > 1.0)) throw std::exception();
	
	glm::vec3 puntoFinal = glm::vec3 (0,0,0);
	int total = puntosControl->size();
	for ( int i = 0 ; i < total ; i++ ) {
		glm::vec3 unPunto = puntosControl->at(i);
		float unaBase = calcular_base (total-1, i, u);
		puntoFinal += (unPunto * unaBase);
	}
	return puntoFinal;
}

glm::vec3 Curva::dameTangente (float u, float paso) {
	glm::vec3 puntoInicial = this->damePunto (u);
	glm::vec3 puntoFinal = glm::vec3 (0.0, 0.0, 0.0);
	int coeficiente = 1;
	try {
		puntoFinal = this->damePunto (u + paso);
	} catch (std::exception error) {
		puntoFinal = this->damePunto (u - paso);
		coeficiente = -1;
	}
	glm::vec3 resultado = (puntoFinal - puntoInicial);
	resultado *= coeficiente;
	return resultado;
}

glm::vec3 Curva::dameCentro () {
	return (this->miCentro);
}

glm::vec3 Curva::dameOrientacion () {
	return (this->miOrientacion);
}


glm::vec3 Curva::transformar_punto (glm::vec3 punto, glm::mat4 matriz) {
	glm::vec4 puntoTemp (punto.x, punto.y, punto.z, 1.0);
	puntoTemp = matriz * puntoTemp;
	return ( glm::vec3 (puntoTemp.x, puntoTemp.y, puntoTemp.z) );
}

void Curva::transformar (glm::mat4 matriz) {
	for (unsigned int i = 0 ; i < this->puntosControl->size() ; i++) {
		puntosControl->at(i) = this->transformar_punto (puntosControl->at(i), matriz);
	}
}

void Curva::centrar (glm::vec3 vector) {
	glm::mat4 matriz = glm::mat4 (1.0f);
	matriz = glm::translate (matriz , (vector - this->miCentro) );
	this->transformar (matriz);
	this->miCentro = this->transformar_punto (this->miCentro, matriz);
}

void Curva::alinear (glm::vec3 vector) {
	glm::vec3 v1 = glm::normalize (this->miOrientacion);
	glm::vec3 v2 = glm::normalize (vector);
	float coseno = glm::dot (v1, v2);
	float angulo = acos (coseno);
	
	// roto alrededor del origen
	glm::vec3 centroActual = this->miCentro;
	this->centrar (glm::vec3 (0.0, 0.0, 0.0));
	
	glm::vec3 normal = glm::cross (v1, v2);
	glm::mat4 matriz = glm::mat4 (1.0f);
	matriz = glm::rotate (matriz, angulo, normal);
	this->transformar (matriz);
	
	this->centrar (centroActual);
}

void Curva::reset () {
	delete (this->puntosControl);
	this->puntosControl = new std::vector<glm::vec3> (*(this->puntosControlOriginal));
	
	this->miCentro = glm::vec3 (this->miCentroOriginal);
	this->miOrientacion = glm::vec3 (this->miOrientacionOriginal);
}

Curva::~Curva () {
	delete (this->puntosControl);
	delete (this->puntosControlOriginal);
}

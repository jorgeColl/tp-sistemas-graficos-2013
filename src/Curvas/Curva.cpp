#include "Curva.h"
#include <iostream>
#include <exception>
#include <glm/gtc/matrix_transform.hpp>
#include <list>

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

float Curva::calcular_base_en_orden (int n, int i, float u, OrdenBase orden) {
	if (orden == Cero) return calcular_base (n, i, u);
	if (orden == PrimeraDerivada) return calcular_base_primera_derivada (n, i, u);
	if (orden == SegundaDerivada) return calcular_base_segunda_derivada (n, i, u);
	return 0.0;
}

glm::vec3 Curva::dameVector (float u, OrdenBase orden) {
	if ((u < 0.0) || (u > 1.0)) throw std::exception();
	
	glm::vec3 puntoFinal = glm::vec3 (0,0,0);
	int total = puntosControl->size();
	for ( int i = 0 ; i < total ; i++ ) {
		glm::vec3 unPunto = puntosControl->at(i);
		float unaBase = calcular_base_en_orden (total-1, i, u, orden);
		this->redondear_valor (unaBase);
		puntoFinal += (unPunto * unaBase);
	}
	
	this->redondear_valor (puntoFinal.x);
	this->redondear_valor (puntoFinal.y);
	this->redondear_valor (puntoFinal.z);
	
	return puntoFinal;
}

glm::vec3 Curva::dameVectorNoDefinido (float u, OrdenBase orden, glm::vec3 vector) {
	glm::vec3 vectorDefinido = vector;
	
	int coef = 1.0;
	if (u == 1.0) coef = -1.0;
	float paso = 0.001;
	float parametro = u + (coef * paso);
	while (Helper::is_nan (vectorDefinido) && (parametro >= 0.0 && parametro <= 1.0)) {
		vectorDefinido = dameVector (parametro, orden);
		parametro += (coef * paso);
	}
	return vectorDefinido;
}

glm::vec3 Curva::damePunto (float u) {
	return dameVector (u, Cero);
}

glm::vec3 Curva::dameTangenteNoDefinida (float u, float paso) {
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

glm::vec3 Curva::dameTangente (float u) {
	glm::vec3 tangente = dameVector (u, PrimeraDerivada);
	if (Helper::is_nan (tangente)) tangente = dameVectorNoDefinido (u, PrimeraDerivada, tangente);
	if ((tangente.x == 0.0) && (tangente.y == 0.0) && (tangente.z == 0.0)) return tangente;
	return (glm::normalize (tangente));
}

glm::vec3 Curva::dameBinormal (float u) {
	glm::vec3 pDerivada = dameTangente (u);
	if ((pDerivada.x == 0.0) && (pDerivada.y == 0.0) && (pDerivada.z == 0.0)) return (this->dameOrientacion());
	
	glm::vec3 sDerivada = dameVector (u, SegundaDerivada);
	if (Helper::is_nan (sDerivada)) sDerivada = dameVectorNoDefinido (u, SegundaDerivada, sDerivada);
	if ((sDerivada.x == 0.0) && (sDerivada.y == 0.0) && (sDerivada.z == 0.0)) return (this->dameOrientacion());
	
	glm::vec3 binormal = glm::cross (pDerivada, sDerivada);
	if (Helper::is_nan (binormal)) return (this->dameOrientacion());
	
	this->redondear_valor (binormal.x);
	this->redondear_valor (binormal.y);
	this->redondear_valor (binormal.z);
	
	if ((binormal.x == 0.0) && (binormal.y == 0.0) && (binormal.z == 0.0)) return (this->dameOrientacion());
	return (glm::normalize (binormal));
}

glm::vec3 Curva::dameNormal (float u) {
	glm::vec3 tangente = dameTangente (u);
	glm::vec3 binormal = dameBinormal (u);
	glm::vec3 normal = glm::cross (tangente, binormal);
	
	if (Helper::is_nan (normal)) normal = glm::vec3 (0.0, 0.0, 0.0);
	
	this->redondear_valor (normal.x);
	this->redondear_valor (normal.y);
	this->redondear_valor (normal.z);
	
	if ((normal.x == 0.0) && (normal.y == 0.0) && (normal.z == 0.0)) return normal;
	return (glm::normalize (normal));
}

glm::vec3 Curva::dameCentro () {
	return (this->miCentro);
}

glm::vec3 Curva::dameOrientacion () {
	return (this->miOrientacion);
}

void Curva::redondear_valor (float& valor) {
	float min_value = 0.00001; // redondeo para reducir errores numericos
	if ((valor < min_value) && (valor > 0.0)) valor = 0.0;
	if ((((-1.0) * valor) < min_value) && (valor < 0.0)) valor = 0.0;
	if (valor == -0.0) valor = 0.0;
}

glm::vec3 Curva::transformar_punto (glm::vec3 punto, glm::mat4 matriz) {
	glm::vec4 puntoTemp (punto.x, punto.y, punto.z, 1.0);
	puntoTemp = matriz * puntoTemp;
	this->redondear_valor (puntoTemp.x);
	this->redondear_valor (puntoTemp.y);
	this->redondear_valor (puntoTemp.z);
	
	return ( glm::vec3 (puntoTemp.x, puntoTemp.y, puntoTemp.z) );
}

void Curva::transformar (glm::mat4 matriz) {
	for (unsigned int i = 0 ; i < this->puntosControl->size() ; i++) {
		puntosControl->at(i) = this->transformar_punto (puntosControl->at(i), matriz);
	}
}

void Curva::centrar (glm::vec3 vector) {
	glm::vec3 traslacion = (vector - this->miCentro);
	if ((traslacion.x != 0.0) || (traslacion.y != 0.0) || (traslacion.z != 0.0)) {
		glm::mat4 matriz = glm::mat4 (1.0f);
		matriz = glm::translate (matriz , traslacion);
		this->transformar (matriz);
		this->miCentro = this->transformar_punto (this->miCentro, matriz);
	}
}

void Curva::alinear (glm::vec3 vector) {
	glm::vec3 v1 = glm::normalize (this->miOrientacion);
	glm::vec3 v2 = glm::normalize (vector);
	float coseno = glm::dot (v1, v2);
	float PI = 3.1415927f;
	float angulo = (acos (coseno) * 180.0 / PI);
	
	if (angulo != 0.0) {
		// centro en el origen => roto => vuelvo a centrar en donde estaba
		glm::vec3 centroActual = this->miCentro;
		this->centrar (glm::vec3 (0.0, 0.0, 0.0));
		
		glm::mat4 matriz = glm::mat4(1.0);
		if (angulo != 180.0) {
			glm::vec3 normal = glm::cross (v1, v2);
			matriz = glm::rotate (matriz, angulo, normal);
		} else {
			if ((v1.x == 0.0) && (v1.y == 0.0) && (v1.z == 1.0))
				matriz = glm::scale (matriz, glm::vec3 (1.0,1.0,-1.0));
		}
		this->transformar (matriz);
		this->centrar (centroActual);
	}
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

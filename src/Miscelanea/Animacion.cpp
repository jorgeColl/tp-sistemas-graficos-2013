#include "Animacion.h"
#include <iostream>
#include <vector>
#include <exception>
#include "Helper.h"

Animacion::Animacion (VariableAnimacion varRecibida) {
	this->tiempo = 0.0;
	this->velocidad = 1.0;
	this->var = varRecibida;
}

void Animacion::agregar_animacion (TipoAnimacion tipo, Funcion* intensidad,
								   Funcion* coeficiente, glm::vec3 vector) {
									   
	this->tipos.push_back (tipo);
	this->intensidades.push_back (intensidad);
	this->coeficientes.push_back (coeficiente);
	this->vectores.push_back (vector);	
}

float Animacion::get_variable (glm::vec4 punto) {
	if (this->var == Xvar) return punto.x;
	if (this->var == Yvar) return punto.y;
	if (this->var == Zvar) return punto.z;
	return 1.0;
}

float Animacion::get_coeficiente (glm::vec4 punto, unsigned int i) {
	float variable = this->get_variable (punto);
	float coef = 1.0;
	try {
		coef = this->coeficientes.at(i)->evaluar_en (variable + this->tiempo);
	} catch (std::exception error) { }
	return coef;
}

float Animacion::get_intensidad (glm::vec4 punto, unsigned int i) {
	float variable = this->get_variable (punto);
	float intensidad = 0.0;
	try {
		intensidad = this->intensidades.at(i)->evaluar_en (variable);
	} catch (std::exception error) {
		intensidad = this->intensidades.at(i)->evaluar_en (this->intensidades.at(i)->get_x_max());
	}
	return intensidad;
}

glm::vec4 Animacion::animar_punto (glm::vec4 punto) {
	for (unsigned int i = 0 ; i < this->tipos.size() ; i++) {
		glm::mat4 matriz = glm::mat4 (1.0);
		if (this->tipos.at(i) == Traslacion) {
			matriz = glm::translate (matriz, this->vectores.at(i) * this->get_coeficiente (punto, i) * this->get_intensidad(punto, i));
		} else if (this->tipos.at(i) == Rotacion) {
			matriz = glm::rotate (matriz, this->get_coeficiente (punto, i) * this->get_intensidad(punto, i), this->vectores.at(i));
		} else {
			matriz = glm::scale (matriz, this->vectores.at(i) * this->get_coeficiente (punto, i) * this->get_intensidad(punto, i));
		}
		punto = matriz * punto;
	}
	
	return (glm::vec4 (punto));
}

void Animacion::dar_paso (GLfloat* buffer, int largo, int cantidad_puntos_seccion) {
	if ((this->var == SINvar) || (this->tipos.empty())) return;
	std::vector<glm::vec4> puntos;
	for (int m = 0 ; m < largo ; m += 3) {
		puntos.push_back ( glm::vec4 (buffer[m], buffer[m+1], buffer[m+2], 1.0) );
	}
	
	int cant_puntos = puntos.size();
	for (int i = 0 ; i < cant_puntos ; i += cantidad_puntos_seccion) {
		for (int j = 0 ; j < cantidad_puntos_seccion ; j++) {
			glm::vec4 punto = this->animar_punto ( puntos.at(i+j) );
			puntos.at(i+j) = punto;
		}
	}
	
	int pos = 0;
	for (unsigned int h = 0 ; h < puntos.size() ; h++) {
		buffer[pos] = puntos.at(h).x;
		buffer[pos+1] = puntos.at(h).y;
		buffer[pos+2] = puntos.at(h).z;
		pos += 3;
	}
	
	this->tiempo += this->velocidad;
}

Animacion::~Animacion () {
	Helper::destruir_elementos <std::vector<Funcion*>, Funcion> (&(this->intensidades));
	Helper::destruir_elementos <std::vector<Funcion*>, Funcion> (&(this->coeficientes));
}

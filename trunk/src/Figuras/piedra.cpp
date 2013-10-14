/*
 * Piedra.cpp
 *
 *  Created on: 08/10/2013
 *      Author: jorge
 */

#include "piedra.h"
#include <vector>
#include "Helper.h"

Piedra::Piedra(myWindow* ventana) : Figura (ventana) {
	this->mi_superficie = this->crear_superficie (ventana);
}
Piedra::~Piedra() { }

void Piedra::renderizar(glm::mat4 model_matrix) {
	model_matrix = glm::scale(model_matrix,glm::vec3(0.3,0.3,0.3));
	Figura::renderizar(model_matrix);
}

Curva* Piedra::crear_curva_trayectoria () {
	std::vector<glm::vec3> control_trayectoria;
	control_trayectoria.push_back ( glm::vec3 ( -1.5, 0.0, 0.0) );
	control_trayectoria.push_back ( glm::vec3 ( 0.0, 0.0, 1.0) );
	control_trayectoria.push_back ( glm::vec3 ( 1.5, 0.0, 0.5) );
	return (new CurvaBezier (control_trayectoria, glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 0.0, 1.0)));
}

// MODELAR MEJOR !!
Curva* Piedra::crear_curva_seccion () {
	return (new Circunferencia (glm::vec3(0.0, 0.0, 0.0), 1.5));
}

int Piedra::obtener_pasos_trayectoria () {
	return 35;
}

int Piedra::obtener_pasos_seccion () {
	return 1000;
}

// MODELAR MEJOR !!
std::vector<glm::mat4> Piedra::crear_transformaciones () {
	std::vector<glm::mat4> transformaciones;
	int pasosTrayectoria = this->obtener_pasos_trayectoria();
	for (int i = 0 ; i <= pasosTrayectoria ; i++) {
		glm::mat4 matriz = glm::mat4 (1.0f);
		float a2 = (-4.0) / Helper::potencia(pasosTrayectoria,2);
		Parabola funcion = Parabola (0.0, pasosTrayectoria * 1.0, a2, true);
		float num = (float)rand()/((float)RAND_MAX/360.0);
		float coef = 0.0;
		if ((i > 0) && (i < pasosTrayectoria)) coef = (funcion.evaluar_en (i * 1.0) + (0.02) * sin(num * 3.1415927f / 180.0));
		if (coef < 0.0) coef *= (-1);
		matriz = glm::scale ( glm::mat4 (1.0f) , glm::vec3 (coef, coef, coef));
		transformaciones.push_back(matriz);
	}
	return transformaciones;
}

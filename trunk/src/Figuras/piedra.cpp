/*
 * Piedra.cpp
 *
 *  Created on: 08/10/2013
 *      Author: jorge
 */

#include "piedra.h"
#include <vector>

Piedra::Piedra(myWindow* ventana) : Figura (ventana) {
//	this->mi_superficie = new Esfera (ventana, 1.0, 32, 32);
	
	std::vector<glm::vec3> control_trayectoria;
	control_trayectoria.push_back ( glm::vec3 ( -2.0, 0.0, 0.0) );
	control_trayectoria.push_back ( glm::vec3 ( 2.0, 0.0, 0.0) );
	CurvaBezier* trayectoria = new CurvaBezier (control_trayectoria, glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 0.0, 1.0));
	
	Circunferencia* seccion = new Circunferencia (glm::vec3(0.0, 0.0, 0.0), 2.0);
	
	std::vector<glm::mat4> transformaciones;
	for (unsigned int i = 0 ; i < 10 ; i++) {
		glm::mat4 matriz = glm::mat4 (1.0f);
		Parabola funcion = Parabola (0.0, 10.0, 0.1, true);
		float coef = funcion.evaluar_en (i * 1.0);
		matriz = glm::scale(matriz, glm::vec3 (coef * 1.0f, coef * 1.0f, coef * 1.0f));
		transformaciones.push_back(matriz);
	}
	this->mi_superficie = new SuperficieBarrido (trayectoria, seccion, 10, 10, transformaciones, ventana);

	
}

Piedra::~Piedra() {
	delete this->mi_superficie;
}


void Piedra::renderizar(glm::mat4 model_matrix) {
	model_matrix = glm::scale(model_matrix,glm::vec3(0.3,0.3,0.3));
	this->mi_superficie->render(model_matrix);
}

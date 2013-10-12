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
//	this->mi_superficie = new Esfera (ventana, 1.0, 32, 32);
	
	std::vector<glm::vec3> control_trayectoria;
	control_trayectoria.push_back ( glm::vec3 ( -1.5, 0.0, 0.0) );
	control_trayectoria.push_back ( glm::vec3 ( 0.0, 0.0, 1.0) );
	control_trayectoria.push_back ( glm::vec3 ( 1.5, 0.0, 0.5) );
	CurvaBezier* trayectoria = new CurvaBezier (control_trayectoria, glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 0.0, 1.0));
	
	Circunferencia* seccion = new Circunferencia (glm::vec3(0.0, 0.0, 0.0), 1.5);
	
	// cuando tenga tiempo refactorizo todo esto de manera linda y generica para todas las figuras
	// y modelo mejor a la piedra
	
	std::vector<glm::mat4> transformaciones;
	unsigned int pasosTrayectoria = 35;
	for (unsigned int i = 0 ; i <= pasosTrayectoria ; i++) {
		glm::mat4 matriz = glm::mat4 (1.0f);
		float a2 = (-4.0) / Helper::potencia(pasosTrayectoria,2);
		Parabola funcion = Parabola (0.0, pasosTrayectoria * 1.0, a2, true);
	//	Funcion funcion = Funcion();
		float num = (float)rand()/((float)RAND_MAX/360.0);
		float coef = 0.0;
		if ((i > 0) && (i < pasosTrayectoria)) coef = (funcion.evaluar_en (i * 1.0) + (0.05) * sin(num * 3.1415927f / 180.0));
		if (coef < 0.0) coef = coef * (-1);
		matriz = glm::scale ( glm::mat4 (1.0f) , glm::vec3 (coef, coef, coef));
		transformaciones.push_back(matriz);
	}
	this->mi_superficie = new SuperficieBarrido (trayectoria, seccion, pasosTrayectoria, 1000, transformaciones, ventana);
	
}

Piedra::~Piedra() {
	delete this->mi_superficie;
}


void Piedra::renderizar(glm::mat4 model_matrix) {
	model_matrix = glm::scale(model_matrix,glm::vec3(0.3,0.3,0.3));
	this->mi_superficie->render(model_matrix);
}

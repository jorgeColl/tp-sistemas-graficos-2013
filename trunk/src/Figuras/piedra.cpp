/*
 * Piedra.cpp
 *
 *  Created on: 08/10/2013
 *      Author: jorge
 */

#include "piedra.h"
#include "Esfera.h"
#include "SuperficieBarrido.h"
#include "CurvaBezier.h"
#include "CurvaBSpline.h"
#include "Circunferencia.h"
#include "Parabola.h"
#include "Funcion.h"
#include <vector>

Piedra::Piedra(myWindow* ventana) : Figura (ventana) {
	this->mi_superficie = new Esfera (ventana, 1.0, 32, 32);
	
/*	std::vector<glm::vec3> control_trayectoria;
	control_trayectoria.push_back ( glm::vec3 ( -1.0, 0.0, 0.0) );
	control_trayectoria.push_back ( glm::vec3 ( 1.0, 0.0, 0.0) );
	CurvaBezier* trayectoria = new CurvaBezier (control_trayectoria, glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 0.0, 1.0));
	
	Circunferencia* seccion = new Circunferencia (glm::vec3(0.0, 0.0, 0.0), 1.0);
	
	glm::mat4 transformacion = glm::mat4 ( 1.0f );
	transformacion = glm::scale(transformacion, glm::vec3 (1.0f, 1.5f, 1.0f) );
	this->mi_superficie = new SuperficieBarrido (trayectoria, seccion, 15, 20, transformacion, Parabola (0.0, 1.0, 1.0, true), ventana);
*/
	
}

Piedra::~Piedra() {
	delete this->mi_superficie;
}


void Piedra::renderizar(glm::mat4 model_matrix) {
	// temporalmente aca
	model_matrix = glm::translate(model_matrix,glm::vec3(5,5,0.4));

	model_matrix = glm::scale(model_matrix,glm::vec3(0.3,0.3,0.3));
	this->mi_superficie->render(model_matrix);
}

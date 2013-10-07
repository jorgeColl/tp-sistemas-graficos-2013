#include "SuperficieBarrido.h"

SuperficieBarrido::SuperficieBarrido (std::vector<glm::vec3> controlTrayectoria, std::vector<glm::vec3> controlSeccion,
									  unsigned int pasosTray, unsigned int pasosSec, glm::mat4 transformacionRecibida,
									  Funcion funcionRecibida) : Superficie () {
	
	this->trayectoria = new CurvaBezier (controlTrayectoria);
	this->seccion = new CurvaBSpline (controlSeccion);
	this->set_pasos_trayectoria (pasosTray);
	this->set_pasos_seccion (pasosSec);
	this->set_transformacion (transformacionRecibida);
	this->set_funcion (funcionRecibida);
	
	this->crear_puntos();
}

void SuperficieBarrido::set_pasos_trayectoria (unsigned int pasos) {
	this->pasos_trayectoria = pasos;
}

void SuperficieBarrido::set_pasos_seccion (unsigned int pasos) {
	this->pasos_seccion = pasos;
}

void SuperficieBarrido::set_transformacion (glm::mat4 transformacionRecibida) {
	this->transformacion = transformacionRecibida;
}

void SuperficieBarrido::set_funcion (Funcion funcionRecibida) {
	this->funcion = funcionRecibida;
}

void SuperficieBarrido::crear_puntos () {
	
}

SuperficieBarrido::~SuperficieBarrido () {
	delete (this->trayectoria);
	delete (this->seccion);
}

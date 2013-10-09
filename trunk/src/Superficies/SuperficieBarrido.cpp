#include "SuperficieBarrido.h"

SuperficieBarrido::SuperficieBarrido (Curva* trayectoriaRecibida, Curva* seccionRecibida, unsigned int pasosTray,
									  unsigned int pasosSec, glm::mat4 transformacionRecibida, Funcion funcionRecibida,
									  myWindow* passed_window) : Superficie (passed_window) {
	
	this->trayectoria = trayectoriaRecibida;
	this->seccion = seccionRecibida;
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
	// std::vector<glm::vec3> unaSeccion;
	for (unsigned int i = 0; i <= this->pasos_trayectoria ; i++) {
		float u = ((i*1.0) / (this->pasos_trayectoria*1.0)) * this->trayectoria->cantidad_tramos();
		float u2 = (((i+1)*1.0) / (this->pasos_trayectoria*1.0)) * this->trayectoria->cantidad_tramos();
		
		glm::vec3 puntoTrayectoria = this->trayectoria->damePunto (u);
		glm::mat4 matrizAux = this->funcion.evaluar_en(u) * this->transformacion;
		this->seccion->transformar(matrizAux);
		this->seccion->centrar (puntoTrayectoria);
		this->seccion->alinear (this->trayectoria->dameTangente(u, u2 - u));
		
		for (unsigned int j = 0; j <= this->pasos_seccion ; j++) {
			// dame punto seccion
			// coser malla
			// calcular normal (como?)
		}
	}		
}

SuperficieBarrido::~SuperficieBarrido () { }

#include "Techo.h"

Techo::Techo(myWindow* ventana):Piso(ventana) {
	this->mi_superficie->nombreTextura="techo.jpg";
	this->mi_superficie->nombreTexturaNormal="";
	//this->mi_superficie->nombreTexturaNormal="techoNormal.jpg";
	
	this->mi_superficie->ka = glm::vec3(0.8, 0.8, 0.8);
	this->mi_superficie->kd = glm::vec3(1.0, 1.0, 1.0);
}

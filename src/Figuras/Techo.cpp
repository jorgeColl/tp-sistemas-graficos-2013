#include "Techo.h"

Techo::Techo(myWindow* ventana):Piso(ventana) {
	this->mi_superficie->nombreTextura="techo.jpg";
	//this->mi_superficie->nombreTexturaNormal="techoNormal.jpg";
}

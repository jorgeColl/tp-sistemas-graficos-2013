#include "FuncionSeno.h"
#include <cmath>

FuncionSeno::FuncionSeno (float amplitudRecibida, float frecuenciaRecibida, float faseRecibida) {
	this->amplitud = amplitudRecibida;
	this->frecuencia = frecuenciaRecibida;
	this->fase = faseRecibida;
}

float FuncionSeno::evaluar_en (float x) {
	return ( this->amplitud * std::sin (this->frecuencia * x + this->fase) );
}

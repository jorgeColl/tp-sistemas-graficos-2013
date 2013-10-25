#pragma once
#include "Funcion.h"

class  FuncionSeno : public Funcion {
	private:
		float amplitud, frecuencia, fase;
	
	public:
		FuncionSeno (float amplitudRecibida, float frecuenciaRecibida, float faseRecibida);
		
		virtual float evaluar_en (float x);
		
		virtual ~FuncionSeno () { };
};

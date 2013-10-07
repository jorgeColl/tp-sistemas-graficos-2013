#pragma once

#include <iostream>
#include "Funcion.h"

class Parabola : public Funcion {
	
	private:
		float a0, a1, a2;
		bool raices;
		
	public:
		// Si 'raices' es true, a0 y a1 seran las raices del polinomio.
		// a2 es el coeficiente de x^2 en todos los casos.
		Parabola (float passed_a0, float passed_a1, float passed_a2, bool passed_raices);
		
		virtual float evaluar_en (float x);
		
};

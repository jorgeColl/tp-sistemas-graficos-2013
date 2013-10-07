#include "Parabola.h"
#include "Helper.h"

// Si 'raices' es true, a0 y a1 seran las raices del polinomio.
// a2 es el coeficiente de x^2 en todos los casos.
Parabola::Parabola (float passed_a0, float passed_a1, float passed_a2, bool passed_raices): Funcion() {
	this->a0 = passed_a0;
	this->a1 = passed_a1;
	this->a2 = passed_a2;
	this->raices = passed_raices;
}

float Parabola::evaluar_en (float x) {
	if (raices)
		return (a2 * (x - a0) * (x - a1));
	else
		return (a2 * Helper::potencia(x,2) + a1 * x + a0);
}

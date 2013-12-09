#include "Helper.h"
#include "CurvaBSplineCubica.h"

float CurvaBSplineCubica::calcular_base (int n, int i, float u) {
	// Hardcode mode on
	float termino1, termino2;
	float unSexto = (1.0/6.0);
	
	if (i == 0) {
		return (unSexto * Helper::potencia(1 - u, 3));
	}
	else if (i == 1) {
		termino1 = 3.0 * Helper::potencia(u, 3);
		termino2 = (-6.0) * Helper::potencia(u, 2);
		return (unSexto * (termino1 + termino2 + 4));
	}
	else if (i == 2) {
		termino1 = (-3.0) * Helper::potencia(u, 3);
		termino2 = (3.0) * Helper::potencia(u, 2);
		return (unSexto * (termino1 + termino2 + 3*u + 1));
	}
	else if (i == 3) {
		return (unSexto * Helper::potencia(u, 3));
	}
	else return 0.0;
}

float CurvaBSplineCubica::calcular_base_primera_derivada (int n, int i, float u) {
	// Hardcode mode on
	float termino1, termino2;
	float unMedio = (1.0/2.0);
	
	if (i == 0) {
		return ( (-1) * unMedio * Helper::potencia(1 - u, 2));
	}
	else if (i == 1) {
		termino1 = 3.0 * Helper::potencia(u, 2);
		termino2 = (-4.0) * u;
		return (unMedio * (termino1 + termino2));
	}
	else if (i == 2) {
		termino1 = (-3.0) * Helper::potencia(u, 2);
		termino2 = (2.0) * u;
		return (unMedio * (termino1 + termino2 + 1));
	}
	else if (i == 3) {
		return (unMedio * Helper::potencia(u, 2));
	}
	else return 0.0;
}

float CurvaBSplineCubica::calcular_base_segunda_derivada (int n, int i, float u) {
	// Hardcode mode on
	if 		(i == 0) return (1 - u);
	else if (i == 1) return (3*u - 2);
	else if (i == 2) return (1 - 3*u);
	else if (i == 3) return (u);
	else return 0.0;
}

CurvaBSplineCubica::CurvaBSplineCubica (std::vector<glm::vec3> ptosControl, glm::vec3 centro, glm::vec3 orientacion): Curva (ptosControl, centro, orientacion) { }

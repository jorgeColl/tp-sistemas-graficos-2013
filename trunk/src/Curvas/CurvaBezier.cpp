#include "Helper.h"
#include "CurvaBezier.h"

float CurvaBezier::calcular_base (int n, int i, float u) {
	return ( Helper::coef_binomial(n,i) * Helper::potencia(u,i) * Helper::potencia(1-u,n-i) );
}

CurvaBezier::CurvaBezier (std::vector<glm::vec3> ptosControl): Curva (ptosControl) { }

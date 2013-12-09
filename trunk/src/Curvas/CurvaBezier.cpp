#include "Helper.h"
#include "CurvaBezier.h"

float CurvaBezier::calcular_base (int n, int i, float u) {
	return ( Helper::coef_binomial(n,i) * Helper::potencia(u,i) * Helper::potencia(1-u,n-i) );
}

float CurvaBezier::calcular_base_primera_derivada (int n, int i, float u) {
	float coef = Helper::coef_binomial(n,i) * Helper::potencia(u,i-1) * Helper::potencia(1-u,n-i-1);
	float primerTermino = i * (1-u);
	float segundoTermino = (n-i) * u;
	return ( coef * (primerTermino - segundoTermino) );
}

float CurvaBezier::calcular_base_segunda_derivada (int n, int i, float u) {
	float coef = Helper::coef_binomial(n,i) * Helper::potencia(u,i-2) * Helper::potencia(1-u,n-i-2);
	float primerTermino = i * (i-1) * Helper::potencia(1-u,2);
	float segundoTermino = ( (n-i-1) * Helper::potencia(u,2) - 2 * i * u * (1-u) );
	return ( coef * (primerTermino + (n-i) * segundoTermino) );
}

CurvaBezier::CurvaBezier (std::vector<glm::vec3> ptosControl, glm::vec3 centro, glm::vec3 orientacion): Curva (ptosControl, centro, orientacion) { }

glm::vec3 CurvaBezier::dameTangente (float u) {
	if ((u != 0.0) && (u != 1.0)) return Curva::dameTangente (u);
	
	glm::vec3 tangente = glm::vec3 (0.0,0.0,0.0);
	if (u == 0.0) {
		glm::vec3 primerPunto = puntosControl->at(0);
		glm::vec3 segundoPunto = puntosControl->at(1);
		tangente = (segundoPunto - primerPunto);
	} else {
		glm::vec3 primerPunto = puntosControl->at(puntosControl->size() - 2);
		glm::vec3 segundoPunto = puntosControl->at(puntosControl->size() - 1);
		tangente = (segundoPunto - primerPunto);
	}
	
	if ((tangente.x == 0.0) && (tangente.y == 0.0) && (tangente.z == 0.0)) return tangente;
	return (glm::normalize (tangente));
}

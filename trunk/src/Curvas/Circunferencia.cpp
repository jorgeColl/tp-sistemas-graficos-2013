#include "Circunferencia.h"

Circunferencia::Circunferencia (glm::vec3 centro, unsigned int radio)
					: CurvaBSpline (Circunferencia::mis_puntos(centro, radio), centro, glm::vec3(0.0,0.0,1.0)) { }


std::vector<glm::vec3> Circunferencia::mis_puntos (glm::vec3 centro, unsigned int radio) {
	std::vector<glm::vec3> ptosControl;
	
	std::vector<glm::vec3> puntos;
	puntos.push_back (glm::vec3 (centro.x - radio, centro.y, centro.z));
	puntos.push_back (glm::vec3 (centro.x, centro.y + radio, centro.z));
	puntos.push_back (glm::vec3 (centro.x + radio, centro.y, centro.z));
	puntos.push_back (glm::vec3 (centro.x, centro.y - radio, centro.z));
	
	for (unsigned int i = 0 ; i < puntos.size() ; i++) {
		for (unsigned int j = 0 ; j <= CurvaBSpline::ORDEN ; j++) {
			ptosControl.push_back (puntos.at(i));
		}
	}
	
	return ptosControl;
}

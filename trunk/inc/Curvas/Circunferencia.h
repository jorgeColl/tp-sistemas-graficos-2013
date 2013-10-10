#pragma once

#include <vector>
#include <glm/glm.hpp>
#include "CurvaBSpline.h"
#include "Circunferencia.h"

class Circunferencia : public CurvaBSpline {
	
	private:
		static std::vector<glm::vec3> mis_puntos (glm::vec3 centro, float radio);
	
	public:
		// Circunferencia paralela al plano XY
		Circunferencia (glm::vec3 centro, float radio);
};

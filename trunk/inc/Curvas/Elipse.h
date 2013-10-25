#pragma once

#include <vector>
#include <glm/glm.hpp>
#include "CurvaBSpline.h"

class Elipse : public CurvaBSpline {
	
	private:
		static std::vector<glm::vec3> mis_puntos (glm::vec3 centro, float semieje_horizontal, float semieje_vertical);
	
	public:
		// Elipse paralela al plano XY
		Elipse (glm::vec3 centro, float semieje_horizontal, float semieje_vertical);
};

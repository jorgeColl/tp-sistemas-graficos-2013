#pragma once

#include <vector>
#include <glm/glm.hpp>
#include "Curva.h"

class CurvaBezier : public Curva {
	
	protected:
		float calcular_base (int n, int i, float u);
	
	public:
		CurvaBezier (std::vector<glm::vec3> ptosControl);
		
};

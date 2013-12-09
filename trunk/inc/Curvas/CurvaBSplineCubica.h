#pragma once

#include <vector>
#include <glm/glm.hpp>
#include "Curva.h"

class CurvaBSplineCubica : public Curva {
	
	protected:
		virtual float calcular_base (int n, int i, float u);
		virtual float calcular_base_primera_derivada (int n, int i, float u);
		virtual float calcular_base_segunda_derivada (int n, int i, float u);
	
	public:
		CurvaBSplineCubica (std::vector<glm::vec3> ptosControl, glm::vec3 centro, glm::vec3 orientacion);
		
};

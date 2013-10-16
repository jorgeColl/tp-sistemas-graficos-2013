#pragma once

#include <vector>
#include <glm/glm.hpp>
#include "CurvaBSpline.h"

class CurvaPerturbada : public CurvaBSpline {
	
	private:
		std::vector<glm::vec3>* ptosControlSinPerturbar;
		float mi_perturbacion;
		
		static std::vector<glm::vec3> perturbar_puntos (std::vector<glm::vec3> ptosControl, float perturbacion);
	
	public:
		// perturba aleatoriamente a los puntos de control en x
		CurvaPerturbada (std::vector<glm::vec3> ptosControl, glm::vec3 centro, glm::vec3 orientacion, float perturbacion);
		
		// vuelve la curva al estado original pero con una nueva perturbacion
		virtual void reset ();
		
		~CurvaPerturbada();
};

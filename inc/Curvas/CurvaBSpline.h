#pragma once

#include <vector>
#include <glm/glm.hpp>
#include "Curva.h"
#include "CurvaBSplineCubica.h"

class CurvaBSpline : public Curva {
	
	private:
		std::vector<CurvaBSplineCubica*>* tramos;
	
	public:
		static const unsigned int ORDEN;
		
		CurvaBSpline (std::vector<glm::vec3> ptosControl);
		
		int cantidad_tramos ();
		virtual glm::vec3 damePunto (float u);
		
		virtual void transformar (glm::mat4 matriz);
		
		~CurvaBSpline ();
		
};

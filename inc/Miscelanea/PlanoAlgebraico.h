#pragma once

#include <glm/glm.hpp>

class PlanoAlgebraico {
	
	private:
		float a, b, c, d;
	
	public:
		// construye un plano en R3 que pasa por 'punto' y es perpendicular a 'normal'
		PlanoAlgebraico (glm::vec3 punto, glm::vec3 normal);
		
		glm::vec3 proyectar (glm::vec3 vector);
		
};

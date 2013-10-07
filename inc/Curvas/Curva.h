#pragma once

#include <vector>
#include <glm/glm.hpp>

class Curva {
	
	private:
		std::vector<glm::vec3>*  puntosControl;
		
	protected:
		virtual float calcular_base (int n, int i, float u);
		
	public:
		Curva ();
		Curva (std::vector<glm::vec3> ptosControl);
		
		virtual glm::vec3 damePunto (float u);
		virtual int cantidad_tramos() { return 1; };
		
		virtual void transformar (glm::mat4 matriz);
		
		virtual ~Curva ();
		
};

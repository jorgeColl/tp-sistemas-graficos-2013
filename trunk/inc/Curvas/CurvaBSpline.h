#pragma once

#include <vector>
#include <glm/glm.hpp>
#include "Curva.h"
#include "CurvaBSplineCubica.h"

class CurvaBSpline : public Curva {
	
	private:
		std::vector<CurvaBSplineCubica*>* tramos;
	
	protected:
		void init (std::vector<glm::vec3> ptosControl, glm::vec3 centro, glm::vec3 orientacion);
		void destruir_tramos ();
		
	public:
		static const unsigned int ORDEN;
		
		CurvaBSpline (std::vector<glm::vec3> ptosControl, glm::vec3 centro, glm::vec3 orientacion);
		
		int cantidad_tramos ();
		virtual glm::vec3 damePunto (float u);
		
		// transforma solo los puntos de control, no el centro ni la orientacion de la curva
		virtual void transformar (glm::mat4 matriz);
		
		// vuelve la curva al estado en el que fue creada
		virtual void reset ();
		
		~CurvaBSpline ();
		
};

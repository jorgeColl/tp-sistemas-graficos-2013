#pragma once
#include "Funcion.h"
#include "CurvaBezier.h"
#include <vector>
#include <glm/glm.hpp>

class  FuncionCurvaBezier : public Funcion {
	private:
		CurvaBezier mi_curva;
		float x_min, x_max;
	
	public:
		FuncionCurvaBezier (std::vector<glm::vec3> puntosControl);
		
		virtual float evaluar_en (float x);
		
		virtual float get_x_min ();

		virtual float get_x_max ();
		
		virtual ~FuncionCurvaBezier ();
};

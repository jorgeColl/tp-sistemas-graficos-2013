#include "Elipse.h"
#include <exception>
#include <iostream>

Elipse::Elipse (glm::vec3 centro, float semieje_horizontal, float semieje_vertical)
					: CurvaBSpline (Elipse::mis_puntos(centro, semieje_horizontal, semieje_vertical), centro, glm::vec3(0.0,0.0,1.0)) { }


std::vector<glm::vec3> Elipse::mis_puntos (glm::vec3 centro, float semieje_horizontal, float semieje_vertical) {
	if ((semieje_horizontal < 0.0) || (semieje_vertical < 0.0)) throw std::exception();
	
	std::vector<glm::vec3> ptosControl;
	
	std::vector<glm::vec3> puntos;
	puntos.push_back (glm::vec3 ( centro.x + semieje_horizontal  ,			centro.y		   , centro.z ));
	puntos.push_back (glm::vec3 (			centro.x			 , centro.y + semieje_vertical , centro.z ));
	puntos.push_back (glm::vec3 ( centro.x - semieje_horizontal  ,			centro.y		   , centro.z ));
	puntos.push_back (glm::vec3 (			centro.x			 , centro.y - semieje_vertical , centro.z ));
	
	// doy dos vueltas omitiendo el ultimo punto de la segunda
	for (unsigned int j = 0 ; j < 2 ; j++) {
		for (unsigned int i = 0 ; i < puntos.size() ; i++) {
			if ((j != 1) || (i != ((puntos.size()) - 1)))
				ptosControl.push_back (puntos.at(i));
		}
	}
	
	return ptosControl;
}

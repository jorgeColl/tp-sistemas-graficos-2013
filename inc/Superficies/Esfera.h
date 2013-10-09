#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "Superficie.h"

class Esfera : public Superficie {
	
	private:
		static GLenum MODO;
	
	public:
		Esfera (myWindow* passed_window, const float radius, const unsigned int loops, const unsigned int segmentsPerLoop);
		~Esfera ();
};

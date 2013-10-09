#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "Superficie.h"

class Cubo : public Superficie {
	
	private:
		static GLenum MODO;
	
	public:
		Cubo (myWindow* passed_window);
		~Cubo ();
};

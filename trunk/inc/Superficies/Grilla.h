#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "Superficie.h"

class Grilla : public Superficie {
	
	private:
		static GLenum MODO;
	
	public:
		Grilla (myWindow* passed_window, int size);
		~Grilla ();
};

#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "Superficie.h"

class SuperficieDummy : public Superficie {
	
	public:
		SuperficieDummy (GLfloat* v_buffer, GLfloat* n_buffer, GLuint* i_buffer,
						 unsigned int v_size, unsigned int n_size, unsigned int i_size,
						 GLenum modoRecibido, myWindow* passed_window);
};

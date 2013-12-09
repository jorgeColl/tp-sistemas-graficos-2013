#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "Superficie.h"

class Esfera : public Superficie {
	
	private:
		static GLenum MODO;
		
		void llenarBuffers (std::vector<float>* din_vertex_buffer, std::vector<float>* din_tangent_buffer, std::vector<float>* din_normal_buffer,
							std::vector<float>* din_texture_buffer, const float radius, float theta, float phi);
		
	public:
		Esfera (myWindow* passed_window, const float radius, const unsigned int loops, const unsigned int segmentsPerLoop);
		~Esfera ();
};

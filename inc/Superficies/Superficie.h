#pragma once

#include <vector>
#include <GL/glew.h>
//#include <GL/freeglut.h>
#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp> 

class myWindow;

class Superficie {
	
	private:
		myWindow* window;
		
		glm::mat3 calcular_normal_matrix (glm::mat4 view_model_matrix);
		void bind_matrix (GLuint* programHandle, const char* matriz, GLfloat* origen);
	
	protected:
		GLfloat* vertex_buffer;
		GLfloat* normal_buffer;
		GLuint* index_buffer;
		unsigned int vertex_buffer_size;
		unsigned int normal_buffer_size;
		unsigned int index_buffer_size;
		GLenum modo;
		
	public:
		Superficie ();
		Superficie (myWindow* passed_window);
		
		virtual void render (glm::mat4 view_model_matrix);
		
		virtual ~Superficie ();
		
};

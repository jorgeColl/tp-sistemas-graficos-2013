#pragma once

#include <vector>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <string>
#include "Animacion.h"

class myWindow;

class Superficie {
private:
	glm::mat3 calcular_normal_matrix(glm::mat4 view_model_matrix);
	void bind_matrix(GLuint* programHandle, const char* matriz, GLfloat* origen);

	void init();

protected:
	GLfloat* vertex_buffer;
	GLfloat* tangent_buffer;
	GLfloat* normal_buffer;
	GLfloat* texture_buffer;
	GLuint* index_buffer;
	unsigned int vertex_buffer_size;
	unsigned int tangent_buffer_size;
	unsigned int normal_buffer_size;
	unsigned int texture_buffer_size;
	unsigned int index_buffer_size;
	GLenum modo;


	Animacion* mi_animacion;

	virtual int cant_puntos_por_salto() {
		return 1;
	};

public:
	std::string nombreTextura;
	myWindow* window;
	Superficie();
	Superficie(myWindow* passed_window);

	virtual void render(glm::mat4 view_model_matrix);

	virtual void set_animacion(Animacion* ani);

	virtual void animar();

	virtual ~Superficie();
		
};

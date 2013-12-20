#pragma once

#include <vector>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <string>

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
	
	// Animacion senoidal
	bool debeAnimarse;
	float tiempo;
	float amplitud, numeroOnda, velocidad;

public:
	glm::vec3 ka;
	glm::vec3 kd;
	glm::vec3 ks;
	float shininess;
	std::string nombreTextura;
	std::string nombreTexturaNormal;
	bool reflexionActivada;
	
	myWindow* window;
	Superficie();
	Superficie(myWindow* passed_window);

	virtual void render(glm::mat4 view_model_matrix);
	
	virtual void set_parametros_animacion (float _amplitud, float _numeroOnda, float _velocidad);
	virtual void animar();

	virtual ~Superficie();
		
};

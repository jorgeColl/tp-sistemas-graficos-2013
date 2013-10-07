#include "Superficie.h"

Superficie::Superficie () {
	this->vertex_buffer = NULL;
	this->normal_buffer = NULL;
	this->index_buffer  = NULL;
}

glm::mat3 Superficie::calcular_normal_matrix (glm::mat4 view_model_matrix) {
	glm::mat3 normal_matrix = glm::mat3 (1.0f);
	for (int i = 0 ; i < 3 ; i++) {
		for (int j = 0 ; j < 3 ; j++) {
			normal_matrix[i][j] = view_model_matrix[i][j];
		}
	}
	return normal_matrix;
}

void Superficie::bind_matrix (GLuint programHandle, const char* matriz, GLfloat* origen) {
	GLuint location_matrix = glGetUniformLocation (programHandle, matriz); 
	if (location_matrix >= 0) { 
		glUniformMatrix3fv (location_matrix, 1, GL_FALSE, origen); 
	}
}

void Superficie::render (GLuint programHandle, glm::mat4 view_model_matrix) {
	// Normal Matrix
	glm::mat3 normal_matrix = this->calcular_normal_matrix (view_model_matrix);
	
	// Bind Normal Matrix
	this->bind_matrix (programHandle, "NormalMatrix", &normal_matrix[0][0]);
	
	// Bind Model Matrix
	this->bind_matrix (programHandle, "ModelMatrix", &view_model_matrix[0][0]);
	
	glEnableClientState (GL_VERTEX_ARRAY);
	glEnableClientState (GL_NORMAL_ARRAY);
	
	glVertexPointer (3, GL_FLOAT, 0, this->vertex_buffer);
	glNormalPointer (GL_FLOAT, 0, this->normal_buffer);
	
	glDrawElements (GL_TRIANGLE_STRIP, this->index_buffer_size, GL_UNSIGNED_INT, this->index_buffer);
	
	glDisableClientState (GL_VERTEX_ARRAY);
	glDisableClientState (GL_NORMAL_ARRAY);
}

Superficie::~Superficie () {
	if (this->vertex_buffer != NULL) delete[] this->vertex_buffer;
	if (this->normal_buffer != NULL) delete[] this->normal_buffer;
	if (this->index_buffer  != NULL) delete[] this->index_buffer;
}

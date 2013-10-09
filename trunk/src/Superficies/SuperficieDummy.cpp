#include "SuperficieDummy.h"

SuperficieDummy::SuperficieDummy (GLfloat* v_buffer, GLfloat* n_buffer, GLuint* i_buffer,
								  unsigned int v_size, unsigned int n_size, unsigned int i_size,
								  GLenum modoRecibido, myWindow* passed_window) : Superficie (passed_window) {
	
	this->vertex_buffer = v_buffer;
	this->normal_buffer = n_buffer;
	this->index_buffer = i_buffer;
	
	this->vertex_buffer_size = v_size;
	this->normal_buffer_size = n_size;
	this->index_buffer_size = i_size;
	
	this->modo = modoRecibido;
}

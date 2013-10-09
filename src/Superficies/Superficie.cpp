#include "Superficie.h"
#include "myWindow.h"
#include <iostream>

Superficie::Superficie () {
	this->window = NULL;
}

Superficie::Superficie (myWindow* passed_window) {
	this->vertex_buffer = NULL;
	this->normal_buffer = NULL;
	this->index_buffer  = NULL;
	this->vertex_buffer_size = 0;
	this->normal_buffer_size = 0;
	this->index_buffer_size = 0;
	this->window = passed_window;
	
	this->modo = GL_TRIANGLE_STRIP;
}

void Superficie::render (glm::mat4 view_model_matrix) {
	if (this->window != NULL)
		this->window->renderObject (view_model_matrix, this->vertex_buffer, this->normal_buffer,
									this->index_buffer, this->index_buffer_size, this->modo);
}

Superficie::~Superficie () {
}

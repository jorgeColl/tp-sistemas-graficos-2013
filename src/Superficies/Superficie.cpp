#include "Superficie.h"
#include "myWindow.h"
#include <iostream>

void Superficie::init () {
	this->window = NULL;
	this->vertex_buffer = NULL;
	this->tangent_buffer = NULL;
	this->normal_buffer = NULL;
	this->texture_buffer = NULL;
	this->index_buffer = NULL;
	this->vertex_buffer_size = 0;
	this->tangent_buffer_size = 0;
	this->normal_buffer_size = 0;
	this->texture_buffer_size = 0;
	this->index_buffer_size = 0;
	this->modo = GL_TRIANGLE_STRIP;
	this->mi_animacion = new Animacion(SINvar);
	this->nombreTextura="defaultTexture.jpg";
}

Superficie::Superficie () {
	this->init();
}

Superficie::Superficie (myWindow* passed_window) {
	this->init();
	this->window = passed_window;
}

void Superficie::render (glm::mat4 view_model_matrix) {
	if (this->window != NULL) {
		if ((this->tangent_buffer != NULL) && (this->texture_buffer != NULL)) {
			this->window->renderObject (view_model_matrix, this->vertex_buffer, this->tangent_buffer, this->normal_buffer,
										this->texture_buffer, this->nombreTextura, this->index_buffer, this->index_buffer_size, this->modo);
		} else {
			this->window->renderObject (view_model_matrix, this->vertex_buffer, this->normal_buffer,
										this->index_buffer, this->index_buffer_size, this->modo);
		}
	}
}

void Superficie::set_animacion (Animacion* ani) {
	if (this->mi_animacion) delete (this->mi_animacion);
	this->mi_animacion = ani;
}

void Superficie::animar () {
	if (this->mi_animacion->tiene_variable())
		this->mi_animacion->dar_paso (this->vertex_buffer, this->vertex_buffer_size, this->cant_puntos_por_salto());
}

Superficie::~Superficie () {
	delete (this->mi_animacion);
}

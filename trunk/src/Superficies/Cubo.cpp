#include "Cubo.h"
#include <iostream>

GLenum Cubo::MODO = GL_QUADS;

Cubo::Cubo (myWindow* passed_window) : Superficie (passed_window) {
	
	this->modo = Cubo::MODO;
	
	this->vertex_buffer_size = 3*8;
    this->vertex_buffer = new GLfloat[this->vertex_buffer_size];

    this->normal_buffer_size = 3*8;
    this->normal_buffer = new GLfloat[this->normal_buffer_size];
    
    this->index_buffer_size = 4 * 6;
    this->index_buffer = new GLuint[this->index_buffer_size];

    this->vertex_buffer[0] = 0.5f;
    this->vertex_buffer[1] = 0.5f;
    this->vertex_buffer[2] = -0.5f;

    this->vertex_buffer[3] = 0.5f;
    this->vertex_buffer[4] = -0.5f;
    this->vertex_buffer[5] = -0.5f;

    this->vertex_buffer[6] = -0.5f;
    this->vertex_buffer[7] = -0.5f;
    this->vertex_buffer[8] = -0.5f;

    this->vertex_buffer[9] = -0.5f;
    this->vertex_buffer[10] = 0.5f;
    this->vertex_buffer[11] = -0.5f;

    this->vertex_buffer[12] = 0.5f;
    this->vertex_buffer[13] = 0.5f;
    this->vertex_buffer[14] = 0.5f;

    this->vertex_buffer[15] = 0.5f;
    this->vertex_buffer[16] = -0.5f;
    this->vertex_buffer[17] = 0.5f;

    this->vertex_buffer[18] = -0.5f;
    this->vertex_buffer[19] = -0.5f;
    this->vertex_buffer[20] = 0.5f;

    this->vertex_buffer[21] = -0.5f;
    this->vertex_buffer[22] = 0.5f;
    this->vertex_buffer[23] = 0.5f;

    this->index_buffer[0] = 0;
    this->index_buffer[1] = 1;
    this->index_buffer[2] = 2;
    this->index_buffer[3] = 3;
 
    this->index_buffer[4] = 4;
    this->index_buffer[5] = 5;
    this->index_buffer[6] = 6;
    this->index_buffer[7] = 7;
    
    this->index_buffer[8] = 0;
    this->index_buffer[9] = 4;
    this->index_buffer[10] = 5;
    this->index_buffer[11] = 1;

    this->index_buffer[12] = 1;
    this->index_buffer[13] = 5;
    this->index_buffer[14] = 6;
    this->index_buffer[15] = 2;

    this->index_buffer[16] = 2;
    this->index_buffer[17] = 6;
    this->index_buffer[18] = 7;
    this->index_buffer[19] = 3;

    this->index_buffer[20] = 3;
    this->index_buffer[21] = 7;
    this->index_buffer[22] = 4;
    this->index_buffer[23] = 0;

    this->normal_buffer[0] = 0.5f;
    this->normal_buffer[1] = 0.5f;
    this->normal_buffer[2] = 0.0f;

    this->normal_buffer[3] = 0.5f;
    this->normal_buffer[4] = -0.5f;
    this->normal_buffer[5] = 0.0f;

    this->normal_buffer[6] = -0.5f;
    this->normal_buffer[7] = -0.5f;
    this->normal_buffer[8] = 0.0f;

    this->normal_buffer[9] = -0.5f;
    this->normal_buffer[10] = 0.5f;
    this->normal_buffer[11] = 0.0f;

    this->normal_buffer[12] = 0.5f;
    this->normal_buffer[13] = 0.5f;
    this->normal_buffer[14] = 0.0f;

    this->normal_buffer[15] = 0.5f;
    this->normal_buffer[16] = -0.5f;
    this->normal_buffer[17] = 0.0f;

    this->normal_buffer[18] = -0.5f;
    this->normal_buffer[19] = -0.5f;
    this->normal_buffer[20] = 0.0f;

    this->normal_buffer[21] = -0.5f;
    this->normal_buffer[22] = 0.5f;
    this->normal_buffer[23] = 0.0f;
}

Cubo::~Cubo () {
	delete[] this->vertex_buffer;
	delete[] this->normal_buffer;
	delete[] this->index_buffer;
}

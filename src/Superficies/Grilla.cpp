#include "Grilla.h"

GLenum Grilla::MODO = GL_LINES;

Grilla::Grilla (myWindow* passed_window, int size) : Superficie (passed_window) {
	
	this->modo = Grilla::MODO;
	
	this->vertex_buffer_size = 12*(2*size +1);
    this->vertex_buffer = new GLfloat[this->vertex_buffer_size];
    
    this->normal_buffer_size = this->vertex_buffer_size;
    this->normal_buffer = new GLfloat[this->normal_buffer_size];
    
    this->index_buffer_size = 4*(2*size +1);
    this->index_buffer = new GLuint[this->index_buffer_size];

    int offset;
    for (int i=0; i<size; i++)
    {
        offset = 24*i;
        this->vertex_buffer[offset++] = -size;
        this->vertex_buffer[offset++] = i+1;
        this->vertex_buffer[offset++] = 0;

        this->vertex_buffer[offset++] = size;
        this->vertex_buffer[offset++] = i+1;
        this->vertex_buffer[offset++] = 0;

        this->vertex_buffer[offset++] = -size;
        this->vertex_buffer[offset++] = -(i+1);
        this->vertex_buffer[offset++] = 0;

        this->vertex_buffer[offset++] = size;
        this->vertex_buffer[offset++] = -(i+1);
        this->vertex_buffer[offset++] = 0;


        this->vertex_buffer[offset++] = i+1;
        this->vertex_buffer[offset++] = -size;
        this->vertex_buffer[offset++] = 0;

        this->vertex_buffer[offset++] = i+1;
        this->vertex_buffer[offset++] = size;
        this->vertex_buffer[offset++] = 0;

        this->vertex_buffer[offset++] = -(i+1);
        this->vertex_buffer[offset++] = -size;
        this->vertex_buffer[offset++] = 0;

        this->vertex_buffer[offset++] = -(i+1);
        this->vertex_buffer[offset++] = size;
        this->vertex_buffer[offset++] = 0;
    }

    offset = 24 * size;
    this->vertex_buffer[offset++]   = -size;
    this->vertex_buffer[offset++] = 0;
    this->vertex_buffer[offset++] = 0;

    this->vertex_buffer[offset++] = size;
    this->vertex_buffer[offset++] = 0;
    this->vertex_buffer[offset++] = 0;

    this->vertex_buffer[offset++] = 0;
    this->vertex_buffer[offset++] = -size;
    this->vertex_buffer[offset++] = 0;

    this->vertex_buffer[offset++] = 0;
    this->vertex_buffer[offset++] = size;
    this->vertex_buffer[offset++] = 0;

    for (unsigned int i=0; i< this->index_buffer_size; i++)
    {
        this->index_buffer[i] = i;
    }
    
    for (unsigned int j = 0; j < (this->normal_buffer_size - 2); j++)
    {
        this->normal_buffer[j] = 0.0;
        this->normal_buffer[j+1] = 0.0;
        this->normal_buffer[j+1] = 1.0;
    }
}

Grilla::~Grilla () {
	delete[] this->vertex_buffer;
	delete[] this->normal_buffer;
	delete[] this->index_buffer;
}

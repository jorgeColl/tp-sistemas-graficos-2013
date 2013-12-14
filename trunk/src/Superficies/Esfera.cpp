#include "Esfera.h"
#include <iostream>

#define PI 3.1415926f

GLenum Esfera::MODO = GL_TRIANGLE_STRIP;

Esfera::Esfera (myWindow* passed_window, const float radius, const unsigned int loops, const unsigned int segmentsPerLoop) : Superficie (passed_window) {
	
	this->modo = Esfera::MODO;
	std::vector<float> din_vertex_buffer;
	std::vector<float> din_tangent_buffer;
	std::vector<float> din_normal_buffer;
	std::vector<float> din_texture_buffer;
	std::vector<unsigned int> din_index_buffer;
	
	for (unsigned int loopSegmentNumber = 0; loopSegmentNumber < segmentsPerLoop; ++loopSegmentNumber) {
		float theta = 0;
		float phi = loopSegmentNumber * 2 * PI / segmentsPerLoop;
		this->llenarBuffers (&din_vertex_buffer, &din_tangent_buffer, &din_normal_buffer, &din_texture_buffer, radius, theta, phi);
	}
	
	for (unsigned int loopNumber = 0; loopNumber <= loops; ++loopNumber) {
		for (unsigned int loopSegmentNumber = 0; loopSegmentNumber < segmentsPerLoop; ++loopSegmentNumber) {
			float theta = (loopNumber * PI / loops) + ((PI * loopSegmentNumber) / (segmentsPerLoop * loops));
			if (loopNumber == loops) theta = PI;
			float phi = loopSegmentNumber * 2 * PI / segmentsPerLoop;
			this->llenarBuffers (&din_vertex_buffer, &din_tangent_buffer, &din_normal_buffer, &din_texture_buffer, radius, theta, phi);
		}
	}
	
	for (unsigned int loopSegmentNumber = 0; loopSegmentNumber < segmentsPerLoop; ++loopSegmentNumber) {
		din_index_buffer.push_back(loopSegmentNumber);
		din_index_buffer.push_back(segmentsPerLoop + loopSegmentNumber);
	}
	for (unsigned int loopNumber = 0; loopNumber < loops; ++loopNumber) {
		for (unsigned int loopSegmentNumber = 0; loopSegmentNumber < segmentsPerLoop; ++loopSegmentNumber) {
			din_index_buffer.push_back(((loopNumber + 1) * segmentsPerLoop) + loopSegmentNumber);
			din_index_buffer.push_back(((loopNumber + 2) * segmentsPerLoop) + loopSegmentNumber);
		}
	}
	
	
	//
	this->vertex_buffer_size = din_vertex_buffer.size();
	this->vertex_buffer = new GLfloat[this->vertex_buffer_size];
	for (unsigned int i = 0 ; i < this->vertex_buffer_size ; ++i) this->vertex_buffer[i] = (din_vertex_buffer.at(i));
	
	this->tangent_buffer_size = din_tangent_buffer.size();
	this->tangent_buffer = new GLfloat[this->tangent_buffer_size];
	for (unsigned int i = 0 ; i < this->tangent_buffer_size ; ++i) this->tangent_buffer[i] = (din_tangent_buffer.at(i));
	
	this->normal_buffer_size = din_normal_buffer.size();
	this->normal_buffer = new GLfloat[this->normal_buffer_size];
	for (unsigned int i = 0 ; i < this->normal_buffer_size ; ++i) this->normal_buffer[i] = (din_normal_buffer.at(i));
	
	this->texture_buffer_size = din_texture_buffer.size();
	this->texture_buffer = new GLfloat[this->texture_buffer_size];
	for (unsigned int i = 0 ; i < this->texture_buffer_size ; ++i) this->texture_buffer[i] = (din_texture_buffer.at(i));
	
	this->index_buffer_size = din_index_buffer.size();
	this->index_buffer = new GLuint[this->index_buffer_size];
	for (unsigned int i = 0 ; i < this->index_buffer_size ; ++i) this->index_buffer[i] = (din_index_buffer.at(i));
}

void Esfera::llenarBuffers (std::vector<float>* din_vertex_buffer, std::vector<float>* din_tangent_buffer, std::vector<float>* din_normal_buffer,
							std::vector<float>* din_texture_buffer, const float radius, float theta, float phi) {
	
	float phi2 = phi + 2 * PI * 0.001;
	float sinTheta = std::sin(theta);
	float sinPhi = std::sin(phi);
	float sinPhi2 = std::sin(phi2);
	float cosTheta = std::cos(theta);
	float cosPhi = std::cos(phi);
	float cosPhi2 = std::cos(phi2);
	
	glm::vec3 punto1 = glm::vec3 (radius * cosPhi * sinTheta, radius * sinPhi * sinTheta, radius * cosTheta);
	glm::vec3 punto2 = glm::vec3 (radius * cosPhi2 * sinTheta, radius * sinPhi2 * sinTheta, radius * cosTheta);
	glm::vec3 tangente = (punto2 - punto1);
	if ((tangente.x != 0.0) && (tangente.y != 0.0) && (tangente.z != 0.0)) tangente = glm::normalize (tangente);
	glm::vec3 normal = glm::vec3 (punto1);
	if ((normal.x != 0.0) && (normal.y != 0.0) && (normal.z != 0.0)) normal = glm::normalize (normal);
	
	din_vertex_buffer->push_back(punto1.x);
	din_vertex_buffer->push_back(punto1.y);
	din_vertex_buffer->push_back(punto1.z);
	
	din_tangent_buffer->push_back(tangente.x);
	din_tangent_buffer->push_back(tangente.y);
	din_tangent_buffer->push_back(tangente.z);
	
	din_normal_buffer->push_back(normal.x);
	din_normal_buffer->push_back(normal.y);
	din_normal_buffer->push_back(normal.z);
	
	din_texture_buffer->push_back( (phi / (2.0*PI)) );	// u
	din_texture_buffer->push_back( (theta / PI) );		// v
}

Esfera::~Esfera () {
	delete[] this->vertex_buffer;
	delete[] this->tangent_buffer;
	delete[] this->normal_buffer;
	delete[] this->texture_buffer;
	delete[] this->index_buffer;
}

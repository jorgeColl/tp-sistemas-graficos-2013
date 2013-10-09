#include "Esfera.h"
#include <iostream>

GLenum Esfera::MODO = GL_TRIANGLE_STRIP;

Esfera::Esfera (myWindow* passed_window, const float radius, const unsigned int loops, const unsigned int segmentsPerLoop) : Superficie (passed_window) {
	
	this->modo = Esfera::MODO;
	
	float PI = 3.1415f;
	std::vector<float> din_vertex_buffer;
	std::vector<unsigned int> din_index_buffer;
	
	for (unsigned int loopSegmentNumber = 0; loopSegmentNumber < segmentsPerLoop; ++loopSegmentNumber)
	{
		float theta = 0;
		float phi = loopSegmentNumber * 2 * PI / segmentsPerLoop;
		float sinTheta = std::sin(theta);
		float sinPhi = std::sin(phi);
		float cosTheta = std::cos(theta);
		float cosPhi = std::cos(phi);

        // 
        din_vertex_buffer.push_back(radius * cosPhi * sinTheta); // Vx
        din_vertex_buffer.push_back(radius * sinPhi * sinTheta); // Vy
        din_vertex_buffer.push_back(radius * cosTheta);          // Vz
	}
	for (unsigned int loopNumber = 0; loopNumber <= loops; ++loopNumber)
	{
		for (unsigned int loopSegmentNumber = 0; loopSegmentNumber < segmentsPerLoop; ++loopSegmentNumber)
		{
			float theta = (loopNumber * PI / loops) + ((PI * loopSegmentNumber) / (segmentsPerLoop * loops));
			if (loopNumber == loops)
			{
				theta = PI;
			}
			float phi = loopSegmentNumber * 2 * PI / segmentsPerLoop;
			float sinTheta = std::sin(theta);
			float sinPhi = std::sin(phi);
			float cosTheta = std::cos(theta);
			float cosPhi = std::cos(phi);

            din_vertex_buffer.push_back(radius * cosPhi * sinTheta);
            din_vertex_buffer.push_back(radius * sinPhi * sinTheta);
            din_vertex_buffer.push_back(radius * cosTheta);
		}
	}
	for (unsigned int loopSegmentNumber = 0; loopSegmentNumber < segmentsPerLoop; ++loopSegmentNumber)
	{
		din_index_buffer.push_back(loopSegmentNumber);
		din_index_buffer.push_back(segmentsPerLoop + loopSegmentNumber);
	}
	for (unsigned int loopNumber = 0; loopNumber < loops; ++loopNumber)
	{
		for (unsigned int loopSegmentNumber = 0; loopSegmentNumber < segmentsPerLoop; ++loopSegmentNumber)
		{
			din_index_buffer.push_back(((loopNumber + 1) * segmentsPerLoop) + loopSegmentNumber);
			din_index_buffer.push_back(((loopNumber + 2) * segmentsPerLoop) + loopSegmentNumber);
		}
	}

    //
    this->vertex_buffer_size = din_vertex_buffer.size();
    this->normal_buffer_size = din_vertex_buffer.size();
    this->index_buffer_size = din_index_buffer.size();
    
    this->vertex_buffer = new float[din_vertex_buffer.size()];
    this->normal_buffer = new float[din_vertex_buffer.size()];
    this->index_buffer = new unsigned int[din_index_buffer.size()];

    std::vector<float>::iterator vertex_it;
    unsigned int v = 0;
    for (vertex_it = din_vertex_buffer.begin(); vertex_it != din_vertex_buffer.end(); vertex_it++)
    {
        this->vertex_buffer[v] = *vertex_it;
        this->normal_buffer[v] = *vertex_it;
        v++;
    }

    std::vector<unsigned int>::iterator index_it;
    unsigned int i = 0;
    for (index_it = din_index_buffer.begin(); index_it != din_index_buffer.end(); index_it++)
    {
        this->index_buffer[i] = *index_it;
        i++;
    }
}

Esfera::~Esfera () {
	delete[] this->vertex_buffer;
	delete[] this->normal_buffer;
	delete[] this->index_buffer;
}

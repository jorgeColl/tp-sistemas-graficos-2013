/*
 * Ladrillo.cpp
 *
 *  Created on: 11/12/2013
 *      Author: jorge
 */

#include "Ladrillo.h"

void Ladrillo::renderizar(glm::mat4 model_matrix) {

	unsigned int index_buffer_size = 4;
	GLenum modo = GL_QUADS;
	std::string nombreTex = "brick.jpg";
	//this->mi_superficie->window->renderObject (model_matrix,positionData ,tangentData,normalData,
	//		textureData, nombreTex, index_buffer, index_buffer_size,modo );
}

Ladrillo::Ladrillo(myWindow* ventana) :Figura(ventana) {
	/*this->index_buffer={0,1,2,3,4};
	this->positionData=
		{
		     0.5f, -0.5f,  0.5f,
		     0.5f, -0.5f, -0.5f,
		     0.5f,  0.5f, -0.5f,
		     0.5f,  0.5f,  0.5f,

		     0.5f,  0.5f,  0.5f,
		     0.5f,  0.5f, -0.5f,
		    -0.5f,  0.5f, -0.5f,
		    -0.5f,  0.5f,  0.5f,

		    -0.5f,  0.5f,  0.5f,
		    -0.5f,  0.5f, -0.5f,
		    -0.5f, -0.5f, -0.5f,
		    -0.5f, -0.5f,  0.5f,

		    -0.5f, -0.5f,  0.5f,
		     0.5f, -0.5f,  0.5f,
		     0.5f, -0.5f, -0.5f,
		    -0.5f, -0.5f, -0.5f,

		     0.5f,  0.5f,  0.5f,
		     0.5f, -0.5f,  0.5f,
		    -0.5f, -0.5f,  0.5f,
		    -0.5f,  0.5f,  0.5f,

		     0.5f,  0.5f, -0.5f,
		    -0.5f,  0.5f, -0.5f,
		    -0.5f, -0.5f, -0.5f,
		     0.5f, -0.5f, -0.5f
		};
	this->normalData=
		{
		    1.0f,  0.0f,  0.0f,
		    1.0f,  0.0f,  0.0f,
		    1.0f,  0.0f,  0.0f,
		    1.0f,  0.0f,  0.0f,

		    0.0f,  1.0f,  0.0f,
		    0.0f,  1.0f,  0.0f,
		    0.0f,  1.0f,  0.0f,
		    0.0f,  1.0f,  0.0f,

		   -1.0f,  0.0f,  0.0f,
		   -1.0f,  0.0f,  0.0f,
		   -1.0f,  0.0f,  0.0f,
		   -1.0f,  0.0f,  0.0f,

		    0.0f, -1.0f,  0.0f,
		    0.0f, -1.0f,  0.0f,
		    0.0f, -1.0f,  0.0f,
		    0.0f, -1.0f,  0.0f,

		    0.0f,  0.0f,  1.0f,
		    0.0f,  0.0f,  1.0f,
		    0.0f,  0.0f,  1.0f,
		    0.0f,  0.0f,  1.0f,

		    0.0f,  0.0f, -1.0f,
		    0.0f,  0.0f, -1.0f,
		    0.0f,  0.0f, -1.0f,
		    0.0f,  0.0f, -1.0f
		};
	this->textureData=
	{
	    0.0f,  0.0f,
	    1.0f,  0.0f,
	    1.0f,  1.0f,
	    0.0f,  1.0f,

	    0.0f,  0.0f,
	    1.0f,  0.0f,
	    1.0f,  1.0f,
	    0.0f,  1.0f,

	    0.0f,  0.0f,
	    1.0f,  0.0f,
	    1.0f,  1.0f,
	    0.0f,  1.0f,

	    0.0f,  0.0f,
	    1.0f,  0.0f,
	    1.0f,  1.0f,
	    0.0f,  1.0f,

	    0.0f,  0.0f,
	    1.0f,  0.0f,
	    1.0f,  1.0f,
	    0.0f,  1.0f,

	    0.0f,  0.0f,
	    1.0f,  0.0f,
	    1.0f,  1.0f,
	    0.0f,  1.0f,
	};
	this->tangentData={
				1.0f,  1.0f,  1.0f,
				1.0f,  1.0f,  1.0f,
				1.0f,  1.0f,  1.0f,
				1.0f,  1.0f,  1.0f,

				1.0f,  1.0f,  1.0f,
				1.0f,  1.0f,  1.0f,
				1.0f,  1.0f,  1.0f,
				1.0f,  1.0f,  1.0f,

				1.0f,  1.0f,  1.0f,
				1.0f,  1.0f,  1.0f,
				1.0f,  1.0f,  1.0f,
				1.0f,  1.0f,  1.0f,

				1.0f,  1.0f,  1.0f,
				1.0f,  1.0f,  1.0f,
				1.0f,  1.0f,  1.0f,
				1.0f,  1.0f,  1.0f,

				1.0f,  1.0f,  1.0f,
				1.0f,  1.0f,  1.0f,
				1.0f,  1.0f,  1.0f,
				1.0f,  1.0f,  1.0f,

				1.0f,  1.0f,  1.0f,
				1.0f,  1.0f,  1.0f,
				1.0f,  1.0f,  1.0f,
				1.0f,  1.0f,  1.0f,
			};*/
}

Ladrillo::~Ladrillo() {
	// TODO Auto-generated destructor stub
}


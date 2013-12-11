/*
 * Ladrillo.h
 *
 *  Created on: 11/12/2013
 *      Author: jorge
 */

#ifndef LADRILLO_H_
#define LADRILLO_H_
#include "figura.h"
class Ladrillo: public Figura  {
	GLuint index_buffer[50];
	GLfloat positionData[72];
	GLfloat normalData[72];
	GLfloat textureData[72];
	GLfloat tangentData[72];

public:
	Ladrillo(myWindow* ventana);
	virtual void renderizar(glm::mat4 model_matrix);
	virtual ~Ladrillo();
};

#endif /* LADRILLO_H_ */

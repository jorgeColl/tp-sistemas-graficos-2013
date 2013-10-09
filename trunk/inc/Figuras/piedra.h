/*
 * Piedra.h
 *
 *  Created on: 08/10/2013
 *      Author: jorge
 */

#ifndef PIEDRA_H_
#define PIEDRA_H_

#include "figura.h"


class Piedra: public Figura {
public:
	Piedra(myWindow* window);
	virtual ~Piedra();
	virtual void renderizar(glm::mat4 model_matrix);
};

#endif /* PIEDRA_H_ */

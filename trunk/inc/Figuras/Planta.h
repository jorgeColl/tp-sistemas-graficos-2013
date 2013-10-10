/*
 * Planta.h
 *
 *  Created on: 10/10/2013
 *      Author: jorge
 */

#ifndef PLANTA_H_
#define PLANTA_H_

#include "figura.h"

class Planta: public Figura {
public:
	Planta(myWindow* ventana);
	virtual ~Planta();
	virtual void renderizar(glm::mat4 model_matrix);
};

#endif /* PLANTA_H_ */

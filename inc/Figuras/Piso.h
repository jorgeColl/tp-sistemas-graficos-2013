/*
 * Piso.h
 *
 *  Created on: 10/10/2013
 *      Author: jorge
 */

#ifndef PISO_H_
#define PISO_H_

#include "figura.h"

class Piso: public Figura {
protected:
	 Superficie* myGrid;
public:
	Piso(myWindow* ventana);
	virtual ~Piso();
	virtual void renderizar(glm::mat4 model_matrix);
};

#endif /* PISO_H_ */

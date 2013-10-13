/*
 * Pez.h
 *
 *  Created on: 12/10/2013
 *      Author: jorge
 */

#ifndef PEZ_H_
#define PEZ_H_

#include "figura.h"
class AletaPez: public Figura {
public:
	AletaPez(myWindow* ventana);
	~AletaPez();
	virtual void renderizar(glm::mat4 model_matrix);
};

class ColaPez: public Figura {
public:
	ColaPez(myWindow* ventana);
	~ColaPez();
	virtual void renderizar(glm::mat4 model_matrix);
};

class TorsoPez: public Figura {
public:
	TorsoPez(myWindow* ventana);
	~TorsoPez();
	virtual void renderizar(glm::mat4 model_matrix);
};

class Pez: public Figura {
protected:
	AletaPez aleta1;
	AletaPez aleta2;
	ColaPez cola;
	TorsoPez torso;
public:
	Pez(myWindow* ventana);
	virtual ~Pez();
	virtual void renderizar(glm::mat4 model_matrix);
};

#endif /* PEZ_H_ */

/*
 * figura.h
 *
 *  Created on: 20/09/2013
 *      Author: jorge
 */

#ifndef FIGURA_H_
#define FIGURA_H_

#include "myWindow.h"
#include <vector>
#include <glm/glm.hpp>
class Figura {
protected:
	myWindow* window;
	std::vector <Figura*> figuras_hijas;
public:
	virtual void renderizar(glm::mat4 model_matrix) = 0;
	virtual ~Figura() {};
	void agregar_figura_hija(Figura& fig);
	void renderizar_figuras_hijas(glm::mat4 model_matrix);

};

#endif /* FIGURA_H_ */

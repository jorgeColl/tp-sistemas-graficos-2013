/*
 * figura.cpp
 *
 *  Created on: 22/09/2013
 *      Author: jorge
 */

#include "figura.h"

void Figura::agregar_figura_hija(Figura& fig) {
	figuras_hijas.push_back(&fig);
}
void Figura::renderizar_figuras_hijas(glm::mat4 model_matrix) {
	for(unsigned int i=0; i<figuras_hijas.size();++i) {
		figuras_hijas[i]->renderizar(model_matrix);
	}
}





/*
 * Escenario.h
 *
 *  Created on: 10/10/2013
 *      Author: jorge
 */

#ifndef ESCENARIO_H_
#define ESCENARIO_H_

#include "figura.h"
#include "cangrejo.h"
#include "piedra.h"
#include "Planta.h"
#include "Piso.h"

class Escenario: public Figura {
protected:
	Cangrejo cangrejo1;
	Piedra piedra1;
	Planta planta1;
	Piso piso;
public:
	Escenario(myWindow* ventana);
	virtual ~Escenario();
	virtual void renderizar(glm::mat4 model_matrix);
};

#endif /* ESCENARIO_H_ */

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
#include "Pez.h"
#include "Grilla.h"

class Escenario: public Figura {
	static const bool DEBUG;
protected:
	Superficie* grilla_debug;
	
	Pez pez1;
	Cangrejo cangrejo1;
	Piedra piedra1;
	Planta planta1;
	Piso piso;
	std::vector<Figura*> figuras;
	glm::vec3 pos_cangrejo;
	bool vuelta_cangrejo;
public:
	Escenario(myWindow* ventana);
	virtual ~Escenario();
	virtual void renderizar(glm::mat4 model_matrix);
	virtual void animar();
protected:
	virtual Superficie* crear_superficie (myWindow* ventana) { return (new Superficie(ventana)); };
};

#endif /* ESCENARIO_H_ */

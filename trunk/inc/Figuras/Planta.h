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
protected:
	virtual Curva* crear_curva_trayectoria ();
	virtual Curva* crear_curva_seccion ();
	virtual int obtener_pasos_trayectoria ();
	virtual int obtener_pasos_seccion ();
	virtual std::vector<glm::mat4> crear_transformaciones ();
	
	// temporal
	virtual Superficie* crear_superficie (myWindow* ventana);
};

#endif /* PLANTA_H_ */

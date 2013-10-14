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
protected:
	virtual Curva* crear_curva_trayectoria ();
	virtual Curva* crear_curva_seccion ();
	virtual int obtener_pasos_trayectoria ();
	virtual int obtener_pasos_seccion ();
	virtual std::vector<glm::mat4> crear_transformaciones ();
	
	// temporal
	virtual Superficie* crear_superficie (myWindow* ventana);
};

#endif /* PISO_H_ */

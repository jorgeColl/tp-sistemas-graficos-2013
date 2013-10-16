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
	static const float LARGO;
	static const float ANCHO;
	static const float SEPARACION;
	static const float PERTURBACION;
	
public:
	Piso(myWindow* ventana);
	virtual ~Piso();
protected:
	virtual Curva* crear_curva_trayectoria ();
	virtual Curva* crear_curva_seccion ();
	virtual int obtener_pasos_trayectoria ();
	virtual int obtener_pasos_seccion ();
	virtual std::vector<glm::mat4> crear_transformaciones ();
};

#endif /* PISO_H_ */

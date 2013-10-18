/*
 * Planta.h
 *
 *  Created on: 10/10/2013
 *      Author: jorge
 */

#ifndef PLANTA_H_
#define PLANTA_H_

#include "figura.h"

// ************************** HOJAS DE PLANTA **************************
class HojaPlanta: public Figura {
public:
	HojaPlanta(myWindow* ventana);
	virtual ~HojaPlanta();
	virtual void renderizar(glm::mat4 model_matrix);
protected:
	virtual Curva* crear_curva_trayectoria ();
	virtual Curva* crear_curva_seccion ();
	virtual int obtener_pasos_trayectoria ();
	virtual int obtener_pasos_seccion ();
	virtual std::vector<glm::mat4> crear_transformaciones ();
};

// ****************************** PLANTA *******************************
class Planta: public Figura {
public:
	Planta(myWindow* ventana);
	virtual ~Planta();
	virtual void renderizar(glm::mat4 model_matrix);
protected:
	HojaPlanta hoja1;
	HojaPlanta hoja2;
	HojaPlanta hoja3;
	virtual Superficie* crear_superficie (myWindow* ventana) { return (new Superficie(ventana)); };
};


#endif /* PLANTA_H_ */

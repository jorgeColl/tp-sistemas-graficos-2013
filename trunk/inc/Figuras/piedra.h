/*
 * Piedra.h
 *
 *  Created on: 08/10/2013
 *      Author: jorge
 */

#ifndef PIEDRA_H_
#define PIEDRA_H_

#include "figura.h"
#include "FuncionCurvaBezier.h"

class Piedra: public Figura {
public:
	Piedra(myWindow* ventana);
	virtual ~Piedra();
	virtual void renderizar(glm::mat4 model_matrix);
protected:
	virtual Curva* crear_curva_trayectoria ();
	virtual Curva* crear_curva_seccion ();
	virtual int obtener_pasos_trayectoria ();
	virtual int obtener_pasos_seccion ();
	virtual std::vector<glm::mat4> crear_transformaciones ();
private:
	FuncionCurvaBezier crear_funcion ();
};

#endif /* PIEDRA_H_ */

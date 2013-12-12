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
#include <iostream>
#include <glm/glm.hpp>
#include "Animacion.h"
#include "Superficie.h"
#include "Grilla.h"
#include "Cubo.h"
#include "Esfera.h"
#include "SuperficieBarrido.h"
#include "Curva.h"
#include "CurvaBezier.h"
#include "CurvaBSpline.h"
#include "Circunferencia.h"
#include "Elipse.h"
#include "Parabola.h"
#include "FuncionCurvaBezier.h"
#include "FuncionSeno.h"
#include "Funcion.h"
#include "Helper.h"

class Figura {
protected:
	Superficie* mi_superficie;
	std::vector <Figura*> figuras_hijas;
	
	// temporal
	Superficie* mySphere;
	Superficie* myCube;
	
public:
	Figura (myWindow* ventana);
	virtual ~Figura();
	virtual void renderizar(glm::mat4 model_matrix);
	void agregar_figura_hija(Figura& fig);
	virtual void animar();
	
protected:
	void renderizar_figuras_hijas(glm::mat4 model_matrix);
	virtual Superficie* crear_superficie (myWindow* ventana);
	virtual Curva* crear_curva_trayectoria ();
	virtual Curva* crear_curva_seccion ();
	virtual int obtener_pasos_trayectoria () { return 0; };
	virtual int obtener_pasos_seccion () { return 0; };
	virtual std::vector<glm::mat4> crear_transformaciones ();
	virtual std::vector<glm::mat4> transformacion_parabolica ();
	
	virtual FuncionCurvaBezier crear_funcion ();
	virtual float obtener_coef_expansion();
	virtual float obtener_valor_inicial_funcion();
	virtual float obtener_valor_final_funcion();
};

#endif /* FIGURA_H_ */

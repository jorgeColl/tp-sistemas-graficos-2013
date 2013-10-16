/*
 * Pez.h
 *
 *  Created on: 12/10/2013
 *      Author: jorge
 */

#ifndef PEZ_H_
#define PEZ_H_
#include "CurvaBSpline.h"
#include "figura.h"

// ******************************* ALETA *******************************
class AletaPez: public Figura {
public:
	AletaPez(myWindow* ventana);
	~AletaPez();
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

// ******************************* COLA ********************************
class ColaPez: public Figura {
public:
	ColaPez(myWindow* ventana);
	~ColaPez();
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

// ******************************* TORSO *******************************
class TorsoPez: public Figura {
public:
	TorsoPez(myWindow* ventana);
	~TorsoPez();
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

// ******************************** PEZ ********************************
class Pez: public Figura {
protected:
	AletaPez aleta1;
	AletaPez aleta2;
	ColaPez cola;
	TorsoPez torso;
	CurvaBSpline* trayecto;
	float cont;
	glm::vec3 m_pos;
	float angX,angZ,angY,angXViejo,angZViejo,angYViejo;
public:
	Pez(myWindow* ventana);
	virtual ~Pez();
	virtual void renderizar(glm::mat4 model_matrix);
	virtual void set_trayecto (std::vector<glm::vec3> puntos);
	virtual void animar();
protected:
virtual Superficie* crear_superficie (myWindow* ventana) { return (new Superficie(ventana)); };
};

#endif /* PEZ_H_ */

/*
 * brazo_cangrejo.h
 *
 *  Created on: 20/09/2013
 *      Author: jorge
 */

#ifndef CANGREJO_H_
#define CANGREJO_H_

#include "figura.h"
#include <vector>
#include <iostream>

// ***************************** PATA MUSLO ****************************
// ********************** PRIMERA PARTE DE LA PATA *********************
class PataMusloCangrejo: public Figura {
public:
	PataMusloCangrejo(myWindow* ventana);
	~PataMusloCangrejo();
	virtual void renderizar(glm::mat4 model_matrix); // TEMPORAL!!
protected:
	virtual Curva* crear_curva_trayectoria ();
	virtual Curva* crear_curva_seccion ();
	virtual int obtener_pasos_trayectoria ();
	virtual int obtener_pasos_seccion ();
	virtual std::vector<glm::mat4> crear_transformaciones ();
};

// **************************** PATA GEMELO ****************************
// ********************** SEGUNDA PARTE DE LA PATA *********************
class PataGemeloCangrejo: public Figura {
public:
	PataGemeloCangrejo(myWindow* ventana);
	~PataGemeloCangrejo();
	virtual void renderizar(glm::mat4 model_matrix); // TEMPORAL!!
protected:
	virtual Curva* crear_curva_trayectoria ();
	virtual Curva* crear_curva_seccion ();
	virtual int obtener_pasos_trayectoria ();
	virtual int obtener_pasos_seccion ();
	virtual std::vector<glm::mat4> crear_transformaciones ();
};

// ****************************** PATA PIE *****************************
// ********************** TERCERA PARTE DE LA PATA *********************
class PataPieCangrejo: public Figura {
public:
	PataPieCangrejo(myWindow* ventana);
	~PataPieCangrejo();
	virtual void renderizar(glm::mat4 model_matrix); // TEMPORAL!!
protected:
	virtual Curva* crear_curva_trayectoria ();
	virtual Curva* crear_curva_seccion ();
	virtual int obtener_pasos_trayectoria ();
	virtual int obtener_pasos_seccion ();
	virtual std::vector<glm::mat4> crear_transformaciones ();
};

// **************************** PATA ENTERA ****************************
class PataCangrejo: public Figura {
	float ang_braz2_X;
	float ang_mano;
	
	PataMusloCangrejo muslo;
	PataGemeloCangrejo gemelo;
	PataPieCangrejo pie;
public:
	PataCangrejo(myWindow* ventana);
	~PataCangrejo();
	virtual void renderizar(glm::mat4 model_matrix);
protected:
	virtual Superficie* crear_superficie (myWindow* ventana) { return (new Superficie(ventana)); };
};

// ****************************** CABEZA *******************************
class CabezaCangrejo: public Figura {
public:
	CabezaCangrejo(myWindow* ventana);
	~CabezaCangrejo();
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

// ****************************** ANTEBRAZO ****************************
// *********************** PRIMERA PARTE DEL BRAZO *********************
class AntebrazoCangrejo: public Figura {
public:
	AntebrazoCangrejo(myWindow* ventana);
	~AntebrazoCangrejo();
	virtual void renderizar(glm::mat4 model_matrix); // TEMPORAL!!
protected:
	virtual Curva* crear_curva_trayectoria ();
	virtual Curva* crear_curva_seccion ();
	virtual int obtener_pasos_trayectoria ();
	virtual int obtener_pasos_seccion ();
	virtual std::vector<glm::mat4> crear_transformaciones ();
};

// **************************** BRAZO MEDIO ****************************
// *********************** SEGUNDA PARTE DEL BRAZO *********************
class BrazoMedioCangrejo: public Figura {
public:
	BrazoMedioCangrejo(myWindow* ventana);
	~BrazoMedioCangrejo();
	virtual void renderizar(glm::mat4 model_matrix); // TEMPORAL!!
protected:
	virtual Curva* crear_curva_trayectoria ();
	virtual Curva* crear_curva_seccion ();
	virtual int obtener_pasos_trayectoria ();
	virtual int obtener_pasos_seccion ();
	virtual std::vector<glm::mat4> crear_transformaciones ();
};

// ************************** TENAZA SUPERIOR **************************
// ****************** TERCERA PARTE SUPERIOR DEL BRAZO *****************
class TenazaSuperiorCangrejo: public Figura {
public:
	TenazaSuperiorCangrejo(myWindow* ventana);
	~TenazaSuperiorCangrejo();
	virtual void renderizar(glm::mat4 model_matrix); // TEMPORAL!!
protected:
	virtual Curva* crear_curva_trayectoria ();
	virtual Curva* crear_curva_seccion ();
	virtual int obtener_pasos_trayectoria ();
	virtual int obtener_pasos_seccion ();
	virtual std::vector<glm::mat4> crear_transformaciones ();
};

// ************************** TENAZA INFERIOR **************************
// ****************** TERCERA PARTE INFERIOR DEL BRAZO *****************
class TenazaInferiorCangrejo: public Figura {
public:
	TenazaInferiorCangrejo(myWindow* ventana);
	~TenazaInferiorCangrejo();
	virtual void renderizar(glm::mat4 model_matrix); // TEMPORAL!!
protected:
	virtual Curva* crear_curva_trayectoria ();
	virtual Curva* crear_curva_seccion ();
	virtual int obtener_pasos_trayectoria ();
	virtual int obtener_pasos_seccion ();
	virtual std::vector<glm::mat4> crear_transformaciones ();
};

// *************************** BRAZO ENTERO ****************************
class BrazoCangrejo : public Figura {
protected:
	// para manejo de brazo
	float ang_braz2_X;
	float ang_braz2_Z;

	float ang_dedos_X;
	float ang_mano;
	
	AntebrazoCangrejo antebrazo;
	BrazoMedioCangrejo brazoMedio;
	TenazaSuperiorCangrejo tenazaSuperior;
	TenazaInferiorCangrejo tenazaInferior;
public:
	BrazoCangrejo(myWindow* ventana);
	~BrazoCangrejo();
	virtual void renderizar(glm::mat4 model_matrix);
protected:
	virtual Superficie* crear_superficie (myWindow* ventana) { return (new Superficie(ventana)); };
};

// ******************************* TORSO *******************************
class TorsoCangrejo : public Figura {
public:
	TorsoCangrejo (myWindow* ventana);
	~TorsoCangrejo();
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

// ***************************** CANGREJO ******************************
class Cangrejo: public Figura {
protected:
	PataCangrejo pata1;
	PataCangrejo pata2;
	PataCangrejo pata3;
	PataCangrejo pata4;
	PataCangrejo pata5;
	PataCangrejo pata6;
	std::vector<PataCangrejo*> patas;
	CabezaCangrejo cabeza;
	TorsoCangrejo torso;
	BrazoCangrejo brazo1;
	BrazoCangrejo brazo2;
	myWindow* window;

	float ang_pata_X[6];
	float ang_pata_Z[6];
	bool patas_elevacion[6];
public:
	Cangrejo(myWindow* ventana);
	~Cangrejo();
	virtual void renderizar(glm::mat4 model_matrix);
	virtual void animar();
protected:
	virtual Superficie* crear_superficie (myWindow* ventana) { return (new Superficie(ventana)); };
};

#endif /* CANGREJO_H_ */

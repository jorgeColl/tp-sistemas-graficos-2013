/*
 * cangrejo.cpp
 *
 *  Created on: 22/09/2013
 *      Author: jorge
 */

#include "cangrejo.h"
#include <cstdio>
#include <iostream>

using namespace std;


// **************************** PATA ENTERA ****************************
PataCangrejo::PataCangrejo(myWindow* ventana) : Figura (ventana),
						muslo(ventana), gemelo(ventana), pie(ventana) {
	this->ang_braz2_X=-45;
	this->ang_mano=-45;
	this->mi_superficie = this->crear_superficie (ventana);
}
PataCangrejo::~PataCangrejo() { }

void PataCangrejo::renderizar(glm::mat4 model_matrix) {
		// primera parte de la pata
		this->muslo.renderizar(model_matrix);

		model_matrix = glm::translate(model_matrix, glm::vec3 (0.0f, 0.0f, 3.5f));
		model_matrix = glm::rotate(model_matrix, this->ang_braz2_X, glm::vec3 ( 1.0f,0.0f,0.0f));

		// segunda parte de la pata
		this->gemelo.renderizar(model_matrix);

		model_matrix= glm::translate(model_matrix, glm::vec3 (0.0f, 0.0f, 3.5f));
		model_matrix = glm::rotate(model_matrix, this->ang_mano, glm::vec3 (1.0f,0.0f,0.0f));

		// pie de la pata
		this->pie.renderizar(model_matrix);
}

// ***************************** PATA MUSLO ****************************
// ********************** PRIMERA PARTE DE LA PATA *********************
PataMusloCangrejo::PataMusloCangrejo (myWindow* ventana) : Figura (ventana) {
	this->mi_superficie = this->crear_superficie (ventana);
	this->mi_superficie->nombreTextura="cangrejoExtremidad.jpg";
	this->mi_superficie->nombreTexturaNormal="cangrejoExtremidadNormal.jpg";
}
PataMusloCangrejo::~PataMusloCangrejo() { }

Curva* PataMusloCangrejo::crear_curva_trayectoria () {
	std::vector<glm::vec3> control_trayectoria;
	
	control_trayectoria.push_back ( glm::vec3 ( 0.0, 0.0, 0.0) );
	control_trayectoria.push_back ( glm::vec3 ( 0.0, -0.85, 1.75) );
	control_trayectoria.push_back ( glm::vec3 ( 0.0, 0.1, 3.52) );
	return (new CurvaBezier (control_trayectoria, glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 0.0, 1.0)));
}
Curva* PataMusloCangrejo::crear_curva_seccion () {
	return (new Circunferencia(glm::vec3(0.0,0.0,0.0),1.0));
}
int PataMusloCangrejo::obtener_pasos_trayectoria () {
	return 50;
}
int PataMusloCangrejo::obtener_pasos_seccion () {
	return 100;
}
FuncionCurvaBezier PataMusloCangrejo::crear_funcion () {
	std::vector<glm::vec3> puntos;
	puntos.push_back ( glm::vec3 (0.0, 0.65, 0.0) );
	puntos.push_back ( glm::vec3 (0.03 * this->obtener_pasos_trayectoria(), 1.7 * 1.0, 0.0) );
	puntos.push_back ( glm::vec3 (0.5 * this->obtener_pasos_trayectoria(), 1.0 * 1.0, 0.0) );
	puntos.push_back ( glm::vec3 (0.97 * this->obtener_pasos_trayectoria(), 1.7 * 1.0, 0.0) );
	puntos.push_back ( glm::vec3 (this->obtener_pasos_trayectoria(), 0.7, 0.0) );
	return (FuncionCurvaBezier(puntos));
}

// **************************** PATA GEMELO ****************************
// ********************** SEGUNDA PARTE DE LA PATA *********************
PataGemeloCangrejo::PataGemeloCangrejo (myWindow* ventana) : Figura (ventana) {
	this->mi_superficie = this->crear_superficie (ventana);
	this->mi_superficie->nombreTextura="cangrejoExtremidad.jpg";
	this->mi_superficie->nombreTexturaNormal="cangrejoExtremidadNormal.jpg";
}
PataGemeloCangrejo::~PataGemeloCangrejo() { }

Curva* PataGemeloCangrejo::crear_curva_trayectoria () {
	std::vector<glm::vec3> control_trayectoria;
	
	control_trayectoria.push_back ( glm::vec3 ( 0.0, 0.0, 0.0) );
	control_trayectoria.push_back ( glm::vec3 ( 0.0, -0.45, 1.75) );
	control_trayectoria.push_back ( glm::vec3 ( 0.0, 0.0, 3.58) );
	return (new CurvaBezier (control_trayectoria, glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 0.0, 1.0)));
}
Curva* PataGemeloCangrejo::crear_curva_seccion () {
	return (new Circunferencia(glm::vec3(0.0,0.0,0.0),0.70));
}
int PataGemeloCangrejo::obtener_pasos_trayectoria () {
	return 50;
}
int PataGemeloCangrejo::obtener_pasos_seccion () {
	return 100;
}
FuncionCurvaBezier PataGemeloCangrejo::crear_funcion () {
	std::vector<glm::vec3> puntos;
	puntos.push_back ( glm::vec3 (0.0, 0.97, 0.0) );
	puntos.push_back ( glm::vec3 (0.03 * this->obtener_pasos_trayectoria(), 2.0 * 1.0, 0.0) );
	puntos.push_back ( glm::vec3 (0.5 * this->obtener_pasos_trayectoria(), 1.0 * 1.0, 0.0) );
	puntos.push_back ( glm::vec3 (0.97 * this->obtener_pasos_trayectoria(), 2.0 * 1.0, 0.0) );
	puntos.push_back ( glm::vec3 (this->obtener_pasos_trayectoria(), 0.5, 0.0) );
	return (FuncionCurvaBezier(puntos));
}

// ****************************** PATA PIE *****************************
// ********************** TERCERA PARTE DE LA PATA *********************
PataPieCangrejo::PataPieCangrejo (myWindow* ventana) : Figura (ventana) {
	this->mi_superficie = this->crear_superficie (ventana);
	this->mi_superficie->nombreTextura="cangrejoExtremidad.jpg";
	this->mi_superficie->nombreTexturaNormal="cangrejoExtremidadNormal.jpg";
}
PataPieCangrejo::~PataPieCangrejo() { }

Curva* PataPieCangrejo::crear_curva_trayectoria () {
	std::vector<glm::vec3> control_trayectoria;
	
	control_trayectoria.push_back ( glm::vec3 ( 0.0, 0.1, -0.1) );
	control_trayectoria.push_back ( glm::vec3 ( 0.0, -0.3, 1.75) );
	control_trayectoria.push_back ( glm::vec3 ( 0.0, 0.0, 3.5) );
	return (new CurvaBezier (control_trayectoria, glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 0.0, 1.0)));
}
Curva* PataPieCangrejo::crear_curva_seccion () {
	return (new Circunferencia(glm::vec3(0.0,0.0,0.0),0.40));
}
int PataPieCangrejo::obtener_pasos_trayectoria () {
	return 50;
}
int PataPieCangrejo::obtener_pasos_seccion () {
	return 100;
}
FuncionCurvaBezier PataPieCangrejo::crear_funcion () {
	std::vector<glm::vec3> puntos;
	puntos.push_back ( glm::vec3 (0.0, 0.98, 0.0) );
	puntos.push_back ( glm::vec3 (0.03 * this->obtener_pasos_trayectoria(), 3.0, 0.0) );
	puntos.push_back ( glm::vec3 (0.5 * this->obtener_pasos_trayectoria(), 1.0, 0.0) );
	puntos.push_back ( glm::vec3 (0.97 * this->obtener_pasos_trayectoria(), 0.55, 0.0) );
	puntos.push_back ( glm::vec3 (this->obtener_pasos_trayectoria(), 0.0, 0.0) );
	return (FuncionCurvaBezier(puntos));
}

// ****************************** CABEZA *******************************
CabezaCangrejo::CabezaCangrejo(myWindow* ventana) : Figura (ventana),
						antenaIzquierda(ventana), antenaDerecha(ventana) {
	
	//this->mi_superficie = this->crear_superficie (ventana);
}
CabezaCangrejo::~CabezaCangrejo() { }

void CabezaCangrejo::renderizar(glm::mat4 model_matrix) {
	glm::mat4 antDer = glm::translate(model_matrix, glm::vec3 (-0.38f, 0.8, 0.17));
	glm::mat4 antIzq = glm::translate(model_matrix, glm::vec3 ( 0.38f, 0.8, 0.17));
	this->antenaDerecha.renderizar(antDer);
	this->antenaIzquierda.renderizar(antIzq);
}

// ****************************** ANTENA *******************************
// ************************ PARTE DE LA CABEZA *************************
AntenaCangrejo::AntenaCangrejo(myWindow* ventana) : Figura (ventana) {
	this->mi_superficie = this->crear_superficie (ventana);
	this->mi_superficie->nombreTextura="cangrejoAntena.jpg";
	this->mi_superficie->nombreTexturaNormal="cangrejoExtremidadNormal.jpg";
}
AntenaCangrejo::~AntenaCangrejo() { }

Curva* AntenaCangrejo::crear_curva_trayectoria () {
	std::vector<glm::vec3> control_trayectoria;
	
	control_trayectoria.push_back ( glm::vec3 ( 0.0, 0.0, 0.0) );
	control_trayectoria.push_back ( glm::vec3 ( 0.0, 0.0, 0.7) );
	return (new CurvaBezier (control_trayectoria, glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 0.0, 1.0)));
}
Curva* AntenaCangrejo::crear_curva_seccion () {
	return (new Circunferencia(glm::vec3(0.0,0.0,0.0),0.10));
}
int AntenaCangrejo::obtener_pasos_trayectoria () {
	return 50;
}
int AntenaCangrejo::obtener_pasos_seccion () {
	return 100;
}
FuncionCurvaBezier AntenaCangrejo::crear_funcion () {
	std::vector<glm::vec3> puntos;
	int pasosSegundoTramo = (this->obtener_pasos_trayectoria() / 2);
	puntos.push_back ( glm::vec3 (0.0, 1.0, 0.0) );
	puntos.push_back ( glm::vec3 (0.01 * pasosSegundoTramo, 5.0, 0.0) );
	puntos.push_back ( glm::vec3 (0.5 * pasosSegundoTramo, 3.0, 0.0) );
	puntos.push_back ( glm::vec3 (0.99 * pasosSegundoTramo, 5.0, 0.0) );
	puntos.push_back ( glm::vec3 (pasosSegundoTramo, 0.0, 0.0) );
	return (FuncionCurvaBezier(puntos));
}
std::vector<glm::mat4> AntenaCangrejo::crear_transformaciones () {
	std::vector<glm::mat4> transformaciones;
	int pasosPrimerTramo = (this->obtener_pasos_trayectoria() / 2);
	for (int i = 0 ; i < pasosPrimerTramo ; i++) {
		transformaciones.push_back(glm::mat4 (1.0f));
	}
	
	FuncionCurvaBezier funcion = this->crear_funcion();
	for (int j = pasosPrimerTramo ; j <= this->obtener_pasos_trayectoria() ; j++) {
		float coef = 0.0;
		coef = funcion.evaluar_en ((j - pasosPrimerTramo) * 1.0);
		if (coef < 0.0) coef *= (-1);
		glm::mat4 matriz = glm::scale ( glm::mat4 (1.0f) , glm::vec3 (coef, coef, coef));
		transformaciones.push_back(matriz);
	}
	return transformaciones;
}

// *************************** BRAZO ENTERO ****************************
BrazoCangrejo::BrazoCangrejo(myWindow* ventana) : Figura (ventana),
								antebrazo(ventana), brazoMedio(ventana),
								tenazaSuperior(ventana), tenazaInferior(ventana) {
	ang_braz2_X=0;
	ang_braz2_Z=0;
	ang_mano=0;
	ang_dedos_X=0;
	
	this->mi_superficie = this->crear_superficie (ventana);
}
BrazoCangrejo::~BrazoCangrejo() { }

void BrazoCangrejo::renderizar(glm::mat4 model_matrix) {
	// primera parte del brazo
	this->antebrazo.renderizar(model_matrix);

	// segunda parte del brazo
	model_matrix = glm::translate(model_matrix, glm::vec3 (0.0f, 0.15f, 3.27f));
	model_matrix = glm::rotate(model_matrix, this->ang_braz2_X, glm::vec3 (1.0f,0.0f,0.0f));
	model_matrix = glm::rotate(model_matrix, this->ang_braz2_Z, glm::vec3 (0.0f,0.0f,1.0f));
	this->brazoMedio.renderizar(model_matrix);
	
	// pinzas
	model_matrix= glm::translate(model_matrix, glm::vec3 (0.0f, 0.0f, 3.5f));
	model_matrix = glm::rotate(model_matrix, this->ang_mano, glm::vec3 (0.0f, 0.0f,1.0f));

	// pinza1
	glm::mat4 rot3 = glm::rotate(glm::mat4 (1.0f),this->ang_dedos_X , glm::vec3 (1.0f, 0.0f,0.0f));
	this->tenazaSuperior.renderizar( model_matrix * rot3 );

	// pinza2
	glm::mat4 rot4 = glm::rotate(glm::mat4 (1.0f), -this->ang_dedos_X, glm::vec3 (1.0f, 0.0f, 0.0f));
	this->tenazaInferior.renderizar( model_matrix * rot4 );
}
void BrazoCangrejo::set_angulos ( float ang_braz2_X, float ang_braz2_Z, float ang_mano, float ang_dedos_X ) {
	this->ang_braz2_X = ang_braz2_X;
	this->ang_braz2_Z = ang_braz2_Z;
	this->ang_mano = ang_mano;
	this->ang_dedos_X = ang_dedos_X;
}
// ****************************** ANTEBRAZO ****************************
// *********************** PRIMERA PARTE DEL BRAZO *********************
AntebrazoCangrejo::AntebrazoCangrejo (myWindow* ventana) : Figura (ventana) {
	this->mi_superficie = this->crear_superficie (ventana);
	this->mi_superficie->nombreTextura="cangrejoExtremidad.jpg";
	this->mi_superficie->nombreTexturaNormal="cangrejoExtremidadNormal.jpg";
}
AntebrazoCangrejo::~AntebrazoCangrejo() { }

Curva* AntebrazoCangrejo::crear_curva_trayectoria () {
	std::vector<glm::vec3> control_trayectoria;
	
	control_trayectoria.push_back ( glm::vec3 ( 0.0, 0.0, 0.0) );
	control_trayectoria.push_back ( glm::vec3 ( -0.1, 0.0, 1.75) );
	control_trayectoria.push_back ( glm::vec3 ( 0.0, 0.0, 3.5) );
	return (new CurvaBezier (control_trayectoria, glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 0.0, 1.0)));
}
Curva* AntebrazoCangrejo::crear_curva_seccion () {
	return (new Circunferencia(glm::vec3(0.0,0.0,0.0),1.0));
}
int AntebrazoCangrejo::obtener_pasos_trayectoria () {
	return 50;
}
int AntebrazoCangrejo::obtener_pasos_seccion () {
	return 100;
}
FuncionCurvaBezier AntebrazoCangrejo::crear_funcion () {
	std::vector<glm::vec3> puntos;
	puntos.push_back ( glm::vec3 (0.0, 0.4, 0.0) );
	puntos.push_back ( glm::vec3 (0.03 * this->obtener_pasos_trayectoria(), 1.3, 0.0) );
	puntos.push_back ( glm::vec3 (0.5 * this->obtener_pasos_trayectoria(), 1.0, 0.0) );
	puntos.push_back ( glm::vec3 (0.97 * this->obtener_pasos_trayectoria(), 1.3, 0.0) );
	puntos.push_back ( glm::vec3 (this->obtener_pasos_trayectoria(), 0.4, 0.0) );
	return (FuncionCurvaBezier(puntos));
}


// **************************** BRAZO MEDIO ****************************
// *********************** SEGUNDA PARTE DEL BRAZO *********************
BrazoMedioCangrejo::BrazoMedioCangrejo (myWindow* ventana) : Figura (ventana) {
	this->mi_superficie = this->crear_superficie (ventana);
	this->mi_superficie->nombreTextura="cangrejoExtremidad.jpg";
	this->mi_superficie->nombreTexturaNormal="cangrejoExtremidadNormal.jpg";
}
BrazoMedioCangrejo::~BrazoMedioCangrejo() { }

Curva* BrazoMedioCangrejo::crear_curva_trayectoria () {
	std::vector<glm::vec3> control_trayectoria;
	
	control_trayectoria.push_back ( glm::vec3 ( 0.0, 0.0, 0.0) );
	control_trayectoria.push_back ( glm::vec3 ( -0.1, 0.0, 1.75) );
	control_trayectoria.push_back ( glm::vec3 ( 0.0, 0.0, 3.52) );
	return (new CurvaBezier (control_trayectoria, glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 0.0, 1.0)));
}
Curva* BrazoMedioCangrejo::crear_curva_seccion () {
	return (new Circunferencia(glm::vec3(0.0,0.0,0.0),1.0));
}
int BrazoMedioCangrejo::obtener_pasos_trayectoria () {
	return 50;
}
int BrazoMedioCangrejo::obtener_pasos_seccion () {
	return 100;
}
float BrazoMedioCangrejo::obtener_valor_inicial_funcion() {
	return 0.4;
}
float BrazoMedioCangrejo::obtener_valor_final_funcion() {
	return 0.3;
}

// ************************** TENAZA SUPERIOR **************************
// ****************** TERCERA PARTE SUPERIOR DEL BRAZO *****************
TenazaSuperiorCangrejo::TenazaSuperiorCangrejo (myWindow* ventana) : Figura (ventana) {
	this->mi_superficie = this->crear_superficie (ventana);
	this->mi_superficie->nombreTextura="cangrejoExtremidad.jpg";
	this->mi_superficie->nombreTexturaNormal="cangrejoExtremidadNormal.jpg";
}
TenazaSuperiorCangrejo::~TenazaSuperiorCangrejo() { }

void TenazaSuperiorCangrejo::renderizar(glm::mat4 model_matrix) {
	model_matrix = glm::scale (model_matrix, glm::vec3 (0.65, 1.0, 1.0));
	Figura::renderizar(model_matrix);
}
Curva* TenazaSuperiorCangrejo::crear_curva_trayectoria () {
	std::vector<glm::vec3> control_trayectoria;
	
	control_trayectoria.push_back ( glm::vec3 ( 0.0, 0.0, 0.0) );
	control_trayectoria.push_back ( glm::vec3 ( 0.0, -0.6, 0.9) );
	control_trayectoria.push_back ( glm::vec3 ( 0.0, 0.0, 3.0) );
	return (new CurvaBezier (control_trayectoria, glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 0.0, 1.0)));
}
Curva* TenazaSuperiorCangrejo::crear_curva_seccion () {
	std::vector<glm::vec3> puntosAux;
	float distancia = 0.4;
	puntosAux.push_back ( glm::vec3 ( -distancia * 0.75, 0.0, 0.0) );
	puntosAux.push_back ( glm::vec3 ( 0.0, -distancia, 0.0) );
	puntosAux.push_back ( glm::vec3 (  distancia * 0.75, 0.0, 0.0) );
	puntosAux.push_back ( glm::vec3 ( 0.0, -distancia / 8, 0.0) );
	puntosAux.push_back ( glm::vec3 ( -distancia * 0.75, 0.0, 0.0) ); // repito el primero para cerrar la tenaza
	unsigned int cantidades[] = { 3 , 1 , 3 , 1 , 3 };
	
	std::vector<glm::vec3> control_seccion;
	for (unsigned int i = 0 ; i < puntosAux.size() ; i++) {
		for (unsigned int j = 0 ; j < cantidades[i] ; j++) {
			control_seccion.push_back (puntosAux.at(i));
		}
	}
	return (new CurvaBSpline (control_seccion, glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 0.0, 1.0)));
}
int TenazaSuperiorCangrejo::obtener_pasos_trayectoria () {
	return 50;
}
int TenazaSuperiorCangrejo::obtener_pasos_seccion () {
	return 100;
}
FuncionCurvaBezier TenazaSuperiorCangrejo::crear_funcion () {
	std::vector<glm::vec3> puntos;
	puntos.push_back ( glm::vec3 (0.0, 1.0, 0.0) );
	puntos.push_back ( glm::vec3 (0.3 * this->obtener_pasos_trayectoria(), 5.0 , 0.0) );
	puntos.push_back ( glm::vec3 (this->obtener_pasos_trayectoria(), 0.0, 0.0) );
	return (FuncionCurvaBezier(puntos));
}

// ************************** TENAZA INFERIOR **************************
// ****************** TERCERA PARTE INFERIOR DEL BRAZO *****************
TenazaInferiorCangrejo::TenazaInferiorCangrejo (myWindow* ventana) : Figura (ventana) {
	this->mi_superficie = this->crear_superficie (ventana);
	this->mi_superficie->nombreTextura="cangrejoExtremidad.jpg";
	this->mi_superficie->nombreTexturaNormal="cangrejoExtremidadNormal.jpg";
}
TenazaInferiorCangrejo::~TenazaInferiorCangrejo() { }

Curva* TenazaInferiorCangrejo::crear_curva_trayectoria () {
	std::vector<glm::vec3> control_trayectoria;
	
	control_trayectoria.push_back ( glm::vec3 ( 0.0, 0.0, 0.0) );
	control_trayectoria.push_back ( glm::vec3 ( 0.0, 0.5, 1.2) );
	control_trayectoria.push_back ( glm::vec3 ( 0.0, 0.0, 2.0) );
	return (new CurvaBezier (control_trayectoria, glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 0.0, 1.0)));
}
Curva* TenazaInferiorCangrejo::crear_curva_seccion () {
	std::vector<glm::vec3> puntosAux;
	float distancia = 0.4;
	puntosAux.push_back ( glm::vec3 ( distancia / 2, 0.0, 0.0) );
	puntosAux.push_back ( glm::vec3 ( 0.0, distancia, 0.0) );
	puntosAux.push_back ( glm::vec3 ( -distancia / 2, 0.0, 0.0) );
	puntosAux.push_back ( glm::vec3 ( 0.0, distancia / 5, 0.0) );
	puntosAux.push_back ( glm::vec3 ( distancia / 2, 0.0, 0.0) ); // repito el primero para cerrar la tenaza
	unsigned int cantidades[] = { 3 , 1 , 3 , 1 , 3 };
	
	std::vector<glm::vec3> control_seccion;
	for (unsigned int i = 0 ; i < puntosAux.size() ; i++) {
		for (unsigned int j = 0 ; j < cantidades[i] ; j++) {
			control_seccion.push_back (puntosAux.at(i));
		}
	}
	return (new CurvaBSpline (control_seccion, glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 0.0, 1.0)));
}
int TenazaInferiorCangrejo::obtener_pasos_trayectoria () {
	return 50;
}
int TenazaInferiorCangrejo::obtener_pasos_seccion () {
	return 100;
}
FuncionCurvaBezier TenazaInferiorCangrejo::crear_funcion () {
	std::vector<glm::vec3> puntos;
	puntos.push_back ( glm::vec3 (0.0, 1.0, 0.0) );
	puntos.push_back ( glm::vec3 (0.85 * this->obtener_pasos_trayectoria(), 3.0 , 0.0) );
	puntos.push_back ( glm::vec3 (this->obtener_pasos_trayectoria(), 0.0, 0.0) );
	return (FuncionCurvaBezier(puntos));
}

// ******************************* TORSO *******************************
TorsoCangrejo::TorsoCangrejo(myWindow* ventana) : Figura (ventana) {
	this->mi_superficie = this->crear_superficie (ventana);
	this->mi_superficie->nombreTextura="cangrejoTorso.jpg";
	this->mi_superficie->nombreTexturaNormal="cangrejoTorsoNormal.jpg";
}
TorsoCangrejo::~TorsoCangrejo() { }

Curva* TorsoCangrejo::crear_curva_trayectoria () {
	std::vector<glm::vec3> control_trayectoria;
	
	control_trayectoria.push_back ( glm::vec3 ( 0.0, -1.2, 0.0) );
	control_trayectoria.push_back ( glm::vec3 ( 0.0, 1.15, 0.0) );
	return (new CurvaBezier (control_trayectoria, glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 0.0, 1.0)));
}
Curva* TorsoCangrejo::crear_curva_seccion () {
	return (new Elipse(glm::vec3(0.0,0.0,0.0), 0.50, 0.25));
}

int TorsoCangrejo::obtener_pasos_trayectoria () {
	return 85;
}
int TorsoCangrejo::obtener_pasos_seccion () {
	return 150;
}
FuncionCurvaBezier TorsoCangrejo::crear_funcion () {
	std::vector<glm::vec3> puntos;
	puntos.push_back ( glm::vec3 (0.0, 0.0, 0.0) );
	puntos.push_back ( glm::vec3 (0.01 * this->obtener_pasos_trayectoria(), 4.0, 0.0) );
	puntos.push_back ( glm::vec3 (0.50 * this->obtener_pasos_trayectoria(), 0.85, 0.0) );
	puntos.push_back ( glm::vec3 (0.99 * this->obtener_pasos_trayectoria(), 4.75, 0.0) );
	puntos.push_back ( glm::vec3 (this->obtener_pasos_trayectoria(), 0.0, 0.0) );
	return (FuncionCurvaBezier(puntos));
}

// ***************************** CANGREJO ******************************
Cangrejo::Cangrejo(myWindow* ventana) : Figura (ventana),
		pata1(ventana), pata2(ventana), pata3(ventana), pata4(ventana), pata5(
				ventana), pata6(ventana), cabeza(ventana), torso(ventana), brazo1(
				ventana), brazo2(ventana) {

	this->patas.push_back(&pata1);
	this->patas.push_back(&pata2);
	this->patas.push_back(&pata3);
	this->patas.push_back(&pata4);
	this->patas.push_back(&pata5);
	this->patas.push_back(&pata6);

	this->window=NULL;

	ang_pata_X[0]=-95;
	ang_pata_X[1]=-45;
	ang_pata_X[2]=-95;
	ang_pata_X[3]=-95;
	ang_pata_X[4]=-45;
	ang_pata_X[5]=-95;

	ang_pata_Z[0] = 90;
	ang_pata_Z[1] = 90;
	ang_pata_Z[2] = 90;
	ang_pata_Z[3] = -90;
	ang_pata_Z[4] = -90;
	ang_pata_Z[5] = -90;

	patas_elevacion[0] = false;
	patas_elevacion[1] = false;
	patas_elevacion[2] = false;
	patas_elevacion[3] = false;
	patas_elevacion[4] = false;
	patas_elevacion[5] = false;

	brazo1.set_angulos(70,45,130,0);
	brazo2.set_angulos(70,-45,-130,0);

	vuelta_cangrejo = false;
	m_pos = glm::vec3(0, 0, 0);

	this->mi_superficie = this->crear_superficie(ventana);
}
Cangrejo::~Cangrejo() {
}
void Cangrejo::renderizar(glm::mat4 model_matrix) {
	model_matrix = glm::translate(model_matrix, m_pos);

	this->torso.renderizar(model_matrix);
	this->cabeza.renderizar(model_matrix);

	model_matrix = glm::scale(model_matrix, glm::vec3 (0.27f,0.27f,0.27f));

	float ang_braz1_X = -100;
	float ang_braz1_Z = -70;
	glm::mat4 m_brazo1  = glm::translate(model_matrix , glm::vec3 (2.0f, 2.5f, 0.2f));
	m_brazo1  = glm::rotate(m_brazo1 , ang_braz1_Z, glm::vec3(0.0f, 0.0f, 1.0f));
	m_brazo1  = glm::rotate(m_brazo1 , ang_braz1_X, glm::vec3(1.0f, 0.0f, 0.0f));

	this->brazo1.renderizar(m_brazo1);

	float ang_braz2_X = -100;
	float ang_braz2_Z = 70;
	glm::mat4 m_brazo2  = glm::translate(model_matrix , glm::vec3 (-2.0f, 2.5f, 0.2f));
	m_brazo2  = glm::rotate(m_brazo2 , ang_braz2_Z, glm::vec3(0.0f, 0.0f, 1.0f));
	m_brazo2  = glm::rotate(m_brazo2 , ang_braz2_X, glm::vec3(1.0f, 0.0f, 0.0f));
	this->brazo2.renderizar(m_brazo2);

	// Achico un poco para q las patas sean mas chicas que los brazos
	model_matrix = glm::scale(model_matrix, glm::vec3 (0.77f,0.77f,0.77f));

	// Dibujo las patas
	glm::mat4 m_pata;
	for (int i=0;i<6;++i) {
		if(i<3){
			m_pata = glm::translate(model_matrix , glm::vec3 (-3.2f+(0.8*i) , 0.8f - (2*i), 0.0f));
		}else{
			m_pata = glm::translate(model_matrix , glm::vec3 (3.2f-0.8*(i-3), 0.8f - (2*(i-3)), 0.0f));
		}
		m_pata  = glm::rotate(m_pata , ang_pata_Z[i], glm::vec3(0.0f, 0.0f, 1.0f));
		m_pata  = glm::rotate(m_pata , ang_pata_X[i], glm::vec3(1.0f, 0.0f, 0.0f));
		this->patas[i]->renderizar(m_pata);
	}
}
void Cangrejo::animar() {
	for (unsigned int i=0;i<6;++i) {
		if ( patas_elevacion[i] == true ) {
			ang_pata_X[i]+=1;
			if ( ang_pata_X[i]>=-45 ) {
				patas_elevacion[i]=false;
			}
		}

		if ( patas_elevacion[i] == false ) {
			ang_pata_X[i]-=1;
			if ( ang_pata_X[i]<=-90 ){
				patas_elevacion[i]=true;
			}
		}
	}
	// translacion de cangrejo
	if (vuelta_cangrejo == true) {
		m_pos.x -= 0.1f;
		if (m_pos.x <= -10.0f) {
			vuelta_cangrejo = false;
		}
	} else {
		m_pos.x += 0.1f;
		if (m_pos.x >= 10.0f) {
			vuelta_cangrejo = true;
		}
	}
}

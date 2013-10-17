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
CabezaCangrejo::CabezaCangrejo(myWindow* ventana) : Figura (ventana) {
	this->mi_superficie = this->crear_superficie (ventana);
}
CabezaCangrejo::~CabezaCangrejo() { }

void CabezaCangrejo::renderizar(glm::mat4 model_matrix) {
	glm::vec3 translado(0, 1.2, 0);
	model_matrix = glm::translate(model_matrix, translado);

	glm::vec3 escala(0.5, 0.5, 0.5);
	model_matrix = glm::scale(model_matrix, escala);
	Figura::renderizar(model_matrix);
}

// PARA HACER !!!
Curva* CabezaCangrejo::crear_curva_trayectoria () {
	return (new Curva(glm::vec3(0.0,0.0,0.0),glm::vec3(0.0,0.0,1.0)));
}
Curva* CabezaCangrejo::crear_curva_seccion () {
	return (new Curva(glm::vec3(0.0,0.0,0.0),glm::vec3(0.0,0.0,1.0)));
}
int CabezaCangrejo::obtener_pasos_trayectoria () {
	return 500;
}
int CabezaCangrejo::obtener_pasos_seccion () {
	return 500;
}
std::vector<glm::mat4> CabezaCangrejo::crear_transformaciones () {
	return (std::vector<glm::mat4>());
}

// TEMPORAL!!!
Superficie* CabezaCangrejo::crear_superficie (myWindow* ventana) {
	return (new Esfera (ventana, 1.0, 32, 32));
}

// *************************** BRAZO ENTERO ****************************
BrazoCangrejo::BrazoCangrejo(myWindow* ventana) : Figura (ventana),
								antebrazo(ventana), brazoMedio(ventana),
								tenazaSuperior(ventana), tenazaInferior(ventana) {
	ang_braz2_X=0;
	ang_braz2_Z=0;

	ang_mano=0;
	ang_dedos_X=20;
	
	this->mi_superficie = this->crear_superficie (ventana);
}
BrazoCangrejo::~BrazoCangrejo() { }

void BrazoCangrejo::renderizar(glm::mat4 model_matrix) {
	// primera parte del brazo
	this->antebrazo.renderizar(model_matrix);

	model_matrix = glm::translate(model_matrix, glm::vec3 (0.0f, 0.0f, 3.5f));
	model_matrix = glm::rotate(model_matrix, this->ang_braz2_X, glm::vec3 (1.0f,0.0f,0.0f));
	model_matrix = glm::rotate(model_matrix, this->ang_braz2_Z, glm::vec3 ( 0.0f,0.0f,1.0f));

	// segunda parte del brazo
	this->brazoMedio.renderizar(model_matrix);

	model_matrix= glm::translate(model_matrix, glm::vec3 (0.0f, 0.0f, 3.5f));
	model_matrix = glm::rotate(model_matrix, this->ang_dedos_X, glm::vec3 (1.0f, 0.0f,0.0f));

	// pinza1
	glm::mat4 rot3 = glm::rotate(glm::mat4 (1.0f), this->ang_mano, glm::vec3 (0.0f, 0.0f,1.0f));
	this->tenazaSuperior.renderizar( model_matrix * rot3 );

	// pinza2
	glm::mat4 rot4 = glm::rotate(glm::mat4 (1.0f), -this->ang_dedos_X, glm::vec3 (1.0f, 0.0f, 0.0f));
	this->tenazaInferior.renderizar( model_matrix * rot4 );
}

// ****************************** ANTEBRAZO ****************************
// *********************** PRIMERA PARTE DEL BRAZO *********************
AntebrazoCangrejo::AntebrazoCangrejo (myWindow* ventana) : Figura (ventana) {
	this->mi_superficie = this->crear_superficie (ventana);
}
AntebrazoCangrejo::~AntebrazoCangrejo() { }

// PARA HACER !!!
Curva* AntebrazoCangrejo::crear_curva_trayectoria () {
	return (new Curva(glm::vec3(0.0,0.0,0.0),glm::vec3(0.0,0.0,1.0)));
}
Curva* AntebrazoCangrejo::crear_curva_seccion () {
	return (new Curva(glm::vec3(0.0,0.0,0.0),glm::vec3(0.0,0.0,1.0)));
}
int AntebrazoCangrejo::obtener_pasos_trayectoria () {
	return 500;
}
int AntebrazoCangrejo::obtener_pasos_seccion () {
	return 500;
}
std::vector<glm::mat4> AntebrazoCangrejo::crear_transformaciones () {
	return (std::vector<glm::mat4>());
}

// TEMPORAL !!
void AntebrazoCangrejo::renderizar(glm::mat4 model_matrix) {
	this->renderArm(model_matrix);
}

// **************************** BRAZO MEDIO ****************************
// *********************** SEGUNDA PARTE DEL BRAZO *********************
BrazoMedioCangrejo::BrazoMedioCangrejo (myWindow* ventana) : Figura (ventana) {
	this->mi_superficie = this->crear_superficie (ventana);
}
BrazoMedioCangrejo::~BrazoMedioCangrejo() { }

// PARA HACER !!!
Curva* BrazoMedioCangrejo::crear_curva_trayectoria () {
	return (new Curva(glm::vec3(0.0,0.0,0.0),glm::vec3(0.0,0.0,1.0)));
}
Curva* BrazoMedioCangrejo::crear_curva_seccion () {
	return (new Curva(glm::vec3(0.0,0.0,0.0),glm::vec3(0.0,0.0,1.0)));
}
int BrazoMedioCangrejo::obtener_pasos_trayectoria () {
	return 500;
}
int BrazoMedioCangrejo::obtener_pasos_seccion () {
	return 500;
}
std::vector<glm::mat4> BrazoMedioCangrejo::crear_transformaciones () {
	return (std::vector<glm::mat4>());
}

// TEMPORAL !!
void BrazoMedioCangrejo::renderizar(glm::mat4 model_matrix) {
	this->renderArm(model_matrix);
}

// ************************** TENAZA SUPERIOR **************************
// ****************** TERCERA PARTE SUPERIOR DEL BRAZO *****************
TenazaSuperiorCangrejo::TenazaSuperiorCangrejo (myWindow* ventana) : Figura (ventana) {
	this->mi_superficie = this->crear_superficie (ventana);
}
TenazaSuperiorCangrejo::~TenazaSuperiorCangrejo() { }

// PARA HACER !!!
Curva* TenazaSuperiorCangrejo::crear_curva_trayectoria () {
	return (new Curva(glm::vec3(0.0,0.0,0.0),glm::vec3(0.0,0.0,1.0)));
}
Curva* TenazaSuperiorCangrejo::crear_curva_seccion () {
	return (new Curva(glm::vec3(0.0,0.0,0.0),glm::vec3(0.0,0.0,1.0)));
}
int TenazaSuperiorCangrejo::obtener_pasos_trayectoria () {
	return 500;
}
int TenazaSuperiorCangrejo::obtener_pasos_seccion () {
	return 500;
}
std::vector<glm::mat4> TenazaSuperiorCangrejo::crear_transformaciones () {
	return (std::vector<glm::mat4>());
}

// TEMPORAL !!
void TenazaSuperiorCangrejo::renderizar(glm::mat4 model_matrix) {
	this->renderArm(model_matrix);
}

// ************************** TENAZA INFERIOR **************************
// ****************** TERCERA PARTE INFERIOR DEL BRAZO *****************
TenazaInferiorCangrejo::TenazaInferiorCangrejo (myWindow* ventana) : Figura (ventana) {
	this->mi_superficie = this->crear_superficie (ventana);
}
TenazaInferiorCangrejo::~TenazaInferiorCangrejo() { }

// PARA HACER !!!
Curva* TenazaInferiorCangrejo::crear_curva_trayectoria () {
	return (new Curva(glm::vec3(0.0,0.0,0.0),glm::vec3(0.0,0.0,1.0)));
}
Curva* TenazaInferiorCangrejo::crear_curva_seccion () {
	return (new Curva(glm::vec3(0.0,0.0,0.0),glm::vec3(0.0,0.0,1.0)));
}
int TenazaInferiorCangrejo::obtener_pasos_trayectoria () {
	return 500;
}
int TenazaInferiorCangrejo::obtener_pasos_seccion () {
	return 500;
}
std::vector<glm::mat4> TenazaInferiorCangrejo::crear_transformaciones () {
	return (std::vector<glm::mat4>());
}

// TEMPORAL !!
void TenazaInferiorCangrejo::renderizar(glm::mat4 model_matrix) {
	this->renderArm(model_matrix);
}

// ******************************* TORSO *******************************
TorsoCangrejo::TorsoCangrejo(myWindow* ventana) : Figura (ventana) {
	this->mi_superficie = this->crear_superficie (ventana);
}
TorsoCangrejo::~TorsoCangrejo() { }

Curva* TorsoCangrejo::crear_curva_trayectoria () {
	std::vector<glm::vec3> control_trayectoria;
	
	control_trayectoria.push_back ( glm::vec3 ( 0.0, -1.2, 0.0) );
	control_trayectoria.push_back ( glm::vec3 ( 0.0, 1.15, 0.0) );
	return (new CurvaBezier (control_trayectoria, glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 0.0, 1.0)));
}
Curva* TorsoCangrejo::crear_curva_seccion () {
	return (new Circunferencia(glm::vec3(0.0,0.0,0.0),0.5));
}

int TorsoCangrejo::obtener_pasos_trayectoria () {
	return 85;
}
int TorsoCangrejo::obtener_pasos_seccion () {
	return 100;
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

	ang_pata_Z[0]=90;
	ang_pata_Z[1]=90;
	ang_pata_Z[2]=90;
	ang_pata_Z[3]=-90;
	ang_pata_Z[4]=-90;
	ang_pata_Z[5]=-90;

	patas_elevacion[0]=false;
	patas_elevacion[1]=false;
	patas_elevacion[2]=false;
	patas_elevacion[3]=false;
	patas_elevacion[4]=false;
	patas_elevacion[5]=false;
	
	this->mi_superficie = this->crear_superficie (ventana);
}
Cangrejo::~Cangrejo() {
}
void Cangrejo::renderizar(glm::mat4 model_matrix) {
	this->torso.renderizar(model_matrix);
	this->cabeza.renderizar(model_matrix);

	model_matrix = glm::scale(model_matrix, glm::vec3 (0.3f,0.3f,0.3f));

	float ang_braz1_X = -90;
	float ang_braz1_Z = -45;
	glm::mat4 m_brazo1  = glm::translate(model_matrix , glm::vec3 (2.0f, 3.0f, 0.0f));
	m_brazo1  = glm::rotate(m_brazo1 , ang_braz1_Z, glm::vec3(0.0f, 0.0f, 1.0f));
	m_brazo1  = glm::rotate(m_brazo1 , ang_braz1_X, glm::vec3(1.0f, 0.0f, 0.0f));

	this->brazo1.renderizar(m_brazo1);

	float ang_braz2_X = -90;
	float ang_braz2_Z = 45;
	glm::mat4 m_brazo2  = glm::translate(model_matrix , glm::vec3 (-2.0f, 3.0f, 0.0f));
	m_brazo2  = glm::rotate(m_brazo2 , ang_braz2_Z, glm::vec3(0.0f, 0.0f, 1.0f));
	m_brazo2  = glm::rotate(m_brazo2 , ang_braz2_X, glm::vec3(1.0f, 0.0f, 0.0f));
	this->brazo2.renderizar(m_brazo2);

	// Achico un poco para q las patas sean mas chicas que los brazos
	model_matrix = glm::scale(model_matrix, glm::vec3 (0.8f,0.8f,0.8f));

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
}

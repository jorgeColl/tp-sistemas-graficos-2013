/*
 * Pez.cpp
 *
 *  Created on: 12/10/2013
 *      Author: jorge
 */

#include "Pez.h"
#include <vector>

#define KA_PEZ 0.04, 0.07, 0.15
#define KD_PEZ 0.8, 0.8, 0.8
#define KS_PEZ 0.5, 0.5, 0.5
#define SHIN_PEZ 20.0


// ******************************* ALETA *******************************
AletaPez::AletaPez(myWindow* ventana) :Figura(ventana) {
	this->mi_superficie = this->crear_superficie (ventana);
	this->mi_superficie->nombreTextura="aletaPez.jpg";
	this->mi_superficie->nombreTexturaNormal="aletaPezNormal.jpg";
	
	this->mi_superficie->ka = glm::vec3(KA_PEZ);
	this->mi_superficie->kd = glm::vec3(KD_PEZ);
	this->mi_superficie->ks = glm::vec3(KS_PEZ);
	this->mi_superficie->shininess = SHIN_PEZ;
}
AletaPez::~AletaPez() { }
void AletaPez::renderizar(glm::mat4 model_matrix) {
	model_matrix = glm::scale(model_matrix,glm::vec3(0.3,1.0,1.0));
	this->mi_superficie->render(model_matrix);
}

Curva* AletaPez::crear_curva_trayectoria () {
	std::vector<glm::vec3> control_trayectoria;
	
	control_trayectoria.push_back ( glm::vec3 (  0.0,  0.0, 0.0) );
	control_trayectoria.push_back ( glm::vec3 ( -0.01, 0.0, 0.25) );
	control_trayectoria.push_back ( glm::vec3 (  0.0,  0.0, 0.5) );
	return (new CurvaBezier (control_trayectoria, glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 0.0, 1.0)));
}
Curva* AletaPez::crear_curva_seccion () {
	return (new Elipse(glm::vec3(0.0,0.0,0.0), 0.05, 0.40));
}
int AletaPez::obtener_pasos_trayectoria () {
	return 50;
}
int AletaPez::obtener_pasos_seccion () {
	return 100;
}
FuncionCurvaBezier AletaPez::crear_funcion () {
	std::vector<glm::vec3> puntos;
	puntos.push_back ( glm::vec3 (0.0, 0.0, 0.0) );
	puntos.push_back ( glm::vec3 (0.01 * this->obtener_pasos_trayectoria(), 2.00, 0.0) );
	puntos.push_back ( glm::vec3 (0.05 * this->obtener_pasos_trayectoria(), 1.50, 0.0) );
	puntos.push_back ( glm::vec3 (0.30 * this->obtener_pasos_trayectoria(), 1.25, 0.0) );
	puntos.push_back ( glm::vec3 (0.60 * this->obtener_pasos_trayectoria(), 1.00, 0.0) );
	puntos.push_back ( glm::vec3 (this->obtener_pasos_trayectoria(), 0.65, 0.0) );
	return (FuncionCurvaBezier(puntos));
}

// ******************************* COLA ********************************
ColaPez::ColaPez(myWindow* ventana) :Figura(ventana) {
	this->mi_superficie = this->crear_superficie (ventana);
	this->mi_superficie->nombreTextura="colaPez.jpg";
	this->mi_superficie->nombreTexturaNormal="colaPezNormal.jpg";
	
	this->mi_superficie->ka = glm::vec3(KA_PEZ);
	this->mi_superficie->kd = glm::vec3(KD_PEZ);
	this->mi_superficie->ks = glm::vec3(KS_PEZ);
	this->mi_superficie->shininess = SHIN_PEZ;
}
ColaPez::~ColaPez() { }
void ColaPez::renderizar(glm::mat4 model_matrix) {
	model_matrix = glm::scale(model_matrix,glm::vec3 (0.3f,1.0f,1.0f));
	this->mi_superficie->render(model_matrix);
}

Curva* ColaPez::crear_curva_trayectoria () {
	std::vector<glm::vec3> control_trayectoria;
	
	control_trayectoria.push_back ( glm::vec3 (  0.0,  0.0, 0.0) );
	control_trayectoria.push_back ( glm::vec3 ( -0.01, 0.0, 0.25) );
	control_trayectoria.push_back ( glm::vec3 (  0.0,  0.0, 0.60) );
	return (new CurvaBezier (control_trayectoria, glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 0.0, 1.0)));
}
Curva* ColaPez::crear_curva_seccion () {
	return (new Elipse(glm::vec3(0.0,0.0,0.0), 0.05, 0.40));
}
int ColaPez::obtener_pasos_trayectoria () {
	return 50;
}
int ColaPez::obtener_pasos_seccion () {
	return 100;
}
FuncionCurvaBezier ColaPez::crear_funcion () {
	std::vector<glm::vec3> puntos;
	puntos.push_back ( glm::vec3 (0.0, 0.0, 0.0) );
	puntos.push_back ( glm::vec3 (0.01 * this->obtener_pasos_trayectoria(), 2.50, 0.0) );
	puntos.push_back ( glm::vec3 (0.05 * this->obtener_pasos_trayectoria(), 2.20, 0.0) );
	puntos.push_back ( glm::vec3 (0.30 * this->obtener_pasos_trayectoria(), 1.75, 0.0) );
	puntos.push_back ( glm::vec3 (0.50 * this->obtener_pasos_trayectoria(), 1.20, 0.0) );
	puntos.push_back ( glm::vec3 (this->obtener_pasos_trayectoria(), 0.25, 0.0) );
	return (FuncionCurvaBezier(puntos));
}

// ******************************* TORSO *******************************
TorsoPez::TorsoPez(myWindow* ventana) :Figura(ventana) {
	this->mi_superficie = this->crear_superficie (ventana);
	this->mi_superficie->nombreTextura="escamasPez.jpg";
	this->mi_superficie->nombreTexturaNormal="escamasPezNormal.jpg";
	
	this->mi_superficie->ka = glm::vec3(KA_PEZ);
	this->mi_superficie->kd = glm::vec3(KD_PEZ);
	this->mi_superficie->ks = glm::vec3(KS_PEZ);
	this->mi_superficie->shininess = SHIN_PEZ;
}
TorsoPez::~TorsoPez() { }
void TorsoPez::renderizar(glm::mat4 model_matrix) {
	if(MODELO_SIMPLE) model_matrix = glm::scale(model_matrix,glm::vec3(0.5f,0.5f,1.0f));
	Figura::renderizar(model_matrix);
}
Superficie* TorsoPez::crear_superficie (myWindow* ventana) {
	if (MODELO_SIMPLE) return (new Cubo(ventana));
	else return (Figura::crear_superficie(ventana));
}

Curva* TorsoPez::crear_curva_trayectoria () {
	std::vector<glm::vec3> control_trayectoria;
	
	control_trayectoria.push_back ( glm::vec3 (  0.0,  0.0, -1.5) );
	control_trayectoria.push_back ( glm::vec3 (  0.0,  0.0, 1.5) );
	return (new CurvaBezier (control_trayectoria, glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 0.0, 1.0)));
}
Curva* TorsoPez::crear_curva_seccion () {
	return (new Elipse(glm::vec3(0.0,0.0,0.0), 0.25, 1.0));
}
int TorsoPez::obtener_pasos_trayectoria () {
	return 50;
}
int TorsoPez::obtener_pasos_seccion () {
	return 100;
}
FuncionCurvaBezier TorsoPez::crear_funcion () {
	std::vector<glm::vec3> puntos;
	puntos.push_back ( glm::vec3 (0.0, 0.0001, 0.0) );
	puntos.push_back ( glm::vec3 (0.03 * this->obtener_pasos_trayectoria(), 1.7, 0.0) );
	puntos.push_back ( glm::vec3 (0.5 * this->obtener_pasos_trayectoria(), 1.0, 0.0) );
	puntos.push_back ( glm::vec3 (0.97 * this->obtener_pasos_trayectoria(), 1.7, 0.0) );
	puntos.push_back ( glm::vec3 (this->obtener_pasos_trayectoria(), 0.0001, 0.0) );
	return (FuncionCurvaBezier(puntos));
}

// **************************** AletaDorsal ****************************
AletaDorsal::AletaDorsal(myWindow* ventana): Figura(ventana) {
	this->mi_superficie = this->crear_superficie (ventana);
	this->mi_superficie->nombreTextura="aletaDorsalPez.jpg";
	this->mi_superficie->nombreTexturaNormal="aletaDorsalPezNormal.jpg";
	
	this->mi_superficie->ka = glm::vec3(KA_PEZ);
	this->mi_superficie->kd = glm::vec3(KD_PEZ);
	this->mi_superficie->ks = glm::vec3(KS_PEZ);
	this->mi_superficie->shininess = SHIN_PEZ;
}
AletaDorsal::~AletaDorsal(){ }
void AletaDorsal::renderizar(glm::mat4 model_matrix) {
	model_matrix = glm::scale(model_matrix,glm::vec3 (0.8f,1.0f,1.0f));
	Figura::renderizar(model_matrix);
}

Curva* AletaDorsal::crear_curva_trayectoria () {
	std::vector<glm::vec3> control_trayectoria;
	
	control_trayectoria.push_back ( glm::vec3 ( 0.0, -0.25, -0.95) );
	control_trayectoria.push_back ( glm::vec3 ( 0.0,  0.05, 0.0) );
	control_trayectoria.push_back ( glm::vec3 ( 0.0, -0.45, 1.2) );
	return (new CurvaBezier (control_trayectoria, glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 0.0, 1.0)));
}
Curva* AletaDorsal::crear_curva_seccion () {
	return (new Elipse(glm::vec3(0.0,0.0,0.0), 0.05, 0.3));
}
int AletaDorsal::obtener_pasos_trayectoria () {
	return 50;
}
int AletaDorsal::obtener_pasos_seccion () {
	return 100;
}
FuncionCurvaBezier AletaDorsal::crear_funcion () {
	std::vector<glm::vec3> puntos;
	puntos.push_back ( glm::vec3 (0.0, 0.0, 0.0) );
	puntos.push_back ( glm::vec3 (0.35 * this->obtener_pasos_trayectoria(), 0.65, 0.0) );
	puntos.push_back ( glm::vec3 (0.90 * this->obtener_pasos_trayectoria(), 0.5, 0.0) );
	puntos.push_back ( glm::vec3 (0.95 * this->obtener_pasos_trayectoria(), 3.5, 0.0) );
	puntos.push_back ( glm::vec3 (this->obtener_pasos_trayectoria(), 0.0, 0.0) );
	return (FuncionCurvaBezier(puntos));
}

// ******************************** Ojo********************************
Ojo::Ojo(myWindow* ventana):Figura(ventana) {
	this->mi_superficie = this->crear_superficie (ventana);
	this->mi_superficie->nombreTextura="ojoPez.jpg";
	
	this->mi_superficie->ks = glm::vec3(KS_PEZ);
	this->mi_superficie->shininess = SHIN_PEZ;
}
Ojo::~Ojo() { }

Superficie* Ojo::crear_superficie (myWindow* ventana) {
	return (new Esfera (ventana, 0.1, 32, 32));
}

// ******************************** PEZ ********************************
Pez::Pez(myWindow* ventana) :
		Figura(ventana), aleta1(ventana), aleta2(ventana), aleta_dorsal(ventana), cola(ventana),
		torso(ventana),ojo1(ventana), ojo2(ventana), m_pos(0,0,0) {
	trayecto=NULL;
	u=0;
	angCola=5.0f;
	angAleta=25.0f;
	cola_girando=true;
	aleta_girando=true;
	angX=0;
	angZ=0;
	angY=0;
	angXViejo=0;
	angZViejo=0;
	angYViejo=0;
	this->mi_superficie = this->crear_superficie (ventana);

}
Pez::~Pez() {}
void Pez::renderizar(glm::mat4 model_matrix) {
	glm::mat4 model_temp;
	glm::mat4 model_original = model_matrix;

	model_matrix = glm::translate(model_matrix,m_pos);
    // ################################ PARTE COMPLICADA #############################
	// OJO: hay dos rotaciones desavilitadas !!!
	//model_matrix = glm::rotate(model_matrix,angZ,glm::vec3(0,1,0));
	model_matrix = glm::rotate(model_matrix,angX,glm::vec3(0,0,1));
	//model_matrix = glm::rotate(model_matrix,angY,glm::vec3(0,1,0));
	// ############################ FIN DE PARTE COMPLICADA ##########################
	model_matrix = glm::rotate(model_matrix,90.0f,glm::vec3(0,0,1));
	model_matrix = glm::rotate(model_matrix,90.0f,glm::vec3(1,0,0));
	
	if (!MODELO_SIMPLE) {
		model_temp = glm::translate(model_matrix,glm::vec3(0.15f,0,0.3f));
		model_temp = glm::translate(model_temp,glm::vec3(0,0,0.5));
		model_temp = glm::rotate(model_temp,-angAleta,glm::vec3(0,1,0));
		model_temp = glm::translate(model_temp,glm::vec3(0,0,-0.5));
		aleta1.renderizar(model_temp);

		model_temp = glm::translate(model_matrix,glm::vec3(-0.15f,0,0.3f));
		model_temp = glm::translate(model_temp,glm::vec3(0,0,0.5));
		model_temp = glm::rotate(model_temp,angAleta,glm::vec3(0,1,0));
		model_temp = glm::translate(model_temp,glm::vec3(0,0,-0.5));
		aleta2.renderizar(model_temp);

		model_temp = glm::translate(model_matrix, glm::vec3(0,0.8f,0));
		aleta_dorsal.renderizar(model_temp);

		model_temp = glm::translate(model_matrix,glm::vec3 (0,0,-1.95));
		model_temp = glm::translate(model_temp,glm::vec3(0,0,0.5));
		model_temp = glm::rotate(model_temp,angCola,glm::vec3(0,1,0));
		model_temp = glm::translate(model_temp,glm::vec3(0,0,-0.5));
		cola.renderizar(model_temp);
		
		// Ojos
		model_temp = glm::translate(model_matrix,glm::vec3 (-0.1,0,1.1));
		model_temp = glm::rotate(model_temp, 17.0f, glm::vec3 (0.0,1.0,0.0));
		ojo1.renderizar(model_temp);

		model_temp = glm::translate(model_matrix,glm::vec3 (0.1,0,1.1));
		model_temp = glm::rotate(model_temp, -17.0f, glm::vec3 (0.0,1.0,0.0));
		model_temp = glm::scale(model_temp,glm::vec3 (-1.0,1.0,1.0));
		ojo2.renderizar(model_temp);
	}
	torso.renderizar(model_matrix);

	// dibujo trayecto
	if (MOSTRAR_RECORRIDOS){
		float cant_tramos = trayecto->cantidad_tramos();
		for (float i = 0; i < cant_tramos; i += 0.1f) {
			glm::mat4 model_aux = model_original;
			model_aux = glm::translate(model_aux, trayecto->damePunto(i));
			model_aux = glm::scale(model_aux, glm::vec3(0.1f, 0.1f, 0.1f));
			this->mySphere->render(model_aux);
		}
	}

}
void Pez::set_trayecto(std::vector<glm::vec3> puntos){
	glm::vec3 centro (1,1,1);
	glm::vec3 orientacion (1,1,1);
	trayecto = new CurvaBSpline(puntos,centro,orientacion);
}
void Pez::animar() {
	if (trayecto == NULL) {
		//std::cout << "TRAYECTO NO INICIADO";
		return;
	}

	// ################################ PARTE COMPLICADA #############################
	//std::cout << "Cantidad de tramos: " << trayecto->cantidad_tramos() << " "<< std::endl;
	glm::vec3 aN = trayecto->dameTangente(u);


	glm::vec3 ProyAX = glm::normalize( glm::dot(aN, glm::vec3(1, 0, 0))* aN );
	
	// cont es el u , y avanzo al siguiente paso
	u += 0.01;
	if (u > trayecto->cantidad_tramos()) {
		u = 0;
		angZ = 0;
		angX = 0;
		angY = 0;
		m_pos = trayecto->damePunto(u);
		return;
	}
	glm::vec3 bN = trayecto->dameTangente(u);
	glm::vec3 ProyBX = glm::normalize( glm::dot(bN, glm::vec3(1, 0, 0))* bN);

	// asigno siguiente posicion al pez
	glm::vec3 nueva_pos = trayecto->damePunto(u);

	// calculo del angulo a sumar
	// Para rotacio a los costados
	float radianesX = acos(glm::dot(ProyAX, ProyBX));
	if( radianesX<0 || radianesX>0  ){
		float angXNuevo = (radianesX * 360) / (2 * 3.141592654f);
		if(angXNuevo<170 && angXNuevo>-170){
			angX+=angXNuevo;
		}
		//std::cout << "angulo de NUEVOX: " << angXNuevo << std::endl;
	}
	//std::cout << "angulo de giroX: " << angX << std::endl;

	// Para rotacion hacia arriba o abajo
	glm::vec3 dist =(nueva_pos-m_pos);
	angZ-=atan((nueva_pos.z-m_pos.z)/sqrt(glm::dot(dist,dist)));
	//std::cout << "angulo de giroZ: " << angZ << std::endl;

	m_pos = nueva_pos;
	//std::cout << "trayecto:" << nueva_pos.x << " , " << nueva_pos.y << " , "<< nueva_pos.z << std::endl;
	// #########################FIN DE  PARTE COMPLICADA #############################

	// modifico angulo de giro de la COLA
	if(cola_girando){
		angCola++;
		if(angCola>15.0){
			cola_girando=false;
		}
	}
	if(!cola_girando){
		angCola--;
		if(angCola<-15.0f){
			cola_girando=true;
		}
	}
	//std::cout << "angulo cola: " << angCola << std::endl;

	// modifico angulo de giro de las ALETAS
	if (aleta_girando) {
		angAleta++;
		if (angAleta > 45.0) {
			aleta_girando = false;
		}
	}
	if (!aleta_girando) {
		angAleta--;
		if (angAleta < 12.0f) {
			aleta_girando = true;
		}
	}
	//std::cout<<"angulo aleta: "<<angAleta<<std::endl;
}

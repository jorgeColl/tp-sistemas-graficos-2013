/*
 * Planta.cpp
 *
 *  Created on: 10/10/2013
 *      Author: jorge
 */

#include "Planta.h"

// ****************************** PLANTA *******************************
Planta::Planta(myWindow* ventana):Figura(ventana),hoja1(ventana),hoja2(ventana),hoja3(ventana) {
	this->mi_superficie = this->crear_superficie (ventana);
}
Planta::~Planta() { }

void Planta::renderizar(glm::mat4 model_matrix) {
	glm::mat4 model_temp;
	glm::vec3 ejeX (1,0,0);

	model_temp = glm::translate(model_matrix,glm::vec3(0,0,-(hoja1.altura/2)));
	model_temp = glm::rotate(model_temp,-13.0f,ejeX);
	model_temp = glm::translate(model_temp,glm::vec3(0,0,(hoja1.altura/2)));
	hoja1.renderizar(model_temp);

	hoja2.renderizar(model_matrix);

	model_temp = glm::translate(model_matrix,glm::vec3(0,0,-(hoja3.altura/2)));
	model_temp = glm::rotate(model_temp,13.0f,ejeX);
	model_temp = glm::translate(model_temp,glm::vec3(0,0,(hoja3.altura/2)));
	hoja3.renderizar(model_temp);
}

void Planta::animar() {
	this->hoja1.animar();
	this->hoja2.animar();
	this->hoja3.animar();
}

// ************************** HOJAS DE PLANTA **************************
HojaPlanta::HojaPlanta(myWindow* ventana): Figura(ventana) {
	this->altura = Helper::num_aleatorio (1.8, 2.7);
	this->mi_superficie = this->crear_superficie (ventana);
	this->mi_superficie->nombreTextura="hoja.jpg";
	this->mi_superficie->nombreTexturaNormal="hojaNormal.jpg";
	
	Animacion* ani = new Animacion (Zvar);
	ani->set_velocidad ( 5 * 3.1415927f / 180.0 );
	this->agregar_rotacion (ani);
	this->agregar_traslacion (ani);
	this->mi_superficie->set_animacion (ani);
}
HojaPlanta::~HojaPlanta() { }

void HojaPlanta::animar() {
	this->mi_superficie->animar();
}

void HojaPlanta::agregar_traslacion (Animacion* ani) {
	std::vector<glm::vec3> puntosIntensidad;
	puntosIntensidad.push_back ( glm::vec3 (0.0, 0.0, 0.0) );
	puntosIntensidad.push_back ( glm::vec3 (this->altura, 0.02, 0.0) );
	FuncionCurvaBezier* intensidad = new FuncionCurvaBezier (puntosIntensidad);
	
	float amplitud = Helper::num_aleatorio (0.80, 1.2);
	float frecuencia = Helper::num_aleatorio (0.5, 2.0);
	float fase = Helper::num_aleatorio (0.0, 1.0 * 3.1415927f);
	FuncionSeno* coeficiente = new FuncionSeno (amplitud, frecuencia, fase);
	glm::vec3 direccionY = glm::vec3 (0.0, 1.0, 0.0);
	ani->agregar_animacion (Traslacion, intensidad, coeficiente, direccionY);
}

void HojaPlanta::agregar_rotacion (Animacion* ani) {
	
}

Curva* HojaPlanta::crear_curva_trayectoria () {
	std::vector<glm::vec3> control_trayectoria;
	
	control_trayectoria.push_back ( glm::vec3 ( 0.0, 0.0, 0.0) );
	control_trayectoria.push_back ( glm::vec3 ( 0.0, 0.0, this->altura) );
	return (new CurvaBezier (control_trayectoria, glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 0.0, 1.0)));
}
Curva* HojaPlanta::crear_curva_seccion () {
	float ancho = Helper::num_aleatorio (0.25, 0.35);
	return (new Elipse(glm::vec3(0.0,0.0,0.0), ancho, 0.02));
}
int HojaPlanta::obtener_pasos_trayectoria () {
	return 25;
}
int HojaPlanta::obtener_pasos_seccion () {
	return 50;
}

FuncionCurvaBezier HojaPlanta::crear_funcion () {
	std::vector<glm::vec3> puntos;
	puntos.push_back ( glm::vec3 (0.0, 0.15, 0.0) );
	puntos.push_back ( glm::vec3 (0.5 * this->obtener_pasos_trayectoria(), 1.0, 0.0) );
	puntos.push_back ( glm::vec3 (this->obtener_pasos_trayectoria(), 0.0, 0.0) );
	return (FuncionCurvaBezier(puntos));
}

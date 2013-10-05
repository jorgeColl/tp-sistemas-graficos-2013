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
PataCangrejo::PataCangrejo(myWindow* ventana) {
	this->window = ventana;
}
PataCangrejo::~PataCangrejo() {
}
void PataCangrejo::renderizar(glm::mat4 model_matrix) {
	/*// primera parte del brazo
	this->window->renderArm(model_matrix);

	model_matrix = glm::translate(model_matrix, glm::vec3 (0.0f, 0.0f, 3.5f));

	model_matrix = glm::rotate(model_matrix, this->ang_braz2_X, glm::vec3 (1.0f,0.0f,0.0f));
	model_matrix = glm::rotate(model_matrix, this->ang_braz2_Z, glm::vec3 ( 0.0f,0.0f,1.0f));

	// segunda parte del brazo
	this->window->renderArm(model_matrix);

	model_matrix= glm::translate(model_matrix, glm::vec3 (0.0f, 0.0f, 3.5f));
	model_matrix = glm::rotate(model_matrix, this->ang_dedos_X, glm::vec3 (1.0f, 0.0f,0.0f));
	glm::mat4 rot3 = glm::rotate(glm::mat4 (1.0f), this->ang_mano, glm::vec3 (0.0f, 0.0f,1.0f));

	// mano del brazo 1
	this->window->renderArm(  model_matrix*rot3);
	*/
}

CabezaCangrejo::CabezaCangrejo(myWindow* ventana) {
	this->window = ventana;
}
CabezaCangrejo::~CabezaCangrejo() {
}
void CabezaCangrejo::renderizar(glm::mat4 model_matrix) {
	glm::vec3 translado(0, 1.2, 0);
	model_matrix = glm::translate(model_matrix, translado);

	glm::vec3 escala(0.5, 0.5, 0.5);
	model_matrix = glm::scale(model_matrix, escala);
	this->window->renderSpiralSphere(model_matrix);
}

BrazoCangrejo::BrazoCangrejo(myWindow* ventana) {
	this->window = ventana;
	ang_braz2_X=0;
	ang_braz2_Z=0;

	ang_mano=0;
	ang_dedos_X=20;
}
BrazoCangrejo::~BrazoCangrejo() {
}
void BrazoCangrejo::renderizar(glm::mat4 model_matrix) {
	// primera parte del brazo
	this->window->renderArm(model_matrix);

	model_matrix = glm::translate(model_matrix, glm::vec3 (0.0f, 0.0f, 3.5f));

	model_matrix = glm::rotate(model_matrix, this->ang_braz2_X, glm::vec3 (1.0f,0.0f,0.0f));
	model_matrix = glm::rotate(model_matrix, this->ang_braz2_Z, glm::vec3 ( 0.0f,0.0f,1.0f));

	// segunda parte del brazo
	this->window->renderArm(model_matrix);

	model_matrix= glm::translate(model_matrix, glm::vec3 (0.0f, 0.0f, 3.5f));
	model_matrix = glm::rotate(model_matrix, this->ang_dedos_X, glm::vec3 (1.0f, 0.0f,0.0f));
	glm::mat4 rot3 = glm::rotate(glm::mat4 (1.0f), this->ang_mano, glm::vec3 (0.0f, 0.0f,1.0f));

	// mano del brazo 1
	this->window->renderArm(  model_matrix*rot3);

	glm::mat4 rot4 = glm::rotate(glm::mat4 (1.0f), -this->ang_dedos_X, glm::vec3 (1.0f, 0.0f, 0.0f));

	// mano del brazo 2
	this->window->renderArm(  model_matrix * rot4);

}

TorsoCangrejo::TorsoCangrejo(myWindow* ventana) {
	this->window = ventana;
}
TorsoCangrejo::~TorsoCangrejo() {
}
void TorsoCangrejo::renderizar(glm::mat4 model_matrix) {
	glm::vec3 escala(1, 1.2, 0.8);
	model_matrix = glm::scale(model_matrix, escala);
	this->window->renderSpiralSphere(model_matrix);
}

Cangrejo::Cangrejo(myWindow* ventana) :
		pata1(ventana), pata2(ventana), pata3(ventana), pata4(ventana), pata5(
				ventana), pata6(ventana), cabeza(ventana), torso(ventana), brazo1(
				ventana), brazo2(ventana) {
	this->window = ventana;

}
Cangrejo::~Cangrejo() {
}
void Cangrejo::renderizar(glm::mat4 model_matrix) {
	this->torso.renderizar(model_matrix);
	this->cabeza.renderizar(model_matrix);

	float ang_braz1_X = -70;
	float ang_braz1_Z = 0;
	float ang_braz1_Y=45;
	glm::mat4 m_brazo1  = glm::scale(model_matrix, glm::vec3 (0.3f,0.3f,0.3f));
	m_brazo1  = glm::translate(m_brazo1 , glm::vec3 (2.0f, 3.0f, 0.0f));
	m_brazo1  = glm::rotate(m_brazo1 , ang_braz1_X, glm::vec3(1.0f, 0.0f, 0.0f));
	m_brazo1  = glm::rotate(m_brazo1 , ang_braz1_Y, glm::vec3(0.0f, 1.0f, 0.0f));
	m_brazo1  = glm::rotate(m_brazo1 , ang_braz1_Z, glm::vec3(0.0f, 0.0f, 1.0f));

	this->brazo1.renderizar(m_brazo1);

	float ang_braz2_X = -70;
	float ang_braz2_Z = 0;
	float ang_braz2_Y = 45;
	glm::mat4 m_brazo2 = glm::scale(model_matrix, glm::vec3(0.3f, 0.3f, 0.3f));
	m_brazo2 = glm::translate(m_brazo2, glm::vec3(-2.0f, 3.0f, 0.0f));
	m_brazo2 = glm::rotate(m_brazo2, ang_braz2_X, glm::vec3(1.0f, 0.0f, 0.0f));
	m_brazo2 = glm::rotate(m_brazo2, ang_braz2_Y, glm::vec3(0.0f, 1.0f, 0.0f));
	m_brazo2  = glm::rotate(m_brazo2 , ang_braz2_Z, glm::vec3(0.0f, 0.0f, 1.0f));

	this->brazo2.renderizar(m_brazo2);

	this->pata1.renderizar(model_matrix);
	/*
	this->pata2.renderizar(model_matrix);
	this->pata3.renderizar(model_matrix);
	this->pata4.renderizar(model_matrix);
	this->pata5.renderizar(model_matrix);
	this->pata6.renderizar(model_matrix);
*/
}

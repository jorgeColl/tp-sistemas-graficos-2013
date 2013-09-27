/*
 * cangrejo.cpp
 *
 *  Created on: 22/09/2013
 *      Author: jorge
 */

#include "cangrejo.h"

PataCangrejo::PataCangrejo(myWindow* ventana) {
	this->window=ventana;
}
PataCangrejo::~PataCangrejo(){ }
void PataCangrejo::renderizar(glm::mat4 model_matrix) {
}

CabezaCangrejo::CabezaCangrejo(myWindow* ventana) {
	this->window=ventana;
}
CabezaCangrejo::~CabezaCangrejo(){ }
void CabezaCangrejo::renderizar(glm::mat4 model_matrix) {
}

BrazoCangrejo::BrazoCangrejo(myWindow* ventana){
	this->window= ventana;
}
BrazoCangrejo::~BrazoCangrejo(){ }
void BrazoCangrejo::renderizar(glm::mat4 model_matrix) {
}

TorsoCangrejo::TorsoCangrejo (myWindow* ventana){
	this->window = ventana;
}
TorsoCangrejo::~TorsoCangrejo(){ }
void TorsoCangrejo::renderizar(glm::mat4 model_matrix) {
}

Cangrejo::Cangrejo(myWindow* ventana):pata1(ventana),pata2(ventana),pata3(ventana), pata4(ventana),pata5(ventana), pata6(ventana),cabeza(ventana),torso(ventana),brazo1(ventana),brazo2(ventana){
	this->window = ventana;

}
Cangrejo::~Cangrejo() { }
void Cangrejo::renderizar(glm::mat4 model_matrix) {
}

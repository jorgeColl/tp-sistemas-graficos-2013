#include "SuperficieBarrido.h"

#include "PlanoAlgebraico.h"
#include <iostream>

SuperficieBarrido::SuperficieBarrido (Curva* trayectoriaRecibida, Curva* seccionRecibida, unsigned int pasosTray,
									  unsigned int pasosSec, std::vector<glm::mat4> transformacionesRecibidas,
									  myWindow* passed_window) : Superficie (passed_window) {
	
	this->trayectoria = trayectoriaRecibida;
	this->seccion = seccionRecibida;
	this->set_pasos_trayectoria (pasosTray);
	this->set_pasos_seccion (pasosSec);
	this->set_transformaciones (transformacionesRecibidas);
	
	if (this->atributosValidos()) this->crear_puntos();
	else this->inicializarNulo();
	
	this->modo = GL_TRIANGLE_STRIP;
}

void SuperficieBarrido::set_pasos_trayectoria (unsigned int pasos) {
	this->pasos_trayectoria = pasos;
}

void SuperficieBarrido::set_pasos_seccion (unsigned int pasos) {
	this->pasos_seccion = pasos;
}

void SuperficieBarrido::set_transformaciones (std::vector<glm::mat4> transformacionesRecibidas) {
	this->transformaciones = std::vector<glm::mat4>(transformacionesRecibidas);
}

SuperficieBarrido::~SuperficieBarrido () {
	delete[] this->vertex_buffer;
	delete[] this->tangent_buffer;
	delete[] this->normal_buffer;
	delete[] this->texture_buffer;
	delete[] this->index_buffer;
	
	delete (this->trayectoria);
	delete (this->seccion);
}

// metodos auxiliares
bool SuperficieBarrido::atributosValidos () {
	if (this->pasos_trayectoria <= 0) return false;
	if (this->pasos_seccion <= 0) return false;
	return true;
}

void SuperficieBarrido::inicializarNulo () {
	this->vertex_buffer_size = 0;
	this->normal_buffer_size = 0;
	this->index_buffer_size  = 0;
	
	this->vertex_buffer = new GLfloat[this->vertex_buffer_size];
	this->normal_buffer = new GLfloat[this->normal_buffer_size];
	this->index_buffer = new GLuint[this->index_buffer_size];
}

void SuperficieBarrido::crear_puntos () {
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> tangentes;
	std::vector<glm::vec3> normales;
	std::vector<glm::vec2> textura;
	std::vector<unsigned int> indices;
	std::list<unsigned int> indices_seccion;
	
	for (unsigned int i = 0; i <= this->pasos_trayectoria ; i++) {
		float ui = this->preparar_seccion (i);
		
		for (unsigned int j = 0; j <= this->pasos_seccion ; j++) {
			float vi = ((j*1.0) / (this->pasos_seccion*1.0));
			float v = vi * this->seccion->cantidad_tramos();
			vertices.push_back  (this->seccion->damePunto (v));
			tangentes.push_back (this->seccion->dameTangente (v));
			normales.push_back  (this->seccion->dameNormal (v));
			textura.push_back (glm::vec2 (ui,vi));
			this->cargar_indices (i, j, &indices_seccion, &indices);
		}
		this->seccion->reset();
	}
	this->cargar_puntos (&vertices, &tangentes, &normales, &textura, &indices);
}

float SuperficieBarrido::preparar_seccion (unsigned int i) {
	float ui = ((i*1.0) / (this->pasos_trayectoria*1.0));
	float u = ui * this->trayectoria->cantidad_tramos();
	
	glm::mat4 transformacion = glm::mat4 (1.0f);
	if (i < this->transformaciones.size()) transformacion = this->transformaciones.at(i);
	
	this->seccion->transformar(transformacion);
	this->seccion->alinear (this->trayectoria->dameTangente(u));
	this->seccion->centrar (this->trayectoria->damePunto (u));
	return ui;
}

void SuperficieBarrido::cargar_indices (unsigned int i, unsigned int j,
										std::list<unsigned int>* indices_seccion,
										std::vector<unsigned int>* indices) {
	
	unsigned int indice_actual = (i * (this->pasos_seccion + 1)) + j;
	if (i != 0) {
		unsigned int indice_anterior = indices_seccion->front();
		indices_seccion->pop_front();
		
		// degeneracion: repito primer indice para enganchar strip
		if ((j == 0) && (i != 1)) indices->push_back (indice_anterior); 
		
		indices->push_back (indice_anterior);
		indices->push_back (indice_actual);
		
		// degeneracion: repito ultimo indice para enganchar strip
		if ((j == this->pasos_seccion) && (i != this->pasos_trayectoria)) indices->push_back (indice_actual);
	}
	indices_seccion->push_back (indice_actual);
}

void SuperficieBarrido::cargar_puntos (std::vector<glm::vec3>* vertices, std::vector<glm::vec3>* tangentes,
									   std::vector<glm::vec3>* normales, std::vector<glm::vec2>* textura,
									   std::vector<unsigned int>* indices) {
	
	this->vertex_buffer_size =  (3 * vertices->size());
	this->tangent_buffer_size = (3 * tangentes->size());
	this->normal_buffer_size =  (3 * normales->size());
	this->texture_buffer_size = (2 * textura->size());
	this->index_buffer_size = indices->size();
	
	this->vertex_buffer = new GLfloat[this->vertex_buffer_size];
	this->tangent_buffer = new GLfloat[this->tangent_buffer_size];
	this->normal_buffer = new GLfloat[this->normal_buffer_size];
	this->texture_buffer = new GLfloat[this->texture_buffer_size];
	this->index_buffer = new GLuint[this->index_buffer_size];
	
	this->copiar_puntos_3D (vertices, this->vertex_buffer);
	this->copiar_puntos_3D (tangentes, this->tangent_buffer);
	this->copiar_puntos_3D (normales, this->normal_buffer);
	this->copiar_puntos_2D (textura, this->texture_buffer);
	for (unsigned int i = 0 ; i < this->index_buffer_size ; i++) {
		this->index_buffer[i] = indices->at (i);
	}
}

void SuperficieBarrido::copiar_puntos_3D (std::vector<glm::vec3>* puntosOrigen, GLfloat* puntosDestino) {
	std::vector<glm::vec3>::iterator it;
    unsigned int i = 0;
    for (it = puntosOrigen->begin() ; it != puntosOrigen->end(); it++) {
        puntosDestino[i] = ((*it).x);
        puntosDestino[i+1] = ((*it).y);
        puntosDestino[i+2] = ((*it).z);
        i += 3;
    }
}

void SuperficieBarrido::copiar_puntos_2D (std::vector<glm::vec2>* puntosOrigen, GLfloat* puntosDestino) {
	std::vector<glm::vec2>::iterator it;
    unsigned int i = 0;
    for (it = puntosOrigen->begin() ; it != puntosOrigen->end(); it++) {
        puntosDestino[i] = ((*it).x);
        puntosDestino[i+1] = ((*it).y);
        i += 2;
    }
}

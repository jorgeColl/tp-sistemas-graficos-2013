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
	
	this->crear_puntos();
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
	delete[] this->normal_buffer;
	delete[] this->index_buffer;
	
	delete (this->trayectoria);
	delete (this->seccion);
}

// metodos auxiliares

void SuperficieBarrido::crear_puntos () {
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> normales;
	std::vector<unsigned int> indices;
	std::list<unsigned int> indices_seccion;
	
	for (unsigned int i = 0; i <= this->pasos_trayectoria ; i++) {
		this->preparar_seccion (i);
		
		for (unsigned int j = 0; j <= this->pasos_seccion ; j++) {
			float u = ((j*1.0) / (this->pasos_seccion*1.0)) * this->seccion->cantidad_tramos();
			glm::vec3 puntoSeccion = this->seccion->damePunto (u);
			vertices.push_back (puntoSeccion);
			normales.push_back (this->calcular_normal (puntoSeccion));
			this->cargar_indices (i, j, &indices_seccion, &indices);
		}
		this->seccion->reset();
	}
	this->cargar_puntos (&vertices, &normales, &indices);
}

void SuperficieBarrido::preparar_seccion (unsigned int i) {
	float ui = ((i*1.0) / (this->pasos_trayectoria*1.0));
	float u = ui * this->trayectoria->cantidad_tramos();
	glm::vec3 puntoTrayectoria = this->trayectoria->damePunto (u);
	
	float pasoTangente = ((1.0) / (this->pasos_trayectoria*1.0)) * this->trayectoria->cantidad_tramos();
	glm::mat4 transformacion = glm::mat4 (1.0f);
	if (i < this->transformaciones.size()) transformacion = this->transformaciones.at(i);
	
	this->seccion->transformar(transformacion);
	this->seccion->alinear (this->trayectoria->dameTangente(u, pasoTangente));
	this->seccion->centrar (puntoTrayectoria);
}

glm::vec3 SuperficieBarrido::calcular_normal (glm::vec3 punto) {
	glm::vec3 punto_plano = this->seccion->dameCentro();
	glm::vec3 normal_plano = this->seccion->dameOrientacion();
	PlanoAlgebraico plano (punto_plano, normal_plano);
	return (plano.proyectar (punto));
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

void SuperficieBarrido::cargar_puntos (std::vector<glm::vec3>* vertices,
									   std::vector<glm::vec3>* normales,
									   std::vector<unsigned int>* indices) {
	
	this->vertex_buffer_size = (3 * vertices->size());
	this->normal_buffer_size = (3 * normales->size());
	this->index_buffer_size = indices->size();
	
	this->vertex_buffer = new GLfloat[this->vertex_buffer_size];
	this->normal_buffer = new GLfloat[this->normal_buffer_size];
	this->index_buffer = new GLuint[this->index_buffer_size];
	
	this->copiar_puntos (vertices, this->vertex_buffer);
	this->copiar_puntos (normales, this->normal_buffer);
	for (unsigned int i = 0 ; i < this->index_buffer_size ; i++) {
		this->index_buffer[i] = indices->at (i);
	}
}

void SuperficieBarrido::copiar_puntos (std::vector<glm::vec3>* puntosOrigen, GLfloat* puntosDestino) {
	std::vector<glm::vec3>::iterator it;
    unsigned int i = 0;
    for (it = puntosOrigen->begin() ; it != puntosOrigen->end(); it++) {
        puntosDestino[i] = ((*it).x);
        puntosDestino[i+1] = ((*it).y);
        puntosDestino[i+2] = ((*it).z);
        i += 3;
    }
}

void SuperficieBarrido::render (glm::mat4 view_model_matrix) {
/*	for (unsigned int i = 0 ; i < (this->vertex_buffer_size - 2) ; i = i + 3) {
		std::cout << "vertex: ( " << this->vertex_buffer[i] << " , " << this->vertex_buffer[i+1] << " , " << this->vertex_buffer[i+2] << " )" << std::endl;
		std::cout << "normal: ( " << this->normal_buffer[i] << " , " << this->normal_buffer[i+1] << " , " << this->normal_buffer[i+2] << " )" << std::endl;
	}
	std::cout << "index: ";
	for (unsigned int j = 0 ; j < (this->index_buffer_size) ; j++) {
		std::cout << this->index_buffer[j];
		if (j < (this->index_buffer_size - 1)) std::cout << " , ";
			else std::cout << std::endl;
	}
*/	Superficie::render (view_model_matrix);
}

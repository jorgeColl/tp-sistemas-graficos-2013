#include "SuperficieBarrido.h"

#include "PlanoAlgebraico.h"

SuperficieBarrido::SuperficieBarrido (Curva* trayectoriaRecibida, Curva* seccionRecibida, unsigned int pasosTray,
									  unsigned int pasosSec, glm::mat4 transformacionRecibida, Funcion funcionRecibida,
									  myWindow* passed_window) : Superficie (passed_window) {
	
	this->trayectoria = trayectoriaRecibida;
	this->seccion = seccionRecibida;
	this->set_pasos_trayectoria (pasosTray);
	this->set_pasos_seccion (pasosSec);
	this->set_transformacion (transformacionRecibida);
	this->set_funcion (funcionRecibida);
	
	this->crear_puntos();
}

void SuperficieBarrido::set_pasos_trayectoria (unsigned int pasos) {
	this->pasos_trayectoria = pasos;
}

void SuperficieBarrido::set_pasos_seccion (unsigned int pasos) {
	this->pasos_seccion = pasos;
}

void SuperficieBarrido::set_transformacion (glm::mat4 transformacionRecibida) {
	this->transformacion = transformacionRecibida;
}

void SuperficieBarrido::set_funcion (Funcion funcionRecibida) {
	this->funcion = funcionRecibida;
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
			float u = ((i*1.0) / (this->pasos_seccion*1.0)) * this->seccion->cantidad_tramos();
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
	float pasoTangente = ((1.0) / (this->pasos_trayectoria*1.0)) * this->trayectoria->cantidad_tramos();
	
	glm::vec3 puntoTrayectoria = this->trayectoria->damePunto (u);
	glm::mat4 matrizAux = this->funcion.evaluar_en(ui) * this->transformacion;
	this->seccion->transformar(matrizAux);
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

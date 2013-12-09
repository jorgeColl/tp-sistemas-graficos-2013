#pragma once

#include <GL/glew.h>
//#include <GL/freeglut.h>
#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp> 

#include <list>
#include <vector>

#include "Curva.h"
#include "CurvaBezier.h"
#include "CurvaBSpline.h"
#include "Superficie.h"
#include "Funcion.h"


class SuperficieBarrido : public Superficie {
	
	private:
		// atributos de generado de puntos
		Curva* trayectoria;
		Curva* seccion;
		unsigned int pasos_trayectoria;
		unsigned int pasos_seccion;
		std::vector<glm::mat4> transformaciones;
		
		// metodos auxiliares
		bool atributosValidos();
		void inicializarNulo();
		void crear_puntos();
		float preparar_seccion (unsigned int i);
		void cargar_indices (unsigned int i, unsigned int j, std::list<unsigned int>* indices_seccion,
							 std::vector<unsigned int>* indices);
		void cargar_puntos (std::vector<glm::vec3>* vertices, std::vector<glm::vec3>* tangentes, std::vector<glm::vec3>* normales,
							std::vector<glm::vec2>* textura, std::vector<unsigned int>* indices);
		void copiar_puntos_3D (std::vector<glm::vec3>* puntosOrigen, GLfloat* puntosDestino);
		void copiar_puntos_2D (std::vector<glm::vec2>* puntosOrigen, GLfloat* puntosDestino);
		
	protected:
		virtual int cant_puntos_por_salto () { return (this->pasos_seccion + 1); };
	
	public:
		SuperficieBarrido (Curva* trayectoriaRecibida, Curva* seccionRecibida, unsigned int pasosTray,
						   unsigned int pasosSec, std::vector<glm::mat4> transformacionesRecibidas, myWindow* passed_window);
		
		void set_pasos_trayectoria (unsigned int pasos);
		void set_pasos_seccion (unsigned int pasos);
		void set_transformaciones (std::vector<glm::mat4> transformacionesRecibidas);
		
		~SuperficieBarrido ();
		
};

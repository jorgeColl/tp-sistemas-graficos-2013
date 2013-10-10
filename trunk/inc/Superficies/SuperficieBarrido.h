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
		Funcion funcion;
		
		// metodos auxiliares
		void crear_puntos();
		void preparar_seccion (unsigned int i);
		glm::vec3 calcular_normal (glm::vec3 punto);
		void cargar_indices (unsigned int i, unsigned int j, std::list<unsigned int>* indices_seccion,
							 std::vector<unsigned int>* indices);
		void cargar_puntos (std::vector<glm::vec3>* vertices, std::vector<glm::vec3>* normales,
							std::vector<unsigned int>* indices);
		void copiar_puntos (std::vector<glm::vec3>* puntosOrigen, GLfloat* puntosDestino);
		
		
	public:
		SuperficieBarrido (Curva* trayectoriaRecibida, Curva* seccionRecibida, unsigned int pasosTray,
						   unsigned int pasosSec, std::vector<glm::mat4> transformacionesRecibidas, myWindow* passed_window);
		
		void set_pasos_trayectoria (unsigned int pasos);
		void set_pasos_seccion (unsigned int pasos);
		void set_transformaciones (std::vector<glm::mat4> transformacionesRecibidas);
		void set_funcion (Funcion funcionRecibida);
		
		// render heredado de Superficie
		virtual void render (glm::mat4 view_model_matrix);
		
		~SuperficieBarrido ();
		
};

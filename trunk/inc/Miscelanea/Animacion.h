#pragma once

#include <vector>
#include <GL/glew.h>
//#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp> 

#include "Funcion.h"

enum TipoAnimacion {
	Traslacion, Rotacion, Escalado
};

enum VariableAnimacion {
	Xvar, Yvar, Zvar, SINvar
};

class Animacion {
	
	private:
		float tiempo;
		float velocidad;
		VariableAnimacion var;
		std::vector<TipoAnimacion> tipos;
		std::vector<Funcion*> intensidades;
		std::vector<Funcion*> coeficientes;
		std::vector<glm::vec3> vectores;
		
		glm::vec4 animar_punto (glm::vec4 punto);
		float get_variable (glm::vec4 punto);
		float get_coeficiente (glm::vec4 punto, unsigned int i);
		float get_intensidad (glm::vec4 punto, unsigned int i);
		
	public:
		Animacion (VariableAnimacion varRecibida);
		
		void agregar_animacion (TipoAnimacion tipo, Funcion* intensidad,
								Funcion* coeficiente, glm::vec3 vector);
		
		void dar_paso (GLfloat* buffer, int largo, int cantidad_puntos_seccion);
		
		void set_velocidad (float vel) { this->velocidad = vel; };
		bool tiene_variable () { return (this->var != SINvar); };
		
		~Animacion ();
};

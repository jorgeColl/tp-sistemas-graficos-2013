#pragma once

#include <GL/glew.h>
//#include <GL/freeglut.h>
#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp> 

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
		glm::mat4 transformacion;
		Funcion funcion;
		
		// metodos auxiliares
		void crear_puntos();
		
		
	public:
		SuperficieBarrido (Curva* trayectoriaRecibida, Curva* seccionRecibida, unsigned int pasosTray,
						   unsigned int pasosSec, glm::mat4 transformacionRecibida, Funcion funcionRecibida,
						   myWindow* passed_window);
		
		void set_pasos_trayectoria (unsigned int pasos);
		void set_pasos_seccion (unsigned int pasos);
		void set_transformacion (glm::mat4 transformacionRecibida);
		void set_funcion (Funcion funcionRecibida);
		
		// render heredado de Superficie
		
		~SuperficieBarrido ();
		
};

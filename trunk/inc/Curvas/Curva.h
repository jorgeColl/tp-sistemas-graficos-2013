#pragma once

#include <vector>
#include <glm/glm.hpp>

class Curva {
	
	private:
		std::vector<glm::vec3>* puntosControl;
		glm::vec3 miCentro;
		glm::vec3 miOrientacion;
		
		std::vector<glm::vec3>*  puntosControlOriginal;
		glm::vec3 miCentroOriginal;
		glm::vec3 miOrientacionOriginal;
		
		void init (glm::vec3 centro, glm::vec3 orientacion);
		void redondear_valor (float& valor);
		
	protected:
		virtual float calcular_base (int n, int i, float u);
		glm::vec3 transformar_punto (glm::vec3 punto, glm::mat4 matriz);
		
	public:
		Curva (glm::vec3 centro, glm::vec3 orientacion);
		Curva (std::vector<glm::vec3> ptosControl, glm::vec3 centro, glm::vec3 orientacion);
		
		virtual glm::vec3 damePunto (float u);
		glm::vec3 dameTangente (float u, float paso);
		virtual int cantidad_tramos() { return 1; };
		
		glm::vec3 dameCentro ();
		glm::vec3 dameOrientacion ();
		
		// transforma solo los puntos de control, no el centro ni la orientacion de la curva
		virtual void transformar (glm::mat4 matriz);
		
		void centrar (glm::vec3 vector);
		void alinear (glm::vec3 vector);
		
		// vuelve la curva al estado en el que fue creada
		virtual void reset ();
		
		virtual ~Curva ();
		
};

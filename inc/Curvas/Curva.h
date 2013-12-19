#pragma once

#include <vector>
#include <glm/glm.hpp>
#include "Helper.h"

class Curva {
	
	private:
		glm::vec3 miCentro;
		glm::vec3 miOrientacion;
		
		std::vector<glm::vec3>*  puntosControlOriginal;
		glm::vec3 miCentroOriginal;
		glm::vec3 miOrientacionOriginal;
		
		/* Metodos */
		void init (glm::vec3 centro, glm::vec3 orientacion);
		
		enum OrdenBase {
			Cero, PrimeraDerivada, SegundaDerivada
		};
		float calcular_base_en_orden (int n, int i, float u, OrdenBase orden);
		
		glm::vec3 dameVector (float u, OrdenBase orden);
		glm::vec3 dameVectorNoDefinido (float u, OrdenBase orden, glm::vec3 vector);
		glm::vec3 corregirBinormal (glm::vec3 binormal);
		
	protected:
		std::vector<glm::vec3>* puntosControl;
		
		
		virtual float calcular_base (int n, int i, float u) { return 0.0; };
		virtual float calcular_base_primera_derivada (int n, int i, float u) { return 0.0; };
		virtual float calcular_base_segunda_derivada (int n, int i, float u) { return 0.0; };
		
		glm::vec3 transformar_punto (glm::vec3 punto, glm::mat4 matriz);
		
	public:
		Curva (glm::vec3 centro, glm::vec3 orientacion);
		Curva (std::vector<glm::vec3> ptosControl, glm::vec3 centro, glm::vec3 orientacion);
		
		virtual int cantidad_tramos() { return 1; };
		virtual glm::vec3 damePunto (float u);
		
		/* Devuelven vectores normalizados */
		virtual glm::vec3 dameTangente (float u);
		virtual glm::vec3 dameNormal   (float u); // apunta hacia afuera de la curva
		virtual glm::vec3 dameBinormal (float u);
		
		glm::vec3 dameCentro ();
		glm::vec3 dameOrientacion ();
		
		// transforma solo los puntos de control, no el centro ni la orientacion de la curva
		virtual void transformar (glm::mat4 matriz);
		
		virtual void centrar (glm::vec3 vector);
		virtual void alinear (glm::vec3 vector);
		
		// vuelve la curva al estado en el que fue creada
		virtual void reset ();
		
		virtual ~Curva ();
		
};

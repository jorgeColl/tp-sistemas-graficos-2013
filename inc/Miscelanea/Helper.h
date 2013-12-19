#pragma once
#include <glm/glm.hpp>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstdlib>

class  Helper {
	
	public:
	
		template <class Contenedor, class T>
		static void destruir_elementos (Contenedor* miContenedor) {
			typename Contenedor::reverse_iterator it = miContenedor->rbegin();
			while ( it != miContenedor->rend() ) {
				T* elem = (*it);
				it++;
				delete elem;
			}
			miContenedor->clear();
		}
		
		static int factorial (int n);
		static float potencia (float x, int p);
		static float coef_binomial (int n, int i);
		static float num_aleatorio (float lim_inf, float lim_sup);
		static bool is_nan (glm::vec3 vector);
		static bool is_zero (glm::vec3 vector);
		static void redondear_valor (float& valor);
};

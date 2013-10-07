#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>

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
		
};

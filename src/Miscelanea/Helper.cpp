#include "Helper.h"


int Helper::factorial (int n) {
	if (n < 0) return -1;
	if ((n == 1) || (n == 0)) return 1;
	return (factorial(n - 1) * n);
}

float Helper::potencia (float x, int p) {
	if (p == 0) return 1.0;
	if (p == 1) return x;
	if (p < 0) {
		float otro_x = x;
		if ((x == 0.0) || (x == -0.0)) otro_x += 0.001;
		return (1.0 / potencia(otro_x, (-1)*p));
	}
	return (x * potencia(x, p-1));
}

float Helper::coef_binomial (int n, int i) {
	int numerador = factorial(n);
	int denominador = ( factorial(i) * factorial(n-i) );
	return ( (numerador*1.0) / (denominador*1.0) );
}

float Helper::num_aleatorio (float lim_inf, float lim_sup) {
	if ( lim_inf > lim_sup ) return 0.0;
	return ( lim_inf + ((float)rand()/(float)RAND_MAX) * (lim_sup-lim_inf) );
}

bool Helper::is_nan (glm::vec3 vector) {
	return ((vector.x != vector.x) || (vector.y != vector.y) || (vector.z != vector.z));
}

bool Helper::is_zero (glm::vec3 vector) {
	return ((vector.x == 0.0) && (vector.y == 0.0) && (vector.z == 0.0));
}

void Helper::redondear_valor (float& valor) {
	float min_value = 0.00001; // redondeo para reducir errores numericos
	if ((valor < min_value) && (valor > 0.0)) valor = 0.0;
	if ((((-1.0) * valor) < min_value) && (valor < 0.0)) valor = 0.0;
	if (valor == -0.0) valor = 0.0;
}

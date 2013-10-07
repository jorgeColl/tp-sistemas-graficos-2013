#include "Helper.h"


int Helper::factorial (int n) {
	if (n < 0) return -1;
	if ((n == 1) || (n == 0)) return 1;
	return (factorial(n - 1) * n);
}

float Helper::potencia (float x, int p) {
	if (p == 0) return 1.0;
	if (p == 1) return x;
	return (x * potencia(x, p-1));
}

float Helper::coef_binomial (int n, int i) {
	int numerador = factorial(n);
	int denominador = ( factorial(i) * factorial(n-i) );
	return ( (numerador*1.0) / (denominador*1.0) );
}

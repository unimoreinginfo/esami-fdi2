#pragma once
#include <stdlib.h>

typedef struct polinomio {
	int* coeffs;
	size_t size;
} polinomio;

extern double Newton(const polinomio* p, const polinomio* d, double xn, double t,
	int max_iter);
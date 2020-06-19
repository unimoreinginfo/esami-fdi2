#pragma once
#include <stdlib.h>
#include <math.h>

typedef struct polinomio {
	int* coeffs;
	size_t size;
} polinomio;
extern double Secanti(const polinomio* p, double x0, double x1, double t, int max_iter);

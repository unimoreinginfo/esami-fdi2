#include "lib.h"

double helper(const polinomio*, double x0, double x1, double t, int max_iter, int steps);
double calculate(const polinomio* p, double val);

double Secanti(const polinomio* p, double x0, double x1, double t, int max_iter) {

	return helper(p, x0, x1, t, max_iter, 0);

}

double helper(const polinomio* p, double x0, double x1, double t, int max_iter, int steps) {

	if (fabs(x1 - x0) <= t && x0 != x1)
		return x1;

	if (steps == max_iter)
		return x1;

	double fx1 = calculate(p, x1);
	double fx0 = calculate(p, x0);
	double res = x1 - (((x1 - x0) / (fx1 - fx0)) * fx1);

	return helper(p, x1, res, t, max_iter, steps + 1);

}


double calculate(const polinomio* p, double val) {

	double result = 0;

	for (int i = 0; i < p->size; i++) {

		if (i == 0)
			result += p->coeffs[i];
		else
			result += pow(val, i) * p->coeffs[i];

	}

	return result;

}
#include <math.h>
#include "lib.h"

double helper(double xn, double prev_xn, const polinomio* p, const polinomio* d, int iter, int t, int steps);
double calculate(double xn, const polinomio* p);

double Newton(const polinomio* p, const polinomio* d, double xn, double t, int max_iter) {

	return helper(xn, xn, p, d, max_iter, t, 0);

}

double helper(double xn, double prev_xn, const polinomio* p, const polinomio* d, int iter, int t, int steps) {

	if (steps == iter)
		return xn;

	double toll = fabs(xn - prev_xn);
	if (steps > 0 && toll <= t)
		return xn;

	double fxn = calculate(xn, p);
	double dfxn = calculate(xn, d);
	double xn1 = xn - (fxn / dfxn);

	return helper(xn1, xn, p, d, iter, t, steps + 1);

}

double calculate(double xn, const polinomio* p) {

	double result = 0;

	for (int i = 0; i < p->size; i++) {

		if (i == 0)
			result += p->coeffs[i];
		else
			result += pow(xn, i) * p->coeffs[i];

	}

	return result;

}
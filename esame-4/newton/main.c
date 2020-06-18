#include "lib.h"
#define roba malloc(sizeof(Item));

int main() {

	int ca[4] = { 0, -2, 0, 1 };
	int cb[3] = { -2, 0, 3 };
	struct polinomio p = { .coeffs = ca, .size = 4 };
	struct polinomio d = { .coeffs = cb, .size = 3 };

	double n = Newton(&p, &d, 1.00, 0.0000100000, 4);

}

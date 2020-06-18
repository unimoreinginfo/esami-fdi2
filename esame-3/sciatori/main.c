#include <stdio.h>
#include "lib.h"
int main(void) {

	double altezze[4] = { 81.50, 34.20, 100.00, 96.80 };
	double lunghezze[4] = { 100.20, 200.10, 30.10, 150.12 };

	sciatore *couples = Accoppia(altezze, lunghezze, 4);
	for (int i = 0; i < 4; i++) {

		printf("coppia %d: altezza %f, lunghezza %f\n", i + 1, couples[i].a, couples[i].l);

	}

}
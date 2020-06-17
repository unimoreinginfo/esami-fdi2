#include <stdio.h>
#include "lib.h"

int main(void) {

	int array[6] = { 0,1,2,3,4,5 };
	Inverti(array, 6);

	for (int i = 0; i < 6; i++) {

		printf("%d ", array[i]);

	}

}
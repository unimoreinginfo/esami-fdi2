#include <stdio.h>
#include "lib.h"
int main(void) {

	int array[5] = { 5,4,3,2,1 };
	BubbleSort(array, 5);

	for (int i = 0; i < 5; i++) {

		printf("%d", array[i]);

	}

}
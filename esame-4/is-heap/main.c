#include <stdlib.h>
#include "lib.h"

int main(void) {

	Heap* heap = malloc(sizeof(Heap));
	int* data[10] = { 1,2,3,6,7,4,5,8,9,10 };
	heap->data = data;
	heap->size = 10;

	printf("%d", (int)IsHeap(heap));

}
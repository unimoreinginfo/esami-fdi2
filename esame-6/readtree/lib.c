#define _CRT_SECURE_NO_WARNINGS
#include "lib.h"

Node* construct(Node* tree, char* vector, int size);

Node* ReadTree(FILE* f) {

	if (!f)
		return NULL;

	char array[100];
	int index = 0, c;

	while ((c = fgetc(f)) != EOF) {

		array[index++] = c;

	}

	array[index] = '\0';

	return construct(array, 0, index);

}

Node* construct(char* vector, int index, int size) {

	if (index >= size)
		return NULL;

	Node* l = construct(vector, 2 * index + 1, size);
	Node* r = construct(vector, 2 * index + 2, size);

	return CreateRootTree(&vector[index], l, r);

}

#define _CRT_SECURE_NO_WARNINGS
#include "lib.h"

void helper(size_t n, int* numbers, int* current, int index, int size, int count);
void print(int* c, int s);

void GolaCresta(size_t n) {

	/*
		
		Il problema è più facile di quello che sembri:
			basta fare tutte le n-uple di 0,1,2 e stampare soltanto quelle valide!
	
	*/

	int* numbers = malloc(sizeof(int) * 3);
	int* current = malloc(sizeof(int) * n);

	numbers[0] = 0;
	numbers[1] = 1;
	numbers[2] = 2;

	for (int i = 0; i < n; i++)
		current[i] = -1;

	helper(n, numbers, current, 0, n, 0);

	free(numbers);
	free(current);

}

void helper(size_t n, int* numbers, int* current, int index, int size, int count) {

	int invalid = 0;

	if (index == size && count == n) {

		for (int i = 0; i < n; i++) {

			if (i + 2 >= size)
				break;

			if (!((current[i] < current[i + 1] && current[i + 2] < current[i + 1]) || (current[i] > current[i + 1] && current[i + 1] < current[i + 2]))) {
				invalid = 1;
				break;
			}


		}
		if (!invalid)
			print(current, n);

		return;

	}

	for (int i = 0; i < 3; i++) {
		
		current[index] = numbers[i];
		helper(n, numbers, current, index + 1, size, count + 1);
		current[index] = -1;

	}

}

void print(int* c, int s) {

	printf("(");

	for (int i = 0; i < s; i++) {

		if (c[i] != -1) {
			if(i == s - 1)
				printf("%d", c[i]);
			else printf("%d, ", c[i]);
		}

	}

	printf("), ");

}
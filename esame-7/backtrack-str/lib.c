#include "lib.h"

char* _slice(int starting_index, int ending_index, char* array);
void backtrack(char* slice, char* curr, int index, int elems, int size);

void BacktrackStr(int n) {

	char set[27] = "abcdefghijklmnopqrstuvwxyz";
	char* slice = _slice(0, n - 1, set);
	char* curr = calloc(n + 1, sizeof(char));
	curr[n] = 0;

	backtrack(slice, curr, 0, 0, n);

}

void backtrack(char* slice, char* curr, int index, int elems, int size) {

	if (index == size) {

		printf("{ %s }, ", curr);
		return;

	}

	for (int i = 0; i < size; i++) {

		curr[index] = slice[i];
		backtrack(slice, curr, index + 1, elems + 1, size);
		curr[index] = -1;

	}

}

char* _slice(int starting_index, int ending_index, char* array) {
	
	int size = (ending_index + 1) - starting_index;
	char* arr = malloc((ending_index + 2) - starting_index);

	for (int i = starting_index; i < ending_index + 1; i++) {

		arr[i] = array[i];

	}

	arr[size] = 0;

	return arr;

}
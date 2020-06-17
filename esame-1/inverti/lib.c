#include "lib.h"

void helper(int*, int*, int*);

void Inverti(int* v, int v_size) {

	if (!v)
		return;
	if (!v_size)
		return;

	int start = 0;
	int end = v_size - 1;
	
	helper(v, start, end);

	return;

}

void helper(int* v, int starting_index, int ending_index) {

	if (starting_index > ending_index)
		return;

	int tmp = v[starting_index];
	v[starting_index] = v[ending_index];
	v[ending_index] = tmp;

	helper(v, starting_index + 1, ending_index - 1);

}
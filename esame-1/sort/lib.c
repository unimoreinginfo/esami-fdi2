#include "lib.h"

#include <stdlib.h>
#include <stdbool.h>
extern bool QuickSort(int* v, int v_size, int first, int last) {

	if (!v || first < 0 || last >= v_size || last < first)
		return false;

	int i, j, pivot;

	if (first < last) {

		i = first;
		j = last;
		pivot = (i + j) / 2;
		do {

			while (v[i] < v[pivot]) i++;
			while (v[j] > v[pivot]) j--;
			if (i <= j) {
				int tmp = v[i];
				v[i] = v[j];
				v[j] = tmp;
				i++;
				j--;
			}
		} while (i <= j);

		QuickSort(v, v_size, first, j);
		QuickSort(v, v_size, i, last);

	}

	return true;

}
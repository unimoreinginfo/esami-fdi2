#define _CRT_SECURE_NO_WARNINGS
#include "lib.h"

extern bool BubbleSort(int* v, int v_size) {

	if (!v)
		return false;
	if (!(v_size > 0))
		return false;

	int ordered = 0;
	while (v_size > 1 && !ordered) {

		ordered = 1;
		
		for (int i = 0; i < v_size; i++) {

			if (i < v_size - 1) {

					if (v[i] > v[i + 1]) {
						ordered = 0;
						int tmp = v[i];
						v[i] = v[i + 1];
						v[i + 1] = tmp;
					}

			}

		}

		v_size--;

	}

	return true;

}
#define _CRT_SECURE_NO_WARNINGS
#include "lib.h"

int quot(size_t x, size_t y, size_t res, int);

int Quoziente(size_t x, size_t y) {

	if (y == 0)
		return -1;

	if (x < y)
		return 0;

	if (x == y)
		return 1;

	return quot(x, y, 0, 0);

}

int quot(size_t x, size_t y, size_t res, int steps) {

	if (x < y)
		return steps - 1 + res;

	return quot(x - y, y, 1 + (x - y) / y, steps + 1);

}
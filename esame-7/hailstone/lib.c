#include "lib.h"

size_t help(int n, int times);

extern size_t Hailstone(int n) {

	if (n <= 0)
		return 0;

	return help(n, 0);

}

size_t help(int n, int times) {

	if (n == 1) {

		printf("%d", n);
		return times + 1;

	}

	printf("%d, ", n);

	if (n % 2 == 0)
		return help(n / 2, times + 1);
	else
		return help(3 * n + 1, times + 1);

}
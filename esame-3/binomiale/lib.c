#include "lib.h"

int Binomiale(int n, int k) {

	if (n < 0)
		return -1;

	if (k == 0 || k == n)
		return 1;
	if (k > n || k < 0)
		return 0;

	return Binomiale(n - 1, k - 1) + Binomiale(n - 1, k);

}
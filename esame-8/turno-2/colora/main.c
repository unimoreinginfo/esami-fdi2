#include "colora.h"

int main(void) {
	struct Matrix m;
	m.size = 3;
	m.data = malloc(m.size*m.size * sizeof(bool));

	char v[2] = { 'r', 'v' };

	int n = MappaColori(&m, v, 2);
}
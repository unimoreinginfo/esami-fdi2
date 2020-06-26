#include "colora.h"
#include <stdio.h>

void BackTrackMappaColori(const struct Matrix *m, const char *c, size_t c_size, char *colori, size_t n, size_t *nsol) {
	if (n == m->size) {
		(*nsol)++;
		for (size_t i = 0; i < m->size; i++) {
			printf("%lu -> %c; ", i, colori[i]);
		}
		putc('\n', stdout);
		return;
	}
	if (n == 0) {
		for (size_t i = 0; i < c_size; i++) {
			colori[n] = c[i];
			BackTrackMappaColori(m, c, c_size, colori, n + 1, nsol);
		}
	} else {
		for (size_t i = 0; i < c_size; i++) {
			bool ok = true;
			char col = c[i];
			for (size_t area = 0; area < n; area++) {
				if (colori[area] == col && m->data[area + n * m->size] == 1) {
					ok = false;
				}
			}
			if (ok) {
				colori[n] = col;
				BackTrackMappaColori(m, c, c_size, colori, n + 1, nsol);
			}
		}
	}
}

int MappaColori(const struct Matrix *m, const char *c, size_t c_size) {
	char *colori = malloc(m->size);
	size_t nsol = 0;

	BackTrackMappaColori(m, c, c_size, colori, 0, &nsol);

	free(colori);

	return nsol;
}
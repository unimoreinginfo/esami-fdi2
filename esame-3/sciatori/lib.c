#include <math.h>
#include "lib.h"

sciatore* Accoppia(double* altezze, double* lunghezze, int size) {

	if (size <= 0)
		return NULL;

	sciatore* skis = calloc(size, sizeof(sciatore));

	// devo prendere la minima differenza fra tutte, ogni volta che ciclo attraverso gli sciatori
	for (int i = 0; i < size; i++) {

		float min_diff;
		int is_set = 0,
			is = 0, ij = 0;

		for (int k = 0; k < size; k++) {

			double selected_ski = altezze[k];
			if (selected_ski == -1)
				continue;

			for (int j = 0; j < size; j++) {

				if (lunghezze[j] == -1)
					continue;

				double diff = abs(selected_ski - lunghezze[j]);
				if (!is_set) {
					is_set = 1;
					min_diff = diff;
					is = k;
					ij = j;
				}
				if (diff < min_diff) {
					min_diff = diff;
					is = k;
					ij = j;
				}

			}

		}

		sciatore ski = { .a = altezze[is], .l = lunghezze[ij] };
		skis[i] = ski;

		lunghezze[ij] = -1; // sci preso
		altezze[is] = -1; // sciatore ha preso lo sci

	}

	return skis;

}
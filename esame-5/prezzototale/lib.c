#include "lib.h"

void helper(const articolo* a, articolo* current, int index, size_t a_size, int current_price, int sum);
void _print(articolo* current, int a_size);

void TrovaArticoli(const articolo* a, size_t a_size, int sum) {

	articolo* current = calloc(a_size, sizeof(articolo));
	articolo null_item = { .nome = "", .prezzo = 0 };

	for (int i = 0; i < a_size; i++)
		current[i] = null_item;

	helper(a, current, 0, a_size, 0, sum);

	free(current);

}

void helper(const articolo* a, articolo* current, int index, size_t a_size, int current_price, int sum) {

	if (current_price == sum) {

		_print(current, a_size);
		return;

	}
	if (index == a_size)
		return;

	articolo null_item = { .nome = "", .prezzo = 0 };
	articolo current_item = a[index];
	

	if (current_price + current_item.prezzo <= sum) {

		current[index] = current_item;
		helper(a, current, index + 1, a_size, current_price + current_item.prezzo, sum);
		current[index] = null_item;

	}

	helper(a, current, index + 1, a_size, current_price, sum);

}

void _print(articolo* current, int a_size) {

	for (int i = 0; i < a_size; i++) {

		if (current[i].nome)
			printf("%s ", current[i].nome);
		else continue;

	}

	printf("\n");

}
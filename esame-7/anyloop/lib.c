#include "lib.h"

bool _contains(Item* source, Item* node);

bool AnyLoop(Item* l) {

	Item* head = l;
	Item** indexes = malloc(sizeof(Item*) * 100); // tengo gli indirizzi dei nodi qui
	int is_set = 0;
	int index = 0;

	while (l) {

		if (_contains(indexes, index, l))
			return true;

		indexes[index++] = l;

		l = l->next;

	}

	free(indexes);

	return false;

}

bool _contains(Item** source, int size, Item* node) {

	Item* h = source;

	for (int i = 0; i < size; i++) {

		if (source[i] == node)
			return true;

	}
	return false;

}
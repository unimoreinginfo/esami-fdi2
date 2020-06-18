#include "lib.h"

Item *Concatena(Item** ls, int ls_size) {

	Item* latest_el = NULL;
	Item* head = ls[0];

	for (int i = 0; i < ls_size; i++) {

		Item* current_list = ls[i];
		// scorro tutte le liste e becco il loro ultimo elemento
		if (i != 0) {
			latest_el->next = current_list;
		}
		while (current_list) {

			latest_el = current_list;
			current_list = current_list->next;

		}

	}

	return head;

}
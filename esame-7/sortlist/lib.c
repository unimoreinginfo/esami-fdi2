#include "lib.h"

Item* SortList(Item* list) {

	Item* head = list;

	while (list) {

		Item* current = list;
		Item* min = current;
		for (Item* s = list; s != NULL; s = s->next) {

			if (current->value > s->value)
				min = s;

		}

		// swap

		ElemType copy = ElemCopy(&current->value);
		current->value = min->value;
		min->value = copy;

		list = list->next;

	}

	return head;

}
#include "lib.h"

Item* SortList(Item* list) {

	if (!list)
		return NULL;

	Item* head = list;

	while (list) {

		Item* back_here = list;
		Item* min = list;

		for (Item* i = list; i != NULL; i = i->next) {

			if (i->value < min->value)
				min = i;

		}

		list = back_here;

		ElemType tmp = list->value;
		list->value = min->value;
		min->value = tmp;

		list = list->next;

	}

	return head;

}
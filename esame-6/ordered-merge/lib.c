#define _CRT_SECURE_NO_WARNINGS
#include "lib.h"

Item* OrderedMerge(Item* la, Item* lb) {

	Item* head = la, *prev_item = NULL;

	while (la) {

		if (lb->value < la->value) {
			head = InsertHeadList(&lb->value, head);
			lb = lb->next;
		}

		prev_item = la;
		la = la->next;

	}

	if (lb)
		prev_item->next = lb;

	return head;

}
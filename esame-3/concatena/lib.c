#include "lib.h"

Item* Concatena(Item* l1, Item* l2, Item* l3) {

	if (!l1 && !l2 && !l3)
		return NULL;

	Item* head = l1;
	Item* head1 = l1;
	Item* head2 = l2;
	Item* head3 = l3;

	Item* last_item1 = NULL, * last_item2 = NULL;

	if (!l1 && l2 && l3)
		head = l2;

	if (!l1 && !l2 && l3)
		return l3;

	while (l1) {
		last_item1 = l1;
		l1 = l1->next;
	}
	while (l2) {
		last_item1 = InsertBackList(last_item1, &l2->value);
		l2 = l2->next;
	}
	while (l3) {
		last_item1 = InsertBackList(last_item1, &l3->value);
		l3 = l3->next;
	}

	l1 = head1;
	l2 = head2;
	l3 = head3;

	return head;

}
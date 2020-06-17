#include <stdio.h>
#include "lib.h"
int main(void) {

	Item* list = malloc(sizeof(Item));
	Item* l1 = malloc(sizeof(Item));
	Item* l2 = malloc(sizeof(Item));
	Item* l3 = malloc(sizeof(Item));
	Item* l4 = malloc(sizeof(Item));

	list->value = 5;
	list->next = l1;
	l1->value = 6;
	l1->next = l2;
	l2->value = 10;
	l2->next = l3;
	l3->value = 10;
	l3->next = l4;
	l4->value = 100;
	l4->next = CreateEmptyList();

	Item *cut = Taglia(list, 2);
	while (cut) {

		printf("%d ", cut->value);
		cut = cut->next;

	}

}
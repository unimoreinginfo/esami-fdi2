#include <stdio.h>
#include "lib.h"

int main() {

	Item* list = malloc(sizeof(Item));
	Item* list2 = malloc(sizeof(Item));

	list->value = 3;
	list->next = malloc(sizeof(Item));
	list->next->value = 2;
	list->next->next = malloc(sizeof(Item));
	list->next->next->value = 1;
	list->next->next->next = NULL;


	Item* ordered = SortList(list);

}
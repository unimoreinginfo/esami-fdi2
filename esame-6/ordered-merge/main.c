#include <stdio.h>
#include "lib.h"

int main() {

	Item* list = malloc(sizeof(Item));
	Item* list2 = malloc(sizeof(Item));

	list->value = 1;
	list->next = malloc(sizeof(Item));
	list->next->value = 2;
	list->next->next = malloc(sizeof(Item));
	list->next->next->value = 3;
	list->next->next->next = NULL;

	list2->value = -1;
	list2->next = malloc(sizeof(Item));
	list2->next->value = 6;
	list2->next->next = malloc(sizeof(Item));
	list2->next->next->value = 9;
	list2->next->next->next = NULL;
	
	Item* ordered = OrderedMerge(list, list2);
	WriteStdoutList(ordered);

}
#include <stdio.h>
#include "lib.h"
int main(void) {

	Item* list = malloc(sizeof(Item));
	Item* list2 = malloc(sizeof(Item));
	Item* list3 = malloc(sizeof(Item));

	list->value = 5;
	list->next = NULL;
	list2->value = 6;
	list2->next = NULL;
	list3->value = 7;
	list3->next = NULL;

	Item* conc = Concatena(list, list2, list3);

	WriteStdoutList(conc);

}
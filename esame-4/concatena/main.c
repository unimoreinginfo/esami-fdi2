#include "lib.h"
#define roba malloc(sizeof(Item));

int main() {

	Item* list1 = roba;
	list1->value = 1;
	list1->next = NULL;

	Item* list2 = roba;
	list2->value = 2;
	list2->next = NULL;

	Item* list3 = roba;
	list3->value = 3;
	list3->next = NULL;
	
	Item array[3] = { list1, list2, list3 };

	Item* concat = Concatena(array, 3);

}

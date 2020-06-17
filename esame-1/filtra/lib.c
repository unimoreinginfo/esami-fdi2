#include "lib.h"

#include "list_int.h"
#include <stdlib.h>
#include <string.h>

Item* Filtra(Item* list, const char* citta) {

	if (!list)
		return NULL;

	if (!citta)
		return NULL;

	Item* new_list = CreateEmptyList(), * head = CreateEmptyList();
	int is_set = 0;

	while (list) {

		ElemType *e = GetHeadValueList(list);
		if (!strcmp(e->city, citta)) {

			new_list = InsertBackList(list, e);
			if (!is_set) {
				head = new_list;
				is_set = 1;
			}

		}

		list = list->next;

	}

	return head;

}
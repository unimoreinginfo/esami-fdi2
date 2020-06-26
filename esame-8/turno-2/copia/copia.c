#include "list_int.h"

Item* CopiaDaN(const Item* i, int n) {
	if (IsEmptyList(i)) return NULL;
	for (int j = 1; j < n; j++) {
		i = i->next;
		if (IsEmptyList(i)) return NULL;
	}
	Item *ret = CreateEmptyList();
	while (i != NULL) {
		ret = InsertBackList(ret, &i->value);
		i = i->next;
	}
	return ret;
}
#include "lib.h"

bool _contains(Item* source, Item* node);

bool AnyLoop(Item* l) {

	Item* head = l;
	Item* helper_list = NULL;
	Item* helper_list_head = NULL;
	int is_set = 0;

	while (l) {

		if (_contains(helper_list_head, l))
			return true;

		helper_list = InsertBackList(helper_list, &l->value);
		if (!is_set) {
			helper_list_head = helper_list;
			is_set = 1;
		}

		l = l->next;

	}

	return false;

}

bool _contains(Item* source, Item* node) {

	Item *h = source;

	while (source) {

		if (source->value == node->value)
			return true;

		source = source->next;

	}

	source = &h;
	return false;

}
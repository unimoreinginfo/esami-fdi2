#define _CRT_SECURE_NO_WARNINGS
#include "lib.h"

Item* Taglia(Item* l, int n) {

	if (!l)
		return NULL;

	if (n <= 0 || len(l) < n)
		return l;

	Item* head = l;
	int index = 0;
	bool cutting = false;

	while (l) {

		if (index == n)
			break;

		l = l->next;
		index++;
	
	}

	DeleteList(l);
	l = head;
	for (int i = 0; ; i++) {

		if (i == n - 1) {
			l->next = NULL;
			break;
		}
		l = l->next;

	}

	l = head;

	return l;

}

int len(Item* list) {

	int len = 0;
	Item* head = list;

	while (list) {

		list = list->next;
		len++;

	}

	list = head;
	return len;

}
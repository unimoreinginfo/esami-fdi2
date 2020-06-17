#define _CRT_SECURE_NO_WARNINGS
#include "lib.h"

Item* _parse(Item*);

Item* LoadList(const char* filename) {

	FILE* file = fopen(filename, "r");
	if (!file)
		return NULL;

	Item* list = _parse(file);

	return list;

}

Item* _parse(FILE* file) {

	Item* list = CreateEmptyList();

	if (!file)
		return NULL;

	while (1) {

		int x, y, res;
		res = fscanf(file, "%d %d", &x, &y);

		if (res == EOF)
			break;

		ElemType e = { .x = x, .y = y };
		list = InsertBackList(list, &e);

	}

	return list;

}
#define _CRT_SECURE_NO_WARNINGS
#include "lib.h"
Item* _parse(FILE* file);

Item* LoadList(const char* filename) {

	FILE* file = fopen(filename, "r");
	if (!file)
		return NULL;

	return _parse(file);

}

Item* _parse(FILE* file) {

	if (!file)
		return NULL;

	Item* list = CreateEmptyList();

	while (1) {

		float x = 0, y = 0;
		int res = fscanf(file, "%f %f", &x, &y);

		if (res == EOF)
			break;

		ElemType e = { .x = x, .y = y };

		list = InsertBackList(list, &e);

	}

	return list;

}
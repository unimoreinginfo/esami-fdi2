#define _CRT_SECURE_NO_WARNINGS
#include "lib.h"

void do_things(Node* t, FILE* file);

bool SaveTree(Node* t, const char* filename) {

	if (!t)
		return false;

	FILE* file = fopen(filename, "w");
	if (!file)
		return false;

	do_things(t, file);
	fclose(file);

	return true;

}

void do_things(Node* t, FILE* file) {

	if (!t)
		return;

	fprintf(file, "%d ", t->value);

	do_things(t->left, file);
	do_things(t->right, file);

}
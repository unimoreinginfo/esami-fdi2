#define _CRT_SECURE_NO_WARNINGS
#include "lib.h"

Item* _parse(FILE*);
char** list_to_array(Item*, int);
void backtrack(int k, int n, unsigned int index, char** vcurr);
void _print(char**, unsigned int);
bool _is_valid(char**, unsigned int);

int Sottogruppi(const char* filename, int k) {

	FILE* file = fopen(filename, "r");
	if (!file || k < 0)
		return -1;

	int length = 0;
	Item* parsed = _parse(file, &length);
	char** parsed_array = list_to_array(parsed, length);
	char** ret = calloc(sizeof(char*), length);

	backtrack(k, length, 0, 0, parsed_array, ret, 0);

}

void backtrack(int k, int n, unsigned int index, int count, char** actual, char** vcurr, int current_index) {

	if (count == k) {
		_print(vcurr, current_index, n);
		return;
	}

	if (index >= n) {
		if (index % n == current_index)
			return;
	}

		if (_is_valid(vcurr, actual[index % n], n)) {

			strcpy(&vcurr[index % n], &actual[index % n]);
			backtrack(k, n, index + 1, count + 1, actual, vcurr, current_index);

			vcurr[index] = NULL;

		}

		if (index == current_index) {
			current_index++;
			for (int i = 0; i < n; i++) {
				vcurr[i] = NULL;
			}
		}
		

	backtrack(k, n, index + 1, count, actual, vcurr, current_index);

}

void _print(char** v, unsigned int start, unsigned int size) {

	int is_done = 0;

	for (int i = start; ; i++) {

		if (i == size) {
			if (!is_done) is_done = 1;

			i = 0;
		}
			

		if (i == start && is_done) {
			printf("\n");
			return;
		}

		if(v[i])
			printf("%s ", v[i]);

	}

}

bool _is_valid(char** v1, char* current_string, int size) {


	for(int i = 0; i < size; i++){
		
		if (!v1[i])
			continue;
		if (v1[i][0] == current_string[0])
			return false;
		if (abs(v1[i][0] - current_string[0]) == 1)
			return false;

	}

	return true;

}

char** list_to_array(Item* list, int length) {

	char** array = malloc(sizeof(char*) * length);
	Item* top = list;
	int i = 0;

	while (list) {

		array[i] = list->value.name;
		list = list->next;
		i++;

	}

	return array;

}

Item* _parse(FILE* file, int* file_length) {

	if (!file)
		return NULL;

	int is_set = 0;
	Item* parsed_names = CreateEmptyList(), *head = CreateEmptyList();

	while (1) {

		char name[19];
		int res = fscanf(file, "%s", name);
		if (res == EOF)
			break;

		ElemType to_insert = { .name = name };
		parsed_names = InsertBackList(parsed_names, &name);
		if (!is_set) {
			head = parsed_names;
			is_set = 1;
		}

		(*file_length)++;

	}

	return head;

}
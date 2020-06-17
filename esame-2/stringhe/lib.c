#define _CRT_SECURE_NO_WARNINGS
#include "lib.h"

char* substring(char* string, int len);
void backtrack(char* string, char* current, int size, int index);

void BacktrackStr(int n) {

	if (n > 26 || n < 0)
		return;

	char dataset[27] = "abcdefghijklmnopqrstuvwxyz";
	char* split = substring(dataset, n);
	char* see = calloc(n + 1, sizeof(char));
	see[n] = '\0';

	backtrack(split, see, n, 0);

	free(split);
	free(see);

}

void backtrack(char* string, char* current, int size, int index) {

	if (index == size) {
		if(strlen(current) == size)
			printf("{ %s }, ", current);
		
		return;
	}

	for (int i = 0; i < size; i++) {

		current[index] = string[i];
		backtrack(string, current, size, index + 1);
		current[index] = 0;

	}

}

char* substring(char* string, int len) {

	char* str = malloc(sizeof(char) * len + 1);
	for (int i = 0; i < len; i++) {
		str[i] = string[i];
	}

	str[len] = '\0';

	return str;

}
#define _CRT_SECURE_NO_WARNINGS
#include "lib.h"

Node* loadtree(FILE* f);

Node* LoadTree(const char* filename) {

	FILE* f = fopen(filename, "r");
	if (!f)
		return NULL;

	// skip whitespaces: fscanf(file, " %s\n");
	/*char** stuff = malloc(sizeof(char*) * 40);
	for (int i = 0; i < 40; i++)
		stuff[i] = malloc(sizeof(char) * 3); // stringhe lunghe 2 + terminatore

	int index = 0;
	while (1) {

		char str[3];
		int result = fgets(&str, 3, f);
		if (!result || result == '\n')
			break;

		strcpy(stuff[index], &str);
		stuff[index][2] = 0;
		index++;

	}
	
	for (int i = 0; i < index; i++)
		printf("%s", stuff[i]);

	stuff[index] = '\0';*/
	return loadtree(f);

}

Node* loadtree(FILE* f) {

	// costruisco l'albero dalle foglie (postorder)
	// faccio tutto quanto a partire dal basso e poi mi ritrovo con l'indirizzo della radice!
	// perché non ci ho pensato prima wtff
	char current[3];
	char c;
	int is_leaf = 0;

	int result = fgets(&current, 3, f);
	if (!result)
		return NULL;

	if (strlen(current) == 1) {
		return loadtree(f);
		// se fai un file su windows aspettati degli \n messi a cazzo di cane completamente
	}
	
	if (current[0] == '.') {
		c = current[1];
		is_leaf = 1;
	}
	else
		c = current[0];

	if (is_leaf)
		return CreateRootTree(&c, NULL, NULL);

	Node* l = loadtree(f);
	Node* r = loadtree(f);

	return CreateRootTree(&c, l, r);
	

}
#define _CRT_SECURE_NO_WARNINGS
#include "lib.h"

Node* loadtree(FILE* f);

Node* LoadTree(const char* filename) {

	FILE* f = fopen(filename, "r");
	if (!f)
		return NULL;

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

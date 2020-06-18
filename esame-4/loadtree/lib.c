#define _CRT_SECURE_NO_WARNINGS
#include "lib.h"

Node* loadtree_helper(Node* tree, char* value, FILE* file);

Node* LoadTree(const char* filename) {

	FILE* f = fopen(filename, "r");
	if (!f)
		return NULL;

	// skip ws fscanf(file, " %s\n");

	Node* tree = CreateEmptyTree();

	char r[3], q[3];
	r[2] = 0;

	int root = fscanf(f, "%s\n", r);
	if (root == EOF)
		return NULL;
	int is_set = 0;
	Node* head = loadtree_helper(tree, r, f);

	// la cosa migliore sarebbe in realtà leggere tutti i valori da file
	// farci un array e poi trasformare l'array in un albero
	// questo, non so come mai, non funziona

	return head;

}

Node* loadtree_helper(Node* tree, char* value, FILE* file) {

	if (!file)
		return;

	char l[3], rr[3];
	l[2] = 0;
	rr[2] = 0;

	if (value == EOF)
		return;

	char root_char;

	if (strlen(value) == 2)
		root_char = value[1];
	else
		root_char = value[0];

	tree = CreateRootTree(&root_char, CreateEmptyTree(), CreateEmptyTree());

	if (value[0] == '.')
		return;

	int left = fscanf(file, "%s\n", l);
	loadtree_helper(tree->left, l, file);
	int right = fscanf(file, "%s\n", rr);
	loadtree_helper(tree->right, rr, file);

	return tree;

}
#include "lib.h"
void visit(Node*);

void FreeTree(Node* t) {

	visit(t);
	t->right = NULL;
	t->left = NULL;
	free(t);

}

void visit(Node* t) {

	if (!t)
		return;

	printf("%d", t->value);

	if (IsLeafTree(t)) {
		free(t);
		return;
	}


	visit(t->left);
	visit(t->right);

}
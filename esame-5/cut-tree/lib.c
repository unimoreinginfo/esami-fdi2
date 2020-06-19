#define _CRT_SECURE_NO_WARNINGS
#include "lib.h"

void del(Node* t);
void visit(Node* t);

Node* CutTree(Node* t, int cut_value) {

	if (!t)
		return NULL;

	visit(t, NULL, -1, cut_value);

}

void visit(Node* t, Node* prev_node, int lr,  int cut_value) {

	if (!t)
		return;

	if (cut_value == t->value) {
		del(t);
		free(t);
		t->left = NULL;
		t->right = NULL;
		if (lr)
			prev_node->left = NULL;
		else
			prev_node->right = NULL;

		return;
	}


	visit(t->left, t, 1, cut_value);
	visit(t->right, t, 0, cut_value);

}

void del(Node* t) {

	if (IsLeafTree(t)) {

		free(t);
		return;

	}

	del(t->left);
	del(t->right);

}




#define _CRT_SECURE_NO_WARNINGS
#include "lib.h"

void rec(Node* tree, int* times);

void ExpressionTree(Node* tree) {

	int times = 0;
	rec(tree, &times);

	for (int i = 0; i < times; i++)
		printf(")");

}

void rec(Node* tree, int* times) {
	
	if (!tree)
		return;

	ExpressionTree(tree->left);
	
	if (tree->value.is_op) {
		if (tree->right) {
			if (IsLeafTree(tree->right))
				printf("%c ", tree->value.op);
			else { printf("%c (", tree->value.op); (*times)++; }
		}
		if (tree->left) {
			if (IsLeafTree(tree->left))
				printf("%c ", tree->value.op);
			else { printf("%c (", tree->value.op); (*times)++; }
		}
	}
	else
		printf("%d", tree->value.vl);
	
	ExpressionTree(tree->right);

}
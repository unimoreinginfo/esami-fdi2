#include "lib.h"
void visit(Node* t, int* sum);

int PreOrder(Node* t) {

	if (!t)
		return 0;

	int sum = 0;
	visit(t, &sum);

	return sum;

}

void visit(Node* t, int* sum) {

	if (!t)
		return;

	printf("%d ", t->value);
	(*sum) += t->value;

	visit(t->left, sum);
	visit(t->right, sum);

}
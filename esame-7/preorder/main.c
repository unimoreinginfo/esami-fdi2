#include "lib.h"
#define roba malloc(sizeof(Node));

int main() {

	Node* tree = roba;
	Node* tree2 = roba;
	Node* tree3 = roba;
	Node* tree4 = roba;
	Node* tree5 = roba;

	tree->value = 1;
	tree2->value = 2;
	tree3->value = 3;
	tree4->value = 4;
	tree5->value = 5;

	tree->left = tree2;
	tree->right = tree3;

	tree2->right = tree4;
	tree3->right = tree5;

	tree2->left = NULL;
	tree3->left = NULL;
	tree5->left = NULL;
	tree5->right = NULL;
	tree4->right = NULL;
	tree4->left = NULL;

	int p = PreOrder(tree);
	printf("%d", p);

}
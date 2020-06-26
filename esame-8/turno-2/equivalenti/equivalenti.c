#include "tree_int.h"
#include <stdbool.h>
#include <stdlib.h>

#define FOGLIA(ALBERO) ((ALBERO)->left == NULL && (ALBERO)->right == NULL)

bool StessaStruttura(const Node *t1, const Node *t2) {
	if ((t1 == NULL && t2 != NULL) || (t1 != NULL && t2 == NULL)) return false;
	if ((t1->right != NULL || t2->right != NULL) && !StessaStruttura(t1->right, t2->right)) return false;
	if ((t1->left != NULL || t2->left != NULL) && !StessaStruttura(t1->left, t2->left)) return false;
	return true;
}

bool equivVal(const Node *t1, const Node *t2) {
	if (FOGLIA(t1)) {
		if (t1->value%t2->value && t2->value%t1->value) return false;
	}
	else {
		if (t1->value != t2->value) return false;
		if (t1->right != NULL) {
			if (!equivVal(t1->right, t2->right)) return false;
		}
		if (t1->left != NULL) {
			if (!equivVal(t1->left, t2->left)) return false;
		}
	}
	return true;
}

bool Equivalenti(const Node *t1, const Node *t2) {
	if (!StessaStruttura(t1, t2)) return false;
	return equivVal(t1, t2);
}
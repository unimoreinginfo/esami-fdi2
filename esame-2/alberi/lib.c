#define _CRT_SECURE_NO_WARNINGS
#include "lib.h"

Node* InsertBinOrd(const ElemType* e, Node* n);

Node Tree2Bst(Node* t) {

	if (!t)
		return *CreateEmptyTree();
	
	Node* new_tree = CreateEmptyTree();
	get_tree(t, new_tree);

}

Node* get_tree(Node* tree, Node *new_tree) {

	// preorder
	// do, left, right

    InsertBinOrd(tree->value, new_tree);

	get_tree(tree->left, new_tree);
	get_tree(tree->right, new_tree);

}

Node* InsertBinOrd(const ElemType* e, Node* n)
{
    if (IsEmptyTree(n)) {
        return CreateRootTree(e, CreateEmptyTree(), CreateEmptyTree());
    }
    Node* root = n;

    while (true) {
        if (ElemCompare(e, GetRootValueTree(n)) < 0) {
            if (IsEmptyTree(LeftTree(n))) {
                n->left = CreateRootTree(e, CreateEmptyTree(), CreateEmptyTree());
                break;
            }
            else {
                n = LeftTree(n);
            }
        }
        else {
            if (IsEmptyTree(RightTree(n))) {
                n->right = CreateRootTree(e, CreateEmptyTree(), CreateEmptyTree());
                break;
            }
            else {
                n = RightTree(n);
            }
        }
    }

    return root;
}
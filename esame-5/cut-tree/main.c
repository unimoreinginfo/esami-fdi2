#include "lib.h"
#define roba malloc(sizeof(Node));

int main(void) {
    /*
    struct Node
    {
        ElemType value;
        struct Node* left;
        struct Node* right;
    };*/

    Node* f = roba;
    Node* e = roba;
    Node* d = roba;
    Node* c = roba; // {.value = 3, .left = NULL, .right = NULL };
    Node* b = roba; // {.value = 2, .left = NULL, .right = NULL};
    Node* a = roba; // {.value = 1, .left = &b, .right = &c };
    
    f->value = 16;
    f->left = NULL;
    f->right = NULL;

    e->value = 5;
    e->left = NULL;
    e->right = NULL;

    d->value = 10;
    d->left = e;
    d->right = f;

    c->value = 3;
    c->left = NULL;
    c->right = d;

    b->value = 2;
    b->left = NULL;
    b->right = NULL;

    a->value = 1;
    a->left = b;
    a->right = c;

    WriteStdoutPreOrderTree(a);

    CutTree(a, 10);

    WriteStdoutPreOrderTree(a);

}
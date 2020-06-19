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

    Node* c = roba; // {.value = 3, .left = NULL, .right = NULL };
    Node* b = roba; // {.value = 2, .left = NULL, .right = NULL};
    Node* a = roba; // {.value = 1, .left = &b, .right = &c };
    
    c->value = 3;
    c->left = NULL;
    c->right = NULL;

    b->value = 2;
    b->left = NULL;
    b->right = NULL;

    a->value = 1;
    a->left = b;
    a->right = c;

    FreeTree(a);

}
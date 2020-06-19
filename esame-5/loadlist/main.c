#include "lib.h"
#define roba malloc(sizeof(Node));

int main(void) {
    
    Item* list = LoadList("./ciao.txt");
    
    while (list) {

        printf("%f %f\n", list->value.x, list->value.y);
        list = list->next;

    }

}
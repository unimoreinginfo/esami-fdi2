#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "lib.h"

int main() {

	FILE *f = fopen("ciao.txt", "r");
	Node* tree = ReadTree(f);

	WriteStdoutPreOrderTree(tree);

}
#include "lib.h"

bool IsHeap(Heap* h) {

	/*
		
		La funzione deve verificare che l'heap dato sia un min-heap
		Quindi deve verificare che, dato un genitore, i suoi figli siano maggiori di lui
	
	*/

	if (IsEmptyHeap(h))
		return NULL;

	// visita preorder

	for (int i = (h->size - 1) / 2; i > 0; i--) {

		ElemType *left = NULL, *right = NULL;

		if (LeftHeap(i) < h->size)
			left = GetNodeValueHeap(h, LeftHeap(i));
		if (RightHeap(i) < h->size)
			right = GetNodeValueHeap(h, RightHeap(i));

		if (left && !right)
			if (*left < *GetNodeValueHeap(h, i))
				return false;

		if (!left && right)
			if (*right < *GetNodeValueHeap(h, i))
				return false;

		if (left && right) {

			ElemType biggest;

			if (*right > *left)
				biggest = *right;
			else biggest = *left;

			if (biggest < *GetNodeValueHeap(h, i))
				return false;

		}

	}

	return true;

}

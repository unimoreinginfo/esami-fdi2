#pragma once
#include "list_int.h"

typedef struct sciatore {
    double a;
    double l;
}sciatore;

extern sciatore* Accoppia(double* altezze, double* lunghezze, int size);
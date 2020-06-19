#pragma once
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

typedef struct articolo {
    char nome[11];
    int prezzo;
} articolo;

extern void TrovaArticoli(const articolo* a, size_t a_size, int sum);
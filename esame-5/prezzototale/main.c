#include "lib.h"

int main(void) {

	articolo a = { .nome = "Monopoli", .prezzo = 20 };
	articolo b = { .nome = "Carcassone", .prezzo = 30 };
	articolo c = { .nome = "Perudo", .prezzo = 20 };

	articolo art[3] = { a, b, c };
	TrovaArticoli(art, 3, 50);

}
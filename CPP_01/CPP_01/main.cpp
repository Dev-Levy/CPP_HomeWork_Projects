#include <iostream>
#include "feladat1.h"

int main() {

	double x;			// ez a példa
	const char* ertek = "\n\t -123.4567";

	x = feladat1(ertek);
	printf("\n%s -> %f", ertek, x);

	return 0;
}
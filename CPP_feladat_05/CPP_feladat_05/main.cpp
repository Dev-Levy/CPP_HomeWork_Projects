#include "CMyString.h"
int main() {

	CMyString Fruits("AlmaK�rteNarants");
	CMyString Name("P�ter");
	Fruits = Name;
	Fruits.append("K�rte");

	Fruits.shrink_to_fit();

	Fruits.append("K�rte");
	Fruits.append("K�rte");
	return 0;
}
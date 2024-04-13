#include "CMyString.h"
int main() {

	CMyString Fruits("AlmaKörteNarants");
	CMyString Name("Péter");
	Fruits = Name;
	Fruits.append("Körte");

	Fruits.shrink_to_fit();

	Fruits + Name;
	return 0;
}
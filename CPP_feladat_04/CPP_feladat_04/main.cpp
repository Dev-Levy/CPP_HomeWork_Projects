#include "CMyDate.h"
int main() {

	auto asd = CMyDate(2000, 1, 23); //2023 aprilis 4.

	int foo = asd.DayOfTheYear();

	asd.Get();
	asd.Display();

	return 0;
}
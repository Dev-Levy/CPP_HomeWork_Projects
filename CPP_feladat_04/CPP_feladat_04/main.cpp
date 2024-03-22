#include "CMyDate.h"
#include <exception>
#include <iostream>
int main() {
	try
	{
		CMyDate asd(2000, 1, 8);
		asd.Get();
		asd.Display();
		asd.~CMyDate();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}


	return 0;
}

//	Oláh Levente
//
//	  A3C6TV
//
//	 FELADAT: 9
//
//	 VERZIÓ: 1

#include <iostream>
#include <windows.h>
#include "CEmployee.h"
#include "CWageEmployee.h"
#include "CSalesPerson.h"
#include "CManager.h"
#include "Logic.h"



int main() {

	SetConsoleOutputCP(1250);

	Logic logic;

	int n = 0;
	std::unique_ptr<CEmployee> employees[MAXSIZE];

	bool nemkilep = true;
	while (nemkilep)
	{
		std::cout << "\n1: Bevitel\n";
		std::cout << "2: Lista\n";
		std::cout << "3: Fizetés\n";
		std::cout << "4: Fizetés szerint csökkenö lista, átlagfizetés\n";
		std::cout << "5: Fizetés szerint növekvö lista, átlagfizetés\n";
		std::cout << "6: Kilépés\n\n";

		int valasz;
		std::cin >> valasz;
		switch (valasz)
		{
		case 1:
			logic.Bevitel(employees);
			break;
		case 2:
			logic.Lista(employees);
			break;
		case 3:
			logic.Fizetes(employees);
			break;
		case 4:
			logic.FizetesSortAndWriteOut(employees, false);
			break;
		case 5:
			logic.FizetesSortAndWriteOut(employees, true);
			break;
		case 6:
			nemkilep = false;
			break;
		default:
			std::cout << "Wrong input\n";
		}
	}
}	
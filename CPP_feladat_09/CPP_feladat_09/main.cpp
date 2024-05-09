#include <iostream>
#include <windows.h>
#include "CEmployee.h"
#include "CWageEmployee.h"
#include "CSalesPerson.h"
#include "CManager.h"

#define MAXSIZE 10

int main() {

	SetConsoleOutputCP(1250);

	//smart pointert kell használni a tömbhöz
	int n = 0;
	std::unique_ptr<CEmployee> employees[MAXSIZE];

	bool nemkilep = true;
	while (nemkilep)
	{
		std::cout << "1: Bevitel\n";
		std::cout << "2: Lista\n";
		std::cout << "3: Fizetés\n";
		std::cout << "4: Fizetés szerint csökkenö lista, átlagfizetés\n";
		std::cout << "5: Fizetés szerint növekvö lista, átlagfizetés\n";
		std::cout << "6: Kilépés\n";

		int valasz;
		std::cin >> valasz;
		switch (valasz)
		{
		case 1:
			//Bevitel;
			Bevitel(employees, n);
			break;
		case 2:
			//Lista
			break;
		case 3:
			//Fizetés
			break;
		case 4:
			//Fizetés szerint csökkenő lista, átlagfizetés
			break;
		case 5:
			//Fizetés szerint növekvő lista, átlagfizetés
			break;
		case 6:
			nemkilep = false;
			break;
		default:
			std::cout << "Nem jó választás\n";
		}
	}
}

static void Bevitel(std::unique_ptr<CEmployee> employees[], int& n)
{
	if (n < MAXSIZE)
	{
		bool nemkilep = true;
		while (nemkilep)
		{
			std::cout << "1: WageEmployee\n";
			std::cout << "2: SalesPerson\n";
			std::cout << "3: Manager\n";
			std::cout << "4: Kilépés\n";
			int valasz;
			std::cin >> valasz;
			switch (valasz)
			{
				case 1:
					employees[n] = std::make_unique<CWageEmployee>();
					break;
				case 2:
					employees[n] = std::make_unique<CSalesPerson>();
					break;
				case 3:
					employees[n] = std::make_unique<CManager>();
					break;
				case 4:
					nemkilep = false;
					break;
				default:
					std::cout << "Nem jó választás\n";
			}
			employees[n]->Input();
			n++;
		}
	}
	else
	{
		std::cout << "Nincs több hely\n";
	}
}	
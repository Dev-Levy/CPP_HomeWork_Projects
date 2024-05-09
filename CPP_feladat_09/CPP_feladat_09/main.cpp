#include <iostream>
#include <windows.h>

#define MAXSIZE 10

int main() {

	SetConsoleOutputCP(1250);


	//smart pointert kell használni a tömbhöz
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
			std::cout << "Nem megfelelő válasz\n";
		}
	}
}
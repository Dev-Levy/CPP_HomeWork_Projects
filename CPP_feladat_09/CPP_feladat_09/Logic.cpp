
//	Oláh Levente
//
//	  A3C6TV
//
//	 FELADAT: 9
//
//	 VERZIÓ: 1

#include <iostream>
#include <memory>
#include <algorithm>
#include "Logic.h"
#include "CSalesPerson.h"
#include "CManager.h"


Logic::Logic()
{
	n = 0;
}

Logic::~Logic()
{
}
void Logic::Bevitel(std::unique_ptr<CEmployee> employees[])
{
	if (n < MAXSIZE)
	{
		bool nemkilep = true;
		while (nemkilep)
		{
			std::cout << "\n1: WageEmployee\n";
			std::cout << "2: SalesPerson\n";
			std::cout << "3: Manager\n";
			std::cout << "4: Kilépés\n\n";
			int valasz;
			std::cin >> valasz;
			switch (valasz)
			{
			case 1:
				employees[n] = std::make_unique<CWageEmployee>();
				employees[n]->Input();
				n++;
				break;
			case 2:
				employees[n] = std::make_unique<CSalesPerson>();
				employees[n]->Input();
				n++;
				break;
			case 3:
				employees[n] = std::make_unique<CManager>();
				employees[n]->Input();
				n++;
				break;
			case 4:
				nemkilep = false;
				break;
			default:
				std::cout << "Wrong input\n";
			}
		}
	}
	else
	{
		std::cout << "No space left for another employee\n";
	}
}

void Logic::Lista(std::unique_ptr<CEmployee> employees[])
{
	if (n == 0) 
	{
		std::cout << "There are no emlpoyees\n"; 
		return;
	}

	for (int i = 0; i <= n; i++)
	{
		if (employees[i] != nullptr)
		{
			employees[i]->Display();
			std::cout << std::endl;
		}
	}
}

void Logic::Fizetes(std::unique_ptr<CEmployee> employees[])
{
	if (n == 0)
	{
		std::cout << "There are no emlpoyees\n"; 
		return;
	}

	std::cout << "Név: ";
	std::string nev;
	std::cin >> nev;
	for (int i = 0; i < MAXSIZE; i++)
	{
		if (employees[i] != nullptr)
		{
			if (employees[i]->GetName() == nev)
			{
				std::cout << "Fizetés: " << employees[i]->ComputePay() << std::endl;
				return;
			}
		}
	}
	std::cout << "No employee found with the name: " << nev << std::endl;
}

void Logic::FizetesSortAndWriteOut(std::unique_ptr<CEmployee> employees[], bool novekvo)
{
	if (n == 0)
	{
		std::cout << "There are no emlpoyees\n"; 
		return;
	}

	if (novekvo)
	{
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = 0; j < n - i - 1; j++)
			{
				auto asd1 = employees[j]->ComputePay();
				auto asd2 = employees[j + 1]->ComputePay();
				if (asd1 > asd2)
				{
					std::swap(employees[j], employees[j + 1]);
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = 0; j < n - i - 1; j++)
			{
				auto asd1 = employees[j]->ComputePay();
				auto asd2 = employees[j + 1]->ComputePay();
				if (asd1 < asd2)
				{
					std::swap(employees[j], employees[j + 1]);
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		std::cout << i << ". Pay: " << employees[i]->ComputePay()<< "\t\t";
		employees[i]->Display();
		std::cout << std::endl;
	}

	float sum = 0;

	for (int i = 0; i < n; i++)
		sum += employees[i]->ComputePay();

	std::cout << "\nÁtlagfizetés: " << sum / n << std::endl;
}

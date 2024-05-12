
//	Oláh Levente
//
//	  A3C6TV
//
//	 FELADAT: 9
//
//	 VERZIÓ: 1

#pragma once
#include "CEmployee.h"
#include <memory>
#define MAXSIZE 10
class Logic
{
public:
	Logic();
	~Logic();

	void Bevitel(std::unique_ptr<CEmployee> employees[]);
	void Lista(std::unique_ptr<CEmployee> employees[]);
	void Fizetes(std::unique_ptr<CEmployee> employees[]);
	void FizetesSortAndWriteOut(std::unique_ptr<CEmployee> employees[], bool novekvo);
private:
	int n;
};

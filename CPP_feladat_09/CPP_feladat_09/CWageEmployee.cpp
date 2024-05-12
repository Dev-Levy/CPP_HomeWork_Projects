
//	Oláh Levente
//
//	  A3C6TV
//
//	 FELADAT: 9
//
//	 VERZIÓ: 1

#include <iostream>
#include "CWageEmployee.h"

CWageEmployee::CWageEmployee()
{
	m_fWage = 10;
	m_fHours = 40;
}

CWageEmployee::CWageEmployee(const char* nm):CEmployee(nm)
{
	m_fWage = 10;
	m_fHours = 40;
}

void CWageEmployee::SetWage(float wg)
{
	m_fWage = wg;
}

void CWageEmployee::SetHours(float hrs)
{
	m_fHours = hrs;
}

void CWageEmployee::Input(void)
{
	CEmployee::Input();
	std::cout << "Wage: ";
	std::cin >> m_fWage;
	std::cout << "Hours: ";
	std::cin >> m_fHours;
}

float CWageEmployee::ComputePay() const
{
	return m_fWage * m_fHours;
}

void CWageEmployee::Display(void) const
{
	CEmployee::Display();
	std::cout << " Wage: " << m_fWage << " Hours: "<< m_fHours;
}

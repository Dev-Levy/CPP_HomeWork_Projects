
//	Oláh Levente
//
//	  A3C6TV
//
//	 FELADAT: 9
//
//	 VERZIÓ: 1

#include <iostream>
#include "CManager.h"

CManager::CManager()
{
	m_fWeeklySalary = 400;
}

CManager::CManager(const char* nm) :CEmployee(nm)
{
	m_fWeeklySalary = 20;
}

void CManager::SetSalary(float salary)
{
	m_fWeeklySalary = salary;
}

void CManager::Input(void)
{
	CEmployee::Input();
	std::cout << "Salary: ";
	std::cin >> m_fWeeklySalary;
}

float CManager::ComputePay() const
{
	return m_fWeeklySalary;
}

void CManager::Display(void) const
{
	CEmployee::Display();
	std::cout << " Weekly Salary: " << m_fWeeklySalary;
}

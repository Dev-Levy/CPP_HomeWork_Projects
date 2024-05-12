
//	Oláh Levente
//
//	  A3C6TV
//
//	 FELADAT: 9
//
//	 VERZIÓ: 1

#include <iostream>
#include "CEmployee.h"

CEmployee::CEmployee()
{
	m_szName[0] = '\0';
}

CEmployee::CEmployee(const char* nm)
{
	SetName(nm);
}

const char* CEmployee::GetName() const
{
	return m_szName;
}

void CEmployee::SetName(const char* nm)
{
	const char* p = nm;
	int i = 0;
	while (*p != '\0')
	{
		m_szName[i] = *p;
		p++;
		i++;
	}
	m_szName[i] = '\0';
}

void CEmployee::Input(void)
{
	std::cout << "Name: ";
	std::cin >> m_szName;
}

float CEmployee::ComputePay() const
{
	return 0.0f;
}

void CEmployee::Display(void) const
{
	std::cout << "Name: " << m_szName;
}

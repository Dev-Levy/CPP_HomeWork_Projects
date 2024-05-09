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

float CWageEmployee::ComputePay() const
{
	return m_fWage * m_fHours;
}

#include "CManager.h"

CManager::CManager()
{
	m_fWeeklySalary = 400;
}

CManager::CManager(const char* nm):CEmployee(nm)
{
	m_fWeeklySalary = 20;
}

void CManager::SetSalary(float salary)
{
	m_fWeeklySalary = salary;
}

float CManager::ComputePay() const
{
	return m_fWeeklySalary;
}

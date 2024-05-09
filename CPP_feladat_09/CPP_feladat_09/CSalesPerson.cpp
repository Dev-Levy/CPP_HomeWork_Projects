#include "CSalesPerson.h"

CSalesPerson::CSalesPerson()
{
	m_fCommission = 5;
	m_fSalesMade = 0;
}

CSalesPerson::CSalesPerson(const char* nm):CWageEmployee(nm)	
{
	m_fCommission = 5;
	m_fSalesMade = 0;
}

void CSalesPerson::SetCommision(float comm)
{
	m_fCommission = comm;
}

void CSalesPerson::SetSales(float sales)
{
	m_fSalesMade = sales;
}

float CSalesPerson::ComputePay() const
{
	return CWageEmployee::ComputePay() + m_fCommission * m_fSalesMade;
}

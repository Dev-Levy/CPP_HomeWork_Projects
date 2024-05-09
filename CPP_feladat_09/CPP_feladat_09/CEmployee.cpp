#include "CEmployee.h"
#include <string.h>

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

float CEmployee::ComputePay() const
{
	return 0.0f;
}

#include "CMyString.h"

CMyString::CMyString()
{
}

CMyString::CMyString(const char* psz)
{
}

void CMyString::setat(unsigned index, char ch)
{
}

void CMyString::operator=(const CMyString& str1)
{
	if (this == &str1)
	{
		m_nDataLength = str1.m_nDataLength;

	}

}


//	Ol�h Levente
//
//	  A3C6TV
//
//	 FELADAT: 8
//
//	 VERZI�: 2

#include "CMyVectorException.h"

CMyVectorException::CMyVectorException(const char* s)
{
	m_message = s;
}

const char* CMyVectorException::what(void) const
{
	return m_message.c_str();
}

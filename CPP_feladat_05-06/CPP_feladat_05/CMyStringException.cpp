#include "CmyStringException.h"

//	Ol�h Levente
//
//	  A3C6TV
//
//	 FELADAT: 5-6.
//
//	 VERZI�: 3

CMyStringException::CMyStringException(const char* s) : m_message(s) {}


const char* CMyStringException::what() const
{
	return m_message.c_str();
}




#include "CmyStringException.h"

//	Ol�h Levente
//
//	  A3C6TV
//
//	 FELADAT: 5
//
//	 VERZI�: 1

CMyStringException::CMyStringException(const char* s) : m_message(s) {}


const char* CMyStringException::what() const
{
	return m_message.c_str();
}




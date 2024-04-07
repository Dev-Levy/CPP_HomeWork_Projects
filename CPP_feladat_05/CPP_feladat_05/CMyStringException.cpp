#include "CmyStringException.h"

//	Oláh Levente
//
//	  A3C6TV
//
//	 FELADAT: 5
//
//	 VERZIÓ: 1

CMyStringException::CMyStringException(const char* s) : m_message(s) {}


const char* CMyStringException::what() const
{
	return m_message.c_str();
}




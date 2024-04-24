#include "CmyStringException.h"

//	Oláh Levente
//
//	  A3C6TV
//
//	 FELADAT: 5-6.
//
//	 VERZIÓ: 6

//	Oláh Levente
//
//	  A3C6TV
//
//	 FELADAT: 8
//
//	 VERZIÓ: 1

CMyStringException::CMyStringException(const char* s) : m_message(s) {}


const char* CMyStringException::what() const
{
	return m_message.c_str();
}




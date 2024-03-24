

//	Oláh Levente
//
//	  A3C6TV
//
//	 FELADAT: 4
//
//	 VERZIÓ: 2


#include "CMyDateException.h"

CMyDateException::CMyDateException(const char* s)
{
	msg = s;
}

const char* CMyDateException::what(void)
{
	return msg;
}

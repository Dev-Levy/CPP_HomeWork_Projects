

//	Ol�h Levente
//
//	  A3C6TV
//
//	 FELADAT: 4
//
//	 VERZI�: 1


#include "CMyDateException.h"

CMyDateException::CMyDateException(const char* s)
{
	msg = s;
}

const char* CMyDateException::what(void)
{
	return msg;
}

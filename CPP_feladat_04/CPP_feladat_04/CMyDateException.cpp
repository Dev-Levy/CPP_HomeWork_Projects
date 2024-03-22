#include "CMyDateException.h"

CMyDateException::CMyDateException(const char* s)
{
	msg = s;
}

const char* CMyDateException::what(void)
{
	return msg;
}

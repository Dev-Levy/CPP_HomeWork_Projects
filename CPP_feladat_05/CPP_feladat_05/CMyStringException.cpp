#include "CmyStringException.h"


CMyStringException::CMyStringException(const char* s) : m_message(s) {}


const char* CMyStringException::what() const
{
	return m_message.c_str();
}




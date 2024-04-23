#include "CMyVectorException.h"

CmyVectorException::CmyVectorException(const char* s)
{
	m_message = s;
}

const char* CmyVectorException::what(void) const
{
	return m_message.c_str();
}

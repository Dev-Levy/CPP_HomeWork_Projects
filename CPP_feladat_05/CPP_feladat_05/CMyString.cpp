#include "CMyString.h"
#include <string.h>

CMyString::CMyString()
{
	m_pchData = nullptr;
	m_nDataLength = 0;
	m_nAllocLength = 0;
	m_iCounter = 0;
}

CMyString::CMyString(const char* psz)
{
	if (psz == nullptr)
		CMyString();
	m_pchData = new char[strlen(psz) + 1];
	m_nDataLength = size();
	m_nAllocLength = capacity();
	m_iCounter++;
}

CMyString::CMyString(char ch, size_t repeat)
{
}

CMyString::CMyString(const CMyString& str)
{
}

CMyString::~CMyString()
{
}

size_t CMyString::size() const
{
	return size_t();
}

size_t CMyString::capacity() const
{
	char *p = m_pchData;
	while (*p != '\0')
	{
		p++;
	}
	return p - m_pchData;
}

void CMyString::clear()
{
	*m_pchData = '\0';
	m_nDataLength = 0;
}

char CMyString::getat(size_t index) const
{
	return 0;
}

void CMyString::setat(size_t index, char ch)
{
}

bool CMyString::empty() const
{
	return false;
}

void CMyString::display() const
{
}

void CMyString::shrink_to_fit()
{
}

void CMyString::reverse()
{
}

void CMyString::append(const char* psz, unsigned offset, unsigned count)
{
}

CMyString& CMyString::operator=(const CMyString& str)
{
	return *this;
}

unsigned CMyString::objcount()
{
	return m_iCounter;
}

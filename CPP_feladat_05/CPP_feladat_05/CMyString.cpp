#include "CMyString.h"
#include "CMyStringException.h"
#include <string.h>
#include <string>
#include <iostream>

#ifndef NDEBUG
unsigned CMyString::m_iCounter;
#endif

CMyString::CMyString()
{
	m_nDataLength = 0;
	m_nAllocLength = 1;
	m_pchData = new char[m_nAllocLength];
	m_pchData[0] = '\0';
}

CMyString::CMyString(const char* psz)
{
	if (psz == nullptr)
	{
		m_nDataLength = 0;
		m_nAllocLength = 1;
		m_pchData = new char[m_nAllocLength];
		m_pchData[0] = '\0';
	}
	else
	{
		m_nDataLength = strlen(psz);
		m_nAllocLength = m_nDataLength + 1;
		m_pchData = new char[m_nAllocLength];
		strcpy_s(m_pchData, m_nAllocLength, psz);
	}
}

CMyString::CMyString(char ch, size_t repeat)
{
}

CMyString::CMyString(const CMyString& str)
{
}

CMyString::~CMyString()
{
	delete[] m_pchData;
	m_iCounter--;
}

size_t CMyString::size() const
{
	return capacity() - 1;
}

size_t CMyString::capacity() const
{
	char* p = m_pchData;
	while (*p != '\0') 
	{
		p++;
	}

	return p - m_pchData + 1;
}

void CMyString::clear()
{
	*m_pchData = '\0';
	m_nDataLength = 0;
}

char CMyString::getat(size_t index) const
{
	if (index > size())
		throw CMyStringException(CMyStringException::ErrOutOfRange);


	return m_pchData[index];
}

void CMyString::setat(size_t index, char ch)
{
	if (index > size())
		throw CMyStringException(CMyStringException::ErrOutOfRange);
	else if (ch == '\0')
		throw CMyStringException(CMyStringException::ErrInvalidChar);

	m_pchData[index] = ch;
}

bool CMyString::empty() const
{
	if (*m_pchData == '\0')
		return true;
	else
		return false;
}

void CMyString::display() const
{
	std::cout << m_pchData << std::endl;
}

void CMyString::shrink_to_fit()
{
	char* p = new char[size() + 1];
	delete[] m_pchData;
	m_pchData = p;
}

void CMyString::reverse()
{
	int sizeOfString = size();
	for (int i = 0; i < sizeOfString / 2; i++)
	{
		char temp = m_pchData[i];
		m_pchData[i] = m_pchData[sizeOfString - i - 1];
		m_pchData[sizeOfString - i - 1] = temp;
	}
}

void CMyString::append(const char* psz, unsigned offset, unsigned count)
{
	if (psz != nullptr)
	{

	}
}

CMyString& CMyString::operator=(const CMyString& str)
{
	if (this == &str)
		return *this;


}

#ifndef NDEBUG
unsigned CMyString::objcount()
{
	return m_iCounter;
}
#endif
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
	try
	{
		m_nDataLength = 0;
		m_nAllocLength = 1;
		m_pchData = new char[m_nAllocLength];
		m_pchData[0] = '\0';
	}
	catch (const std::bad_alloc&)
	{
		throw;
	}
	
}

CMyString::CMyString(const char* psz)
{
	try
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
	catch (const std::bad_alloc&)
	{
		throw;
	}
	
}

CMyString::CMyString(char ch, size_t repeat)
{
	if (ch == '\0')
		throw CMyStringException(CMyStringException::ErrInvalidChar);
	else if (repeat == 0)
		throw CMyStringException(CMyStringException::ErrCount);

	try
	{
		m_nDataLength = repeat;
		m_nAllocLength = m_nDataLength + 1;
		m_pchData = new char[m_nAllocLength];
		for (size_t i = 0; i < m_nDataLength; i++)
		{
			m_pchData[i] = ch;
		}
		m_pchData[m_nDataLength] = '\0';
	}
	catch (const std::bad_alloc&)
	{
		throw;
	}
	
}

CMyString::CMyString(const CMyString& str)	
{
	try
	{
		if (str.m_nDataLength == 0)
		{
			m_nDataLength = 0;
			m_nAllocLength = 1;
			m_pchData = new char[m_nAllocLength];
			m_pchData[0] = '\0';
		}
		else
		{
			m_nDataLength = str.m_nDataLength;
			m_nAllocLength = m_nDataLength + 1;
			m_pchData = new char[m_nAllocLength];
			strcpy_s(m_pchData, m_nAllocLength, str.m_pchData);
		}
	}
	catch (const std::bad_alloc&)
	{
		throw;
	}
	
}

CMyString::~CMyString()
{
	delete[] m_pchData;
	m_iCounter--;
}

size_t CMyString::size() const
{
	return m_nDataLength;
}

size_t CMyString::capacity() const
{
	return m_nAllocLength;
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
	else if(str.m_nDataLength == 0)
	{
		clear();
		return *this;
	}
	else if (m_nAllocLength > str.m_nAllocLength)
	{
		m_nDataLength = str.m_nDataLength;
		strcpy_s(m_pchData, sizeof(m_pchData), str.m_pchData);
		return *this;
	}
	else
	{
		delete[] m_pchData;
		m_nDataLength = str.m_nDataLength;
		m_nAllocLength = m_nDataLength + 1;
		m_pchData = new char[m_nAllocLength];
		strcpy_s(m_pchData, m_nAllocLength, str.m_pchData);
	}
}

#ifndef NDEBUG
unsigned CMyString::objcount()
{
	return m_iCounter;
}
#endif
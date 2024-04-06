#include "CMyString.h"
#include <string.h>
#include <string>
#include <iostream>

unsigned CMyString::m_iCounter;

CMyString::CMyString()
{
	//m_pchData = ("").data; //üres string
	m_nDataLength = 0;
	m_nAllocLength = 0;
	m_iCounter = 0;
}

CMyString::CMyString(const char* psz)
{
	if (psz == nullptr)
		CMyString();
	else 
	{
		m_pchData = new char[strlen(psz) + 1];
	}
		
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
	return p - m_pchData;
}

void CMyString::clear()
{
	*m_pchData = '\0';
	m_nDataLength = 0;
}

char CMyString::getat(size_t index) const
{
	if (index > size())
		//throw asdasdasd;


	return m_pchData[index];
}

void CMyString::setat(size_t index, char ch)
{
	if (index > size())
		//throw asdasdasd;
		;
	else if (ch == '\0')
		//throw asdasdasd;

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
}

void CMyString::reverse()
{
	char temp;
	for (size_t i = 0; i < size(); i++)
	{
		temp = m_pchData[i];
		m_pchData[i] = m_pchData[size() - i];
		m_pchData[size() - i] = temp;
	}
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
//done

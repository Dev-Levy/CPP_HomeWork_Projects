#include "CMyString.h"
#include "CMyStringException.h"
#include <string.h>
#include <string>
#include <iostream>

//	Oláh Levente
//
//	  A3C6TV
//
//	 FELADAT: 5-6.
//
//	 VERZIÓ: 2


#ifdef MYDEBUG
unsigned CMyString::m_iCounter = 0;
#endif

CMyString::CMyString()
{
	try
	{
		m_nDataLength = 0;
		m_nAllocLength = 1;
		m_pchData = new char[m_nAllocLength];
		m_pchData[0] = '\0';
#ifdef MYDEBUG
		m_iCounter++;
#endif
	}
	catch (const std::bad_alloc&)
	{
		throw CMyStringException(CMyStringException::ErrUnexpected);
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
#ifdef MYDEBUG
			m_iCounter++;
#endif
		}
		else
		{
			m_nDataLength = strlen(psz);
			m_nAllocLength = m_nDataLength + 1;
			m_pchData = new char[m_nAllocLength];
			strcpy_s(m_pchData, m_nAllocLength, psz);
#ifdef MYDEBUG
			m_iCounter++;
#endif
		}
	}
	catch (const std::bad_alloc&)
	{
		throw CMyStringException(CMyStringException::ErrUnexpected);
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
#ifdef MYDEBUG
		m_iCounter++;
#endif
	}
	catch (const std::bad_alloc&)
	{
		throw CMyStringException(CMyStringException::ErrUnexpected);
	}

}

CMyString::CMyString(const CMyString& str)
{
	try
	{
		if (str.m_nDataLength == 0)
		{
			delete[] m_pchData;
			m_nDataLength = 0;
			m_nAllocLength = 1;
			m_pchData = new char[m_nAllocLength];
			m_pchData[0] = '\0';
#ifdef MYDEBUG
			m_iCounter++;
#endif
			//*this = CMyString(str.m_pchData); //??
		}
		else
		{
			delete[] m_pchData;
			m_nDataLength = str.m_nDataLength;
			m_nAllocLength = m_nDataLength + 1;
			m_pchData = new char[m_nAllocLength];
			strcpy_s(m_pchData, m_nAllocLength, str.m_pchData);
#ifdef MYDEBUG
			m_iCounter++;
#endif
			//*this = CMyString(str.m_pchData); //??
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
#ifdef MYDEBUG
	m_iCounter--;
#endif
}

size_t CMyString::size() const
{
	return m_nDataLength;
}

size_t CMyString::capacity() const
{
	return m_nAllocLength;
}

const char* CMyString::c_str() const
{
	return m_pchData;
}

void CMyString::clear()
{
	m_pchData[0] = '\0';
	m_nDataLength = 0;
}

char CMyString::getat(size_t index) const
{
	if (index >= size())
		throw CMyStringException(CMyStringException::ErrOutOfRange);
	return m_pchData[index];
}

void CMyString::setat(size_t index, char ch)
{
	if (index >= size())
		throw CMyStringException(CMyStringException::ErrOutOfRange);
	else if (ch == '\0')
		throw CMyStringException(CMyStringException::ErrInvalidChar);

	m_pchData[index] = ch;
}

bool CMyString::empty() const
{
	if (m_pchData[0] == '\0')
		return true;
	else
		return false;
}

void CMyString::display() const
{
	std::cout << m_pchData << std::flush;
}

void CMyString::shrink_to_fit()
{
	m_nAllocLength = m_nDataLength + 1;
	char* p = new char[m_nAllocLength];
	strcpy_s(p, m_nAllocLength, m_pchData);
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


	if (psz != nullptr && m_pchData != psz)
	{
		if (count == UINT32_MAX)
			count = strlen(psz);

		if (count == 0)
			throw CMyStringException(CMyStringException::ErrCount);
		else if (offset > strlen(psz))
			throw CMyStringException(CMyStringException::ErrOutOfRange);
		else if (count > strlen(psz))
			throw CMyStringException(CMyStringException::ErrUnexpected);

		//ha belefér
		if (m_nDataLength + count < m_nAllocLength)
		{
			strncat_s(m_pchData, m_nAllocLength, psz + offset, count);
			m_nDataLength += count;
		}
		//ha nem fér bele
		else
		{
			char* p = new char[m_nDataLength + count + 1];
			strcpy_s(p, m_nDataLength + count + 1, m_pchData);
			strncat_s(p, m_nDataLength + count + 1, psz + offset, count);
			delete[] m_pchData;
			m_pchData = p;
			m_nDataLength += count;
			m_nAllocLength = m_nDataLength + 1;
		}

	}
}

CMyString& CMyString::operator=(const CMyString& str)
{
	if (this == &str)
		return *this;
	else if (str.m_nDataLength == 0)
	{
		clear();
		return *this;
	}
	else if (str.m_nAllocLength < m_nAllocLength)
	{
		m_nDataLength = str.m_nDataLength;
		strcpy_s(m_pchData, str.m_nAllocLength, str.m_pchData);
		return *this;
	}
	else
	{
		delete[] m_pchData;
		m_nDataLength = str.m_nDataLength;
		m_nAllocLength = m_nDataLength + 1;
		m_pchData = new char[m_nAllocLength];
		strcpy_s(m_pchData, m_nAllocLength, str.m_pchData);
		return *this;
	}
}

#ifdef MYDEBUG
unsigned CMyString::objcount()
{
	return m_iCounter;
}
#endif
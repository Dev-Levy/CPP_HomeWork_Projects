#include "CMyString.h"
#include "CMyStringException.h"
//#include <string.h>
#include <string>
#include <iostream>

//	Oláh Levente
//
//	  A3C6TV
//
//	 FELADAT: 5-6.
//
//	 VERZIÓ: 6


#ifdef MYDEBUG
unsigned CMyString::m_iCounter = 0;
#endif

void CMyString::emptyStringMaker()
{
	m_nDataLength = 0;
	m_nAllocLength = 1;
	m_pchData = new char[m_nAllocLength];
	m_pchData[0] = '\0';
}

CMyString::CMyString()
{
	try
	{
		emptyStringMaker();
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
			emptyStringMaker();
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
			emptyStringMaker();
#ifdef MYDEBUG
			m_iCounter++;
#endif
		}
		else
		{
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
	if (psz != nullptr && m_pchData != psz && psz[0] != '\0')
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

CMyString CMyString::substring(size_t pos, size_t length) const
{
	int sizeOfString = size();
	if (pos > sizeOfString)
		throw CMyStringException(CMyStringException::ErrOutOfRange);
	else if (length == UINT32_MAX || length == UINT64_MAX || pos + length > sizeOfString)
		length = sizeOfString - pos;

	CMyString temp;
	temp.m_nDataLength = length;
	temp.m_nAllocLength = length + 1;
	temp.m_pchData = new char[temp.m_nAllocLength];
	strncpy_s(temp.m_pchData, temp.m_nAllocLength, m_pchData + pos, temp.m_nDataLength);
	temp.m_pchData[temp.m_nDataLength] = '\0';
	return temp;
}

void CMyString::swap(CMyString& str)
{
	char* p = m_pchData;
	m_pchData = str.m_pchData;
	str.m_pchData = p;

	size_t temp = m_nDataLength;
	m_nDataLength = str.m_nDataLength;
	str.m_nDataLength = temp;

	temp = m_nAllocLength;
	m_nAllocLength = str.m_nAllocLength;
	str.m_nAllocLength = temp;
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
		m_nDataLength = str.m_nDataLength;
		m_nAllocLength = m_nDataLength + 1;
		m_pchData = new char[m_nAllocLength];
		strcpy_s(m_pchData, m_nAllocLength, str.m_pchData);
		return *this;
	}
}
//done
CMyString::CMyString(CMyString&& str) noexcept
{
	m_pchData = str.m_pchData;
	m_nDataLength = str.m_nDataLength;
	m_nAllocLength = str.m_nAllocLength;

	str.emptyStringMaker();

#ifdef MYDEBUG
	m_iCounter++;
#endif
}
//done
CMyString& CMyString::operator=(CMyString&& str) noexcept
{
	if (this != &str) {
		m_pchData = str.m_pchData;
		m_nDataLength = str.m_nDataLength;
		m_nAllocLength = str.m_nAllocLength;

		str.emptyStringMaker();
	}
	return *this;
}
//done???
char& CMyString::operator[](size_t index)
{
	if (index >= size())
		throw CMyStringException(CMyStringException::ErrOutOfRange);
	return m_pchData[index];
}
//done???
const char& CMyString::operator[](size_t index) const
{
	if (index >= size())
		throw CMyStringException(CMyStringException::ErrOutOfRange);
	return m_pchData[index];
}
//done
bool CMyString::operator==(const CMyString& str)
{
	return strcmp(this->c_str(), str.c_str()) == 0;
}
//done
CMyString::operator const char* ()
{
	return m_pchData;
}
//done
CMyString& CMyString::operator+=(const CMyString& str)
{
	append(str.c_str());
	return *this;
}
//done
CMyString& CMyString::operator+=(const char* p)
{
	append(p);
	return *this;
}
//done
CMyString CMyString::operator+(const CMyString& str)
{
	CMyString result(*this);  
	result.append(str.c_str()); 
	return result;
}
//done
bool CMyString::operator<(const CMyString& str) const
{
	bool result = std::strcmp(this->c_str(), str.c_str()) < 0;
	return result;
}
bool CMyString::operator>(const CMyString& str) const
{
	bool result = std::strcmp(this->c_str(), str.c_str()) > 0;
	return result;
}


#ifdef MYDEBUG

void CMyString::clearobjcount()
{
	m_iCounter = 0;
}

unsigned CMyString::objcount()
{
	return m_iCounter;
}
#endif

std::ostream& operator<<(std::ostream& os, CMyString& s)
{
	os << s.c_str();
	return os;
}

std::istream& operator>>(std::istream& is, CMyString& s)
{
	char temp[MAXSTRCIN];
	is.getline(temp, MAXSTRCIN);
	s = temp;
	return is;
}

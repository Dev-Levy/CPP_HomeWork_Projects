
//	Oláh Levente
//
//	  A3C6TV
//
//	 FELADAT: 8
//
//	 VERZIÓ: 1

#include <algorithm>
#include <iostream>
#include "CMyVector.h"
#include "CMyVectorException.h"
#include "CMyString.h"


template CMyVector <int>;
template CMyVector <double>;
template CMyVector <char>;
template CMyVector <CMyString>;

template <class T>
CMyVector<T>::CMyVector(void)
{
	m_pData = nullptr;
	m_nSize = 0;
	m_nCapacity = 0;
	in = 0;
}

template <class T>
CMyVector<T>::CMyVector(unsigned n)
{
	m_pData = new T[n]();
	m_nSize = n;
	m_nCapacity = n;
	in = 0;
}

template <class T>
CMyVector<T>::~CMyVector(void)
{
	delete[] m_pData;
}


template <class T>
T& CMyVector<T>::operator[](unsigned n)
{
	if (m_nSize == 0)
		throw CMyVectorException(CMyVectorException::ErrEmpty);
	else if (n >= m_nSize)
		throw CMyVectorException(CMyVectorException::ErrIndex);

	in = n + 1;
	return m_pData[n];
}

template <class T>
CMyVector<T>& CMyVector<T>::operator=(const CMyVector<T>& r)
{
	if (r.m_nSize == 0)
		return *this;

	else if (r.m_nSize <= m_nCapacity)
	{
		for (size_t i = 0; i < r.m_nSize; i++)
			m_pData[i] = r.m_pData[i];
		for (size_t i = r.m_nSize; i < m_nSize; i++)
			m_pData[i] = {};

		m_nSize = r.m_nSize;
		return *this;
	}
	else //r.m_nSize > m_nCapacity
	{
		m_pData = new T[r.m_nSize];
		for (size_t i = 0; i < r.m_nSize; i++)
			m_pData[i] = r.m_pData[i];

		m_nSize = r.m_nSize;
		m_nCapacity = r.m_nSize;
		return *this;
	}
}

template <class T>
void CMyVector<T>::clear()
{
	for (size_t i = 0; i < m_nSize; i++)
		m_pData[i] = {};

	m_nSize = 0;
}

template <class T>
void CMyVector<T>::push_back(const T& value)
{
	if (in < m_nSize)
	{
		m_pData[in] = value;
		in++;
	}
	else if (in == m_nSize && m_nSize < m_nCapacity)
	{
		m_pData[in] = value;
		m_nSize++;
		in++;
	}
	else //in == m_nSize && m_nSize == m_nCapacity
	{
        unsigned cap = std::max(4, static_cast<int>(m_nCapacity * 1.5));
		m_nCapacity = cap;

		T* asd = new T[m_nCapacity];
		for (size_t i = 0; i < m_nSize; i++)
			asd[i] = m_pData[i];

		m_pData = asd;
		m_pData[in] = value;
		m_nSize++;
		in++;
	}
}

template <class T>
void CMyVector<T>::list()
{
	for (unsigned i = 0; i < m_nSize; i++)
	{
		auto asd = m_pData[i];
		std::cout << i + 1 << ".: " << asd << std::endl;
	}
}

template <class T>
void CMyVector<T>::sort(bool f)
{
	if (f)
		std::sort(m_pData, m_pData + m_nSize, [](const T& a, const T& b) {return a < b; });
	else
		std::sort(m_pData, m_pData + m_nSize, [](const T& a, const T& b) {return a > b; });
}

template <class T>
void CMyVector<T>::resize(unsigned n)
{
	if (n == 0)
		clear();
	else if (n < m_nCapacity)
	{
		for (size_t i = m_nSize; i < n; i++)
			m_pData[i] = {};
		m_nSize = n;
	}
	else
	{
		T* asd = new T[n]();
		for (size_t i = 0; i < m_nSize; i++)
			asd[i] = m_pData[i];

		m_pData = asd;
		m_nSize = n;
		m_nCapacity = n;
	}

}

template <class T>
unsigned CMyVector<T>::size(void) const
{
	return m_nSize;
}

template <class T>
unsigned CMyVector<T>::capacity(void) const
{
	return m_nCapacity;
}

template <class T>
void CMyVector<T>::shrink_to_fit()
{
	m_nCapacity = m_nSize;
	T* asd = new T[m_nCapacity];
	for (size_t i = 0; i < m_nSize; i++)
		asd[i] = m_pData[i];

	//itt csak def értékek a többibe, vagy törlés?
	delete[] m_pData;

	m_pData = asd;
}
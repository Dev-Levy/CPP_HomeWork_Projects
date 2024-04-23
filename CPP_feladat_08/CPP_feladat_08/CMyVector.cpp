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
}

template <class T>
CMyVector<T>::CMyVector(unsigned n)
{
	m_pData = new T[n];
	m_nSize = n;
	m_nCapacity = n;
}

template <class T>
CMyVector<T>::~CMyVector(void)
{
	delete[] m_pData;
}


template <class T>
T& CMyVector<T>::operator[](unsigned n)
{
	if (n >= m_nSize)
		throw CMyVectorException(CmyVectorException::ErrIndex);
	return m_pData[n];
}

template <class T>
CMyVector<T>& CMyVector<T>::operator=(const CMyVector<T>& r)
{
	if (this == &r || &r.m_nSize == 0)
		return *this;

	else if (r.m_nSize <= m_nCapacity)
		std::strcpy_c(m_pData, r.m_nSize, r.m_pData);

	else
	{
		delete[] m_pData;
		m_pData = new T[r.m_nSize];
		std::strcpy_c(m_pData, r.m_nSize, r.m_pData);
	}
}

template <class T>
void CMyVector<T>::clear() 
{
	m_nSize = 0;

	//def értékek a többibe
}

template <class T>
void CMyVector<T>::push_back(const T& value) 
{

}

template <class T>
void CMyVector<T>::list() 
{
	for (size_t i = 0; i < m_nSize; ++i)
	{
		std::cout << i << '.: ' << this[i]
	}
}

template <class T>
void CMyVector<T>::sort(bool f) 
{

}

template <class T>
void CMyVector<T>::resize(unsigned n) 
{

}

template <class T>
unsigned CMyVector<T>::size(void) const 
{
	return m_nSize / sizeof(T);
}

template <class T>
unsigned CMyVector<T>::capacity(void) const 
{
	return m_nCapacity / sizeof(T);
}

template <class T>
void CMyVector<T>::shrink_to_fit() 
{

}
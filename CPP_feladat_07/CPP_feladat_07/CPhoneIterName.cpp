#include "CPhoneIterName.h"
#include <algorithm>
#include <cctype>


CPhoneIterName::CPhoneIterName(CPhoneList& m) : m_cpList(&m), m_iCurrIndex(-1)
{
	indexArray = new unsigned[m.m_iFirstEmpty];
	n = m.m_iFirstEmpty;
	for (size_t i = 0; i < m.m_iFirstEmpty; i++)
		indexArray[i] = i;

	std::sort(indexArray, indexArray + n, [&](unsigned i, unsigned j) { return cmp(m.m_rArray[i], m.m_rArray[j]); });
}

CPhoneIterName::~CPhoneIterName()
{
	delete[] indexArray;
}

Record* CPhoneIterName::begin()
{
	if (n == 0)
		return nullptr;

	m_iCurrIndex = 0;
	auto p = &m_cpList->m_rArray[indexArray[m_iCurrIndex]];
	return p;
}

Record* CPhoneIterName::prev()
{
	if (m_iCurrIndex - 1 < 0)
		return nullptr;

	m_iCurrIndex--;
	auto p = &m_cpList->m_rArray[indexArray[m_iCurrIndex]];
	return p;
}

Record* CPhoneIterName::next()
{
	auto p = ++(*this);
	return p;
}

Record* CPhoneIterName::end()
{
	if (n == 0)
		return nullptr;

	m_iCurrIndex = n - 1;
	auto p = &m_cpList->m_rArray[indexArray[m_iCurrIndex]];
	return p;
}

int CPhoneIterName::size()
{
	return n;
}

Record* CPhoneIterName::search(const char* key)
{
	Record* p = begin();
	while(strcmp(p->name, key) != 0 && p)
		p = next();

	if (p == nullptr)
		return nullptr;
	else
		return p;
}

Record* CPhoneIterName::operator++()
{
	if (m_iCurrIndex + 1 == n)
		return nullptr;

	m_iCurrIndex++;
	auto p = &m_cpList->m_rArray[indexArray[m_iCurrIndex]];
	return p;
}

bool CPhoneIterName::cmp(const Record& r1, const Record& r2)
{
	std::string name1 = r1.name;
	std::string name2 = r2.name;

	std::transform(name1.begin(), name1.end(), name1.begin(),
		[](unsigned char c) { return std::tolower(c); });

	std::transform(name2.begin(), name2.end(), name2.begin(),
		[](unsigned char c) { return std::tolower(c); });

	return name1 < name2;
}


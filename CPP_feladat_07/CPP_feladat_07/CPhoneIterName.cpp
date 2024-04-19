#include "CPhoneIterName.h"
#include <string.h>


CPhoneIterName::CPhoneIterName(CPhoneList& m) : m_cpList(&m)
{
	m_iCurrIndex = 0;

	for (size_t i = 0; i < MAXLENGTH; i++)
		indexArray[i] = i;

	auto cmp = [this](unsigned index1, unsigned index2)->bool {
		return strcmp(this->m_cpList->m_rArray[index1].name, this->m_cpList->m_rArray[index2].name) < 0;
	};

	mysort(indexArray, MAXLENGTH, cmp);
}

CPhoneIterName::~CPhoneIterName()
{
}

Record* CPhoneIterName::begin()
{
	return nullptr;
}

Record* CPhoneIterName::prev()
{
	return nullptr;
}

Record* CPhoneIterName::next()
{
	return nullptr;
}

Record* CPhoneIterName::end()
{
	return nullptr;
}

int CPhoneIterName::size()
{
	return 0;
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
	return next();
}

void CPhoneIterName::mysort(unsigned* array, unsigned size, std::function<bool(unsigned, unsigned)> cmp)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = i + 1; j < size; j++)
		{
			if (cmp(array[i], array[j]))
			{
				unsigned temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}


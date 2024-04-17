#include "CPhoneIterName.h"


CPhoneIterName::CPhoneIterName(CPhoneList& m)
{
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

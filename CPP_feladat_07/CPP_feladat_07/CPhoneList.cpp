
//	Oláh Levente
//
//	  A3C6TV
//
//	 FELADAT: 7
//
//	 VERZIÓ: 1

#include "CPhoneList.h"
#include "CPhoneIterName.h"
#include <iostream>

CPhoneList::CPhoneList()
{
	m_iFirstEmpty = 0;
}

int CPhoneList::append(const Record& newrec)
{
	if (m_iFirstEmpty < MAXLENGTH)
	{
		m_rArray[m_iFirstEmpty] = newrec;
		m_iFirstEmpty++;
		return OK;
	}
	return NOK;
}

void CPhoneList::displayname()
{
	CPhoneIterName iter(*this);
	Record* rec = iter.begin();
	while (rec != nullptr)
	{
		std::cout << *rec;
		rec = ++iter;
	}
}

std::ostream& operator<<(std::ostream& os, Record& r)
{
	os << std::endl << r.name << ";" << r.number;
	return os;
}

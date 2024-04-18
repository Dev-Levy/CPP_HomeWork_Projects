#include "CPhoneList.h"

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

}

std::ostream& operator<<(std::ostream& os, Record& r)
{
	os << std::endl << r.name << ";" << r.number;
	return os;
}

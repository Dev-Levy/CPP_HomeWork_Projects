#include "CMyDate.h"
#include "CMyDateException.h"
#include <iostream>
#include <string>

//	Oláh Levente
//
//	  A3C6TV
//
//	 FELADAT: 4
//
//	 VERZIÓ: 2

CMyDate::CMyDate()
{
	m_iYear = 1970;
	m_iMonth = 1;
	m_iDay = 1;
	IsLeapYear = m_iYear % 4 == 0 && (m_iYear % 100 != 0 || m_iYear % 400 == 0);
}

CMyDate::CMyDate(int year, int month, int day)
{
	SetYear(year);
	SetMonth(month);
	SetDay(day);
}

CMyDate::~CMyDate()
{
}

void CMyDate::Get()
{
	try
	{
		std::string ev;
		std::cout << "Ev: ";
		std::cin >> ev;

		std::string honap;
		std::cout << "Honap: ";
		std::cin >> honap;

		std::string nap;
		std::cout << "Nap: ";
		std::cin >> nap;


		*this = CMyDate(std::stoi(ev), std::stoi(honap), std::stoi(nap));
	}
	catch (...)
	{
		throw CMyDateException(CMyDateException::ErrUnexpected);
	}

}

void CMyDate::Display()
{
	std::string months[12] = { "januar", "februar", "marcius", "aprilis", "majus", "junius", "julius", "augusztus", "szeptember", "oktober", "november", "december" };

	std::cout << m_iYear << " " << months[m_iMonth - 1] << " " << m_iDay << "." << std::flush;
}

int CMyDate::DayOfTheYear()
{
	int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	daysInMonth[1] = IsLeapYear ? 29 : 28;
	int sum = 0;

	for (int i = 0; i < m_iMonth - 1; i++)
	{
		sum += daysInMonth[i];
	}
	sum += m_iDay;

	return sum;
}

void CMyDate::SetYear(int year)
{
	if (year < 1970)
		throw CMyDateException(CMyDateException::ErrMinYear);

	m_iYear = year;
	IsLeapYear = m_iYear % 4 == 0 && (m_iYear % 100 != 0 || m_iYear % 400 == 0);
}
void CMyDate::SetMonth(int month)
{
	if (month > 0 && month < 13)
		m_iMonth = month;
	else if (month < 1)
		throw CMyDateException(CMyDateException::ErrMinMonth);
	else if (month > 12)
		throw CMyDateException(CMyDateException::ErrMaxMonth);
}
void CMyDate::SetDay(int day)
{
	switch (m_iMonth)
	{
		//31 days
	case 1:	case 3:	case 5:	case 7:	case 8:	case 10: case 12:
		if (day > 0 && day < 32)
			m_iDay = day;
		else if (day < 1)
			throw CMyDateException(CMyDateException::ErrMinDay);
		else if (day > 31)
			throw CMyDateException(CMyDateException::ErrMaxDay);
		break;

		//30 days
	case 4:	case 6:	case 9:	case 11:
		if (day > 0 && day < 31)
			m_iDay = day;
		else if (day < 1)
			throw CMyDateException(CMyDateException::ErrMinDay);
		else if (day > 30)
			throw CMyDateException(CMyDateException::ErrMaxDay);
		break;

		//february
	case 2:
		if (IsLeapYear)
		{
			if (day > 0 && day < 30)
				m_iDay = day;
			else if (day < 1)
				throw CMyDateException(CMyDateException::ErrMinDay);
			else if (day > 29)
				throw CMyDateException(CMyDateException::ErrMaxDay);
		}
		else
		{
			if (day > 0 && day < 29)
				m_iDay = day;
			else if (day < 1)
				throw CMyDateException(CMyDateException::ErrMinDay);
			else if (day > 28)
				throw CMyDateException(CMyDateException::ErrMaxDay);
		}

	default:
		break;
	}
}

int CMyDate::GetDay() const
{
	return m_iDay;
}
int CMyDate::GetMonth() const
{
	return m_iMonth;
}
int CMyDate::GetYear() const
{
	return m_iYear;
}
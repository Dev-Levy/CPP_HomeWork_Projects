#pragma once

//	Oláh Levente
//
//	  A3C6TV
//
//	 FELADAT: 4
//
//	 VERZIÓ: 2

class CMyDate
{
public:
	CMyDate();
	CMyDate(int year, int month, int day);
	~CMyDate();
	void Get();
	void Display();
	int DayOfTheYear(); //nap sorszáma az évben
	int GetDay() const;
	int GetMonth() const;
	int GetYear() const;
	void SetYear(int year);
	void SetMonth(int month);
	void SetDay(int day);
private:
	int m_iDay;
	int m_iMonth;
	int m_iYear;
	bool IsLeapYear;
};
//következõ oldal void Display(); 
//dátum kiírása: <év><SP><hónap neve><SP><nap><.>,
//ahol SP a szóköz, hónap neve kisbetûvel, ékezet nélkül
//pl.: 2023 aprilis 4.
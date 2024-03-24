#pragma once

//	Ol�h Levente
//
//	  A3C6TV
//
//	 FELADAT: 4
//
//	 VERZI�: 2

class CMyDate
{
public:
	CMyDate();
	CMyDate(int year, int month, int day);
	~CMyDate();
	void Get();
	void Display();
	int DayOfTheYear(); //nap sorsz�ma az �vben
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
//k�vetkez� oldal void Display(); 
//d�tum ki�r�sa: <�v><SP><h�nap neve><SP><nap><.>,
//ahol SP a sz�k�z, h�nap neve kisbet�vel, �kezet n�lk�l
//pl.: 2023 aprilis 4.
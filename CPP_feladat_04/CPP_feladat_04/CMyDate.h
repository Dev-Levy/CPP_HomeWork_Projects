#pragma once
class CMyDate
{
public:
	CMyDate();
	CMyDate(int year, int month, int day);
	~CMyDate();
	void Get();
	void Display();
	int DayOfTheYear(); //nap sorsz�ma az �vben
	int GetDay();
	int GetMonth();
	int GetYear();
	void SetDay(int day);
	void SetMonth(int month);
	void SetYear(int year);
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
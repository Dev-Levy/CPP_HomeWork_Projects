#pragma once
#include <exception>

//	Ol�h Levente
//
//	  A3C6TV
//
//	 FELADAT: 4
//
//	 VERZI�: 2

class CMyDateException : public std::exception
{
public:
	CMyDateException(const char* s);
	const char* what(void);		// kiv�tel ok�nak lek�rdez�se

	static constexpr const char* ErrMinYear = "Hiba: �v kisebb, mint 1970!";
	static constexpr const char* ErrMinDay = "Hiba: nap kisebb, mint 1!";
	static constexpr const char* ErrMaxDay = "Hiba:  nap nagyobb, mint az adott h�nap napjainak sz�ma!";
	static constexpr const char* ErrMinMonth = "Hiba: h�nap kisebb, mint 1!";
	static constexpr const char* ErrMaxMonth = "Hiba:  h�nap nagyobb, mint 12!";
	static constexpr const char* ErrUnexpected = "Hiba: nem v�rt hiba!";

private:
	const char* msg;			// kiv�tel ok�nak, a sz�veg�nek t�rol�sa
};

#pragma once
#include <exception>

//	Oláh Levente
//
//	  A3C6TV
//
//	 FELADAT: 4
//
//	 VERZIÓ: 2

class CMyDateException : public std::exception
{
public:
	CMyDateException(const char* s);
	const char* what(void);		// kivétel okának lekérdezése

	static constexpr const char* ErrMinYear = "Hiba: év kisebb, mint 1970!";
	static constexpr const char* ErrMinDay = "Hiba: nap kisebb, mint 1!";
	static constexpr const char* ErrMaxDay = "Hiba:  nap nagyobb, mint az adott hónap napjainak száma!";
	static constexpr const char* ErrMinMonth = "Hiba: hónap kisebb, mint 1!";
	static constexpr const char* ErrMaxMonth = "Hiba:  hónap nagyobb, mint 12!";
	static constexpr const char* ErrUnexpected = "Hiba: nem várt hiba!";

private:
	const char* msg;			// kivétel okának, a szövegének tárolása
};

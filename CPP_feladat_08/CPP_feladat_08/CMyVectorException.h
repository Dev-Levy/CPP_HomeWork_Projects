
//	Oláh Levente
//
//	  A3C6TV
//
//	 FELADAT: 8
//
//	 VERZIÓ: 2

#pragma once
#include <string>
class CMyVectorException
{
public:
	CMyVectorException(const char* s);
	const char* what(void) const;

	static constexpr const char* ErrIndex = "Hiba: index hiba!";
	static constexpr const char* ErrEmpty = "Hiba: üres a vector";
	static constexpr const char* ErrUnexpected = "Hiba: nem várt hiba!";

private:
	std::string m_message;
};
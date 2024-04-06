#pragma once
#include <string>
class CMyStringException
{
	public: 
		CMyStringException(); //�? 
		CMyStringException(const char * s);
		~CMyStringException(); //�? 
		const char * what(void) const;

		static constexpr const char* ErrOutOfRange = "Hiba: index hiba!";
		static constexpr const char* ErrInvalidChar = "Hiba: �rv�nytelen karakter!";
		static constexpr const char* ErrCount = "Hiba: karakterek sz�ma 0!";
		static constexpr const char* ErrUnexpected = "Hiba: nem v�rt hiba!";

		  //adattagok: kiv�tel ok�nak t�rol�sa, hiba �zenetek 
	private:
		std::string m_message;
};
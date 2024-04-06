#pragma once
#include <string>
class CMyStringException
{
	public: 
		CMyStringException(const char * s);
		const char * what(void) const;

		static constexpr const char* ErrOutOfRange = "Hiba: index hiba!";
		static constexpr const char* ErrInvalidChar = "Hiba: �rv�nytelen karakter!";
		static constexpr const char* ErrCount = "Hiba: karakterek sz�ma 0!";
		static constexpr const char* ErrUnexpected = "Hiba: nem v�rt hiba!";

	private:
		std::string m_message;
};
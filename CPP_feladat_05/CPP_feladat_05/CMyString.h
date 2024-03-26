#pragma once
class CMyString
{
private:
	char* m_pchData;
	unsigned m_nDataLength;
public:
	CMyString();
	CMyString(const char* psz);
	void setat(unsigned index, char ch);
	void operator=(const CMyString& str1);
};
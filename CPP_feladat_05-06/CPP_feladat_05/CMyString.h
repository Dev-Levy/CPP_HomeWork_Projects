#pragma once

//	Oláh Levente
//
//	  A3C6TV
//
//	 FELADAT: 5-6.
//
//	 VERZIÓ: 2
#ifndef MYDEBUG
#define MYDEBUG
#endif

class CMyString {
public:
	CMyString();
	CMyString(const char* psz);
	CMyString(char ch, size_t repeat = 1);
	CMyString(const CMyString& str);

	~CMyString();
	size_t size() const;
	size_t capacity() const;
	const char* c_str() const;

	void clear();
	char getat(size_t index) const;
	void setat(size_t index, char ch);
	bool empty() const;
	void display() const;
	void shrink_to_fit();
	void reverse();

	void append(const char* psz,
		unsigned offset = 0,
		unsigned count = ~0);

	CMyString& operator=(const CMyString& str);
	CMyString(CMyString&& str);
	CMyString& operator=(CMyString&& str);
	char& operator[](size_t index);
	bool operator==(const CMyString& str);
	operator const char* ();
	CMyString& operator+=(const CMyString& str);
	CMyString& operator+=(const char* p);
	CMyString operator+(const CMyString& str);

	CMyString substring(size_t pos, size_t length = ~0) const;
	void swap(CMyString& str);

#ifdef MYDEBUG
	static void cleanobjcount();
	static unsigned objcount();
#endif											

private: char* m_pchData;
	   size_t m_nDataLength;
	   size_t m_nAllocLength;
#ifdef MYDEBUG
	   static unsigned m_iCounter;
#endif
};
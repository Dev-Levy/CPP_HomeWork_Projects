#include "pch.h"
#include "CppUnitTest.h"
extern class CMyString {
public:
	CMyString();								//def. constr 
	CMyString(const char* psz);					//string (�\0�-ra v�gz�d� char t�mb) a bement. Ha nullptr, �res string j�n l�tre
	CMyString(char ch, size_t repeat = 1);		//ErrCount: repeat=0, ErrInvalidChar: ch=�\0� 
	CMyString(const CMyString& str);			//copy construktor, �res str eset�n �res string lesz.
	//m_nAllocLength nem az str.m_nAllocLength-hez igazodik,
	//hanem az str.m_nDataLength �rt�k�hez! 
	~CMyString();								//destruktor, delete haszn�lata ! 
	size_t size() const;						//string hossz lek�rdez�se (m_nDataLength) 
	size_t capacity() const;					//t�nylegesen lefoglalt mem�ria m�rete (m_nAllocLength)

	void clear();								//t�rli a stringet, de a lefoglalt mem�ria v�ltozatlan marad
	char getat(size_t index) const;				//karakter lek�rdez�se , ErrOutOfRange: index hiba
	void setat(size_t index, char ch);			//karakter be�ll�t�sa , ErrOutOfRange: index hiba, ErrInvalidChar: ch=�\0
	bool empty() const;							//igaz, ha �res a string
	void display() const;						//ki�rja a stringet a cout-ra, �res string eset�n nem �r ki semmit 
	void shrink_to_fit();						//megsz�nteti a karakterl�nc felesleges mem�ria kapacit�s�t 
	void reverse();

	void append(const char* psz,				//hozz�f�zend� string (�\0�-ra v�gz�d� char t�mb)
		unsigned offset = 0,					//psz melyik poz�ci�j�t�l f�zze hozz�
		unsigned count = ~0);					//h�ny darab karaktert f�zz�n hozz�
	//Hozz�f�zi a stringet a param�terek szerint. Nem
	//m�dosul a lefoglalt mem�ria (m_nAllocLength) a c�l
	//ter�leten, ha lehets�ges! �res objektumhoz is
	//hozz�f�zi. psz = nullptr vagy saj�t maga eset�n
	//nem csin�l semmit
	//ErrCount: count=0, ErrOutOfRange: ha offset
	//nagyobb, mint a psz hossza


	CMyString& operator=(const CMyString& str); //�rt�kad�s oper�tor. �res str eset�n �res lesz az
	//objektum. Nem m�dosul a lefoglalt mem�ria
	//(m_nAllocLength) a c�l ter�leten, ha lehets�ges!
	//Saj�t maga eset�n nem csin�l semmit.
#ifndef NDEBUG
	static unsigned objcount();					//objektum sz�ml�l�t adja vissza, CSAK debug
#endif										//m�dban l�tezik, ha MYDEBUG defini�lva van!	

private: char* m_pchData;						//felhaszn�lt mem�ri�ra mutat, ahol string van
	   size_t m_nDataLength;					//hossz, '\0' n�lk�l, size() 
	   size_t m_nAllocLength;					//t�nylegesen lefoglalt mem�ria, capacity() 
#ifndef NDEBUG
	   static unsigned m_iCounter;				//obj.sz�ml�l�, CSAK debug m�dban l�tezik
#endif
};
extern class CMyStringException 
{
public:
	CMyStringException(const char* s);
	const char* what(void) const;

	static constexpr const char* ErrOutOfRange = "Hiba: index hiba!";
	static constexpr const char* ErrInvalidChar = "Hiba: �rv�nytelen karakter!";
	static constexpr const char* ErrCount = "Hiba: karakterek sz�ma 0!";
	static constexpr const char* ErrUnexpected = "Hiba: nem v�rt hiba!";

private:
	std::string m_message;
};


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(CtorTest1)
		{
			CMyString a;
			Assert::AreEqual((size_t)0, a.size());
		}
		TEST_METHOD(CtorTest2)
		{
			CMyString a("alma");
			Assert::AreEqual((size_t)4, a.size());
		}
		TEST_METHOD(CtorTest3)
		{
			CMyString a('s', 2);
			Assert::AreEqual((size_t)2, a.size());
		}
		TEST_METHOD(CtorTest4)
		{
			CMyString a("alma");
			CMyString b(a);
			Assert::AreEqual((size_t)4, b.size());
		}
		TEST_METHOD(CtorTest5)
		{
			CMyString a;
			CMyString b(a);
			Assert::AreEqual((size_t)0, b.size());
		}
		TEST_METHOD(GetatTest1)
		{
			CMyString a("alma");
			Assert::AreEqual('a', a.getat(0));
		}
		TEST_METHOD(GetatTest2)
		{
			CMyString a("p�ter");
			Assert::AreEqual('r', a.getat(4));
		}
		TEST_METHOD(SetatTest1)
		{
			CMyString a("alma");
			a.setat(0, 'b');
			Assert::AreEqual('b', a.getat(0));
		}
		TEST_METHOD(SetatTest2)
		{
			CMyString a("k�rte");
			a.setat(4, 'c');
			Assert::AreEqual('c', a.getat(4));
		}
		TEST_METHOD(EmptyTest1)
		{
			CMyString a("k�rte");
			Assert::AreEqual(false, a.empty());
		}
		TEST_METHOD(EmptyTest2)
		{
			CMyString a;
			//Assert::AreEqual(true, a.empty());
			Assert::AreEqual((size_t)0, a.size());
		}
		TEST_METHOD(EmptyTest3)
		{
			CMyString a("");
			Assert::AreEqual(true, a.empty());
		}
		TEST_METHOD(OperatorTest1)
		{
			CMyString a("alma");
			CMyString b("k�r");
			a = b;
			Assert::AreEqual((size_t)3, a.size());
		}
	};
}

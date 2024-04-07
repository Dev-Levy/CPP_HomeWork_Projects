#include "pch.h"
#include "CppUnitTest.h"
extern class CMyString {
public:
	CMyString();								//def. constr 
	CMyString(const char* psz);					//string (’\0’-ra végzõdõ char tömb) a bement. Ha nullptr, üres string jön létre
	CMyString(char ch, size_t repeat = 1);		//ErrCount: repeat=0, ErrInvalidChar: ch=’\0’ 
	CMyString(const CMyString& str);			//copy construktor, üres str esetén üres string lesz.
	//m_nAllocLength nem az str.m_nAllocLength-hez igazodik,
	//hanem az str.m_nDataLength értékéhez! 
	~CMyString();								//destruktor, delete használata ! 
	size_t size() const;						//string hossz lekérdezése (m_nDataLength) 
	size_t capacity() const;					//ténylegesen lefoglalt memória mérete (m_nAllocLength)

	void clear();								//törli a stringet, de a lefoglalt memória változatlan marad
	char getat(size_t index) const;				//karakter lekérdezése , ErrOutOfRange: index hiba
	void setat(size_t index, char ch);			//karakter beállítása , ErrOutOfRange: index hiba, ErrInvalidChar: ch=’\0
	bool empty() const;							//igaz, ha üres a string
	void display() const;						//kiírja a stringet a cout-ra, üres string esetén nem ír ki semmit 
	void shrink_to_fit();						//megszünteti a karakterlánc felesleges memória kapacitását 
	void reverse();

	void append(const char* psz,				//hozzáfûzendõ string (’\0’-ra végzõdõ char tömb)
		unsigned offset = 0,					//psz melyik pozíciójától fûzze hozzá
		unsigned count = ~0);					//hány darab karaktert fûzzön hozzá
	//Hozzáfûzi a stringet a paraméterek szerint. Nem
	//módosul a lefoglalt memória (m_nAllocLength) a cél
	//területen, ha lehetséges! Üres objektumhoz is
	//hozzáfûzi. psz = nullptr vagy saját maga esetén
	//nem csinál semmit
	//ErrCount: count=0, ErrOutOfRange: ha offset
	//nagyobb, mint a psz hossza


	CMyString& operator=(const CMyString& str); //értékadás operátor. Üres str esetén üres lesz az
	//objektum. Nem módosul a lefoglalt memória
	//(m_nAllocLength) a cél területen, ha lehetséges!
	//Saját maga esetén nem csinál semmit.
#ifndef NDEBUG
	static unsigned objcount();					//objektum számlálót adja vissza, CSAK debug
#endif										//módban létezik, ha MYDEBUG definiálva van!	

private: char* m_pchData;						//felhasznált memóriára mutat, ahol string van
	   size_t m_nDataLength;					//hossz, '\0' nélkül, size() 
	   size_t m_nAllocLength;					//ténylegesen lefoglalt memória, capacity() 
#ifndef NDEBUG
	   static unsigned m_iCounter;				//obj.számláló, CSAK debug módban létezik
#endif
};
extern class CMyStringException 
{
public:
	CMyStringException(const char* s);
	const char* what(void) const;

	static constexpr const char* ErrOutOfRange = "Hiba: index hiba!";
	static constexpr const char* ErrInvalidChar = "Hiba: érvénytelen karakter!";
	static constexpr const char* ErrCount = "Hiba: karakterek száma 0!";
	static constexpr const char* ErrUnexpected = "Hiba: nem várt hiba!";

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
			CMyString a("péter");
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
			CMyString a("körte");
			a.setat(4, 'c');
			Assert::AreEqual('c', a.getat(4));
		}
		TEST_METHOD(EmptyTest1)
		{
			CMyString a("körte");
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
			CMyString b("kör");
			a = b;
			Assert::AreEqual((size_t)3, a.size());
		}
	};
}

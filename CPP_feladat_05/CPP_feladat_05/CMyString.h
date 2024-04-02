#pragma once
class CMyString {
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

	static unsigned objcount();					//objektum számlálót adja vissza, CSAK debug
												//módban létezik, ha MYDEBUG definiálva van!	

private: char* m_pchData;						//felhasznált memóriára mutat, ahol string van
	   size_t m_nDataLength;					//hossz, ’ \0’ nélkül, size() 
	   size_t m_nAllocLength;					//ténylegesen lefoglalt memória, capacity() 
	   static unsigned m_iCounter;				//obj.számláló, CSAK debug módban létezik
};
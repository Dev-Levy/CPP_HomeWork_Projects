#pragma once
class CMyString {
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

	static unsigned objcount();					//objektum sz�ml�l�t adja vissza, CSAK debug
												//m�dban l�tezik, ha MYDEBUG defini�lva van!	

private: char* m_pchData;						//felhaszn�lt mem�ri�ra mutat, ahol string van
	   size_t m_nDataLength;					//hossz, � \0� n�lk�l, size() 
	   size_t m_nAllocLength;					//t�nylegesen lefoglalt mem�ria, capacity() 
	   static unsigned m_iCounter;				//obj.sz�ml�l�, CSAK debug m�dban l�tezik
};
#pragma once

template <class T> // T: int, char, double, CMyString
class CMyVector
{
private:
	// elemekre mutat
	T* m_pData;														//def: nullptr !

	// Felhasznált méret, (CMyString m_nDataLength !), T-ben, nem byte-ban!
	unsigned m_nSize;												//def: 0

	// Tömb valós mérete (CMyString m_nAllocLength !), T-ben, nem byte-ban!
	unsigned m_nCapacity;											//def: 0

	// Pl. m_nCapacity = 10, m_nSize = 6.
	// Csak a vector első 6 eleme érhető el, a maradék 4 elem def. értéken van!
	// m_nCapacity >= m_nSize minden esetben !!!!
	// nCapacity - m_nSize (4): nem elérhető elemek def konstruktor-l inicializálódnak osztály esetén,
	// alapadattípusnál lásd később …
	int in;

public:
	CMyVector(void);								// minden def érték!
	CMyVector(unsigned n);							// Tömb mérete -> m_nSize, m_nCapacity megegyezik
	~CMyVector(void);

	T& operator[](unsigned n);						// Index operátor, m_nSize - index ellenőrzése, ErrIndex, ErrEmpty
	CMyVector<T>& operator=(const CMyVector<T>& r);	// Értékadás, m_nCapacity csak akkor változik, ha szükséges. Nem
													// csinál semmit, ha r üres!
	
	void clear();									// Törli az elemeket (üres) -> m_nSize=0, -> def.constr ! m_nCapacity értéke marad
	
	void push_back(const T& value);					// Tömb végéhez fűzi az értéket, m_nSize növekszik, ha lehet, 
													// különben új memóriafoglalás -> mérete: 1,5*m_nCapacity, de
													// min. 4 elem!, Pl.:
													// m_nSize=1, m_nCapacity=1 -> push_back -> m_nSize=2, m_nCapacity=4,
													// m_nSize=5, m_nCapacity=5 -> push_back -> m_nSize=6, m_nCapacity= 7 (5*1,5 -> 7), def. konstuktor hívódik az új elemnél!
	
	
	void list();									// Listázza képernyőre (<< operátorral) az elemeket (m_nSize!), forma: index.:elem
	void sort(bool f);								// Tömböt rendezi csökkenő (false), növekvő(true) sorrendben
													// Beállítja új méretre (m_nSize értéke), ha nagyobb bővíti (ha kell újra foglalja), ha kisebb lecsökkenti az elemszámot (def. érték!).
	void resize(unsigned n);						// m_nCapacity csak akkor változik, ha szükséges, n = 0, üresre állítja (clear!)
	unsigned size(void) const;						// Tömb felhasznált mérete, T-ben, nem byte-ban!
	unsigned capacity(void) const;					// Tömb valós mérete, T-ben, nem byte-ban!
	void shrink_to_fit();							// Elengedi a felesleges kapacitást, új memóriát foglal -> m_nCapacity == m_nSize
};
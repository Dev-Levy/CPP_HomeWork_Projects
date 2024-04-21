
//	Oláh Levente
//
//	  A3C6TV
//
//	 FELADAT: 7
//
//	 VERZIÓ: 2

#pragma once
#include "CPhoneList.h"

class CPhoneIterName
{
public:
	CPhoneIterName(CPhoneList& m);			// elemeket tartalmazó osztály címe 
	~CPhoneIterName();
	Record* begin();						// elsõ elem címe, hiba esetén nullptr, 
	Record* prev();							// elõzõ elem címe, hiba esetén nullptr 
	Record* next();							// következõ elem címe, hiba esetén nullptr 
	Record* end();							// utolsó elem, hiba nullptr

	int size();								// listában levõ elemek száma 
	Record* search(const char* key);		// elsõ egyezõ name, különben nullptr vagy ha üres a tömb,
	Record* operator++();					// következõ elem címe, hiba esetén nullptr
	bool cmp(const Record& r1, const Record& r2);
private:
	CPhoneList* const m_cpList;				// elemeket tároló tömb címe
	int m_iCurrIndex;						// aktuális index a bejárás során … 
	unsigned* indexArray; 					// name szerinti növekvõ rendezéshez szükség rész
	unsigned n;
};

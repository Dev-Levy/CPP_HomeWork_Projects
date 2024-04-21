
//	Ol�h Levente
//
//	  A3C6TV
//
//	 FELADAT: 7
//
//	 VERZI�: 2
#pragma once
#include <ostream>
#define MAXLENGTH 10					// �rt�ke v�ltozhat,ahogy a munka k�v�nja! 
#define MAXNAME 32
#define MAXNUMBER 16
#define OK 0
#define NOK 1


struct Record {
	char name[MAXNAME + 1];
	char number[MAXNUMBER + 1];

	Record() {
		name[0] = '\0';
		number[0] = '\0';
	}
	Record(const char* n, const char* num) {
		strcpy_s(name, MAXNAME + 1, n);
		strcpy_s(number, MAXNUMBER + 1, num);
	}
};
class CPhoneList {
	friend class CPhoneIterName;		// n�vekv� sorrendben, name alapj�n

public:
	CPhoneList();
	int append(const Record& newrec);	// t�mbbe teszi, az els� szabad/�res helyre
										// 0, ha ok, nem 0, ha nincs t�bb hely
	void displayname();					// bej�r�s a name rendezetts�g (n�vekv�) szerint a
										// ++ oper�torral, a ki�r�s << -! 
private:
	Record m_rArray[MAXLENGTH];			// adatok t�rol�sa, fix m�ret�!
	int m_iFirstEmpty;					// k�vetkez� szabad/�res hely az m_rArray-ban}; 
};

std::ostream& operator << (std::ostream& os, Record& r); // ki�r�s
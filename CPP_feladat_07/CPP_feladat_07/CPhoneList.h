
//	Oláh Levente
//
//	  A3C6TV
//
//	 FELADAT: 7
//
//	 VERZIÓ: 2
#pragma once
#include <ostream>
#define MAXLENGTH 10					// értéke változhat,ahogy a munka kívánja! 
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
	friend class CPhoneIterName;		// növekvõ sorrendben, name alapján

public:
	CPhoneList();
	int append(const Record& newrec);	// tömbbe teszi, az elsõ szabad/üres helyre
										// 0, ha ok, nem 0, ha nincs több hely
	void displayname();					// bejárás a name rendezettség (növekvõ) szerint a
										// ++ operátorral, a kiírás << -! 
private:
	Record m_rArray[MAXLENGTH];			// adatok tárolása, fix méretû!
	int m_iFirstEmpty;					// következõ szabad/üres hely az m_rArray-ban}; 
};

std::ostream& operator << (std::ostream& os, Record& r); // kiírás
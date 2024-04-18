#include "CPhoneList.h"

class CPhoneIterName
{
public:
	CPhoneIterName(CPhoneList& m);			// elemeket tartalmaz� oszt�ly c�me 
	~CPhoneIterName();
	Record* begin();						// els� elem c�me, hiba eset�n nullptr, 
	Record* prev();							// el�z� elem c�me, hiba eset�n nullptr 
	Record* next();							// k�vetkez� elem c�me, hiba eset�n nullptr 
	Record* end();							// utols� elem, hiba nullptr

	int size();								// list�ban lev� elemek sz�ma 
	Record* search(const char* key);		// els� egyez� name, k�l�nben nullptr vagy ha �res a t�mb,
	Record* operator++();					// k�vetkez� elem c�me, hiba eset�n nullptr 
private:
	CPhoneList* const m_cpList;				// elemeket t�rol� t�mb c�me
	int m_iCurrIndex;						// aktu�lis index a bej�r�s sor�n � 
	int indexArray[MAXLENGTH]; 				// name szerinti n�vekv� rendez�shez sz�ks�g r�sz 
};


//	Ol�h Levente
//
//	  A3C6TV
//
//	 FELADAT: 9
//
//	 VERZI�: 1

#pragma once
#include "CWageEmployee.h"
class CSalesPerson : public CWageEmployee
{
	public:
		CSalesPerson();
		CSalesPerson(const char* nm);
		void SetCommision(float comm);
		void SetSales(float sales);

		virtual void Input(void);
		virtual float ComputePay() const;
		virtual void Display(void) const;
	private:
		float m_fCommission;	//jutal�k
		float m_fSalesMade;		//eladott darabsz�m
};

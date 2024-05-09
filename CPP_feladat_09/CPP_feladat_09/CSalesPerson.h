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
		void Display(void) const;
	private:
		float m_fCommission;	//jutalék
		float m_fSalesMade;		//eladott darabszám
};

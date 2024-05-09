#pragma once
#include "CWageEmployee.h"
class CSalesPerson : public CWageEmployee
{
	public:
		CSalesPerson();
		CSalesPerson(const char* nm);
		void SetCommision(float comm);
		void SetSales(float sales);
		virtual float ComputePay() const;
	private:
		float m_fCommission;	//jutal�k
		float m_fSalesMade;		//eladott darabsz�m
};

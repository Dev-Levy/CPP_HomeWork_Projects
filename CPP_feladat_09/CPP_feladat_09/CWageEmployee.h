
//	Oláh Levente
//
//	  A3C6TV
//
//	 FELADAT: 9
//
//	 VERZIÓ: 1

#pragma once
#include "CEmployee.h"
class CWageEmployee : public CEmployee
{
	public:
		CWageEmployee();
		CWageEmployee(const char* nm);
		void SetWage(float wg);
		void SetHours(float hrs);

		virtual void Input(void);
		virtual float ComputePay() const;
		virtual void Display(void) const;
	private:
		float m_fWage;		//órabér
		float m_fHours;		//órák száma
};
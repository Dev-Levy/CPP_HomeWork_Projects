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
		void Display(void) const;
	private:
		float m_fWage;		//órabér
		float m_fHours;		//órák száma
};
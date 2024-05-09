#pragma once
#include "CEmployee.h"
class CWageEmployee : public CEmployee
{
	public:
		CWageEmployee();
		CWageEmployee(const char* nm);
		void SetWage(float wg);
		void SetHours(float hrs);
		virtual float ComputePay() const;
	private:
		float m_fWage;		//�rab�r
		float m_fHours;		//�r�k sz�ma
};
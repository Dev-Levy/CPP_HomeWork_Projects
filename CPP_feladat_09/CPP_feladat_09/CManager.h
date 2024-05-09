#pragma once
#include "CEmployee.h"
class CManager : public CEmployee
{
	public:
		CManager();
		CManager(const char* nm);
		void SetSalary(float salary);

		virtual void Input(void);
		virtual float ComputePay() const;
		void Display(void) const;
	private:
		float m_fWeeklySalary;	//heti bér
};
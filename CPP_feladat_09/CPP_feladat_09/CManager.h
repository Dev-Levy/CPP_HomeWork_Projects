
//	Ol�h Levente
//
//	  A3C6TV
//
//	 FELADAT: 9
//
//	 VERZI�: 1

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
		virtual void Display(void) const;
	private:
		float m_fWeeklySalary;	//heti b�r
};
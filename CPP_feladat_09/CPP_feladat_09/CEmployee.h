
//	Oláh Levente
//
//	  A3C6TV
//
//	 FELADAT: 9
//
//	 VERZIÓ: 1

#pragma once
class CEmployee
{
	public:
		CEmployee();
		CEmployee(const char* nm);
		const char* GetName() const;
		void SetName(const char* nm);

		virtual void Input(void);
		virtual float ComputePay() const;
		virtual void Display(void) const;
	private:
		char m_szName[30];	//név
};
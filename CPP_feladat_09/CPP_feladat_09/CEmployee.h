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
		void Display(void) const;
	private:
		char m_szName[30];	//név
};
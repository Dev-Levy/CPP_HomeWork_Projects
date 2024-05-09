#pragma once
class CEmployee
{
	public:
		CEmployee();
		CEmployee(const char* nm);
		const char* GetName() const;
		void SetName(const char* nm);
		virtual float ComputePay() const;
	private:
		char m_szName[30];	//név
};
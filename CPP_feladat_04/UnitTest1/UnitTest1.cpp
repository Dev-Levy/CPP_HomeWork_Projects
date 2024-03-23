#include "pch.h"
#include "CppUnitTest.h"
//#include "CMyDate.h"
//#include "CMyDateException.h"
#include <iostream>
#include "../CPP_feladat_04/CMyDate.h"
#include "../CPP_feladat_04/CMyDateException.h"

//	Oláh Levente
//
//	  A3C6TV
//
//	 FELADAT: 4
//
//	 VERZIÓ: 1

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	void inputtest(const char* input, CMyDate& d, bool get)
	{
		std::istringstream sin{ input };
		auto cin_rdbuf = std::cin.rdbuf(sin.rdbuf());
		try
		{
			if (get)
			{
				d.Get();
			}
			else
			{

			}
		}
		catch (CMyDateException& e)
		{
			std::cin.rdbuf(cin_rdbuf);
			throw e;
		}
		catch (...)
		{
			std::cin.rdbuf(cin_rdbuf);
			throw CMyDateException(CMyDateException::ErrUnexpected);
		}
		std::cin.rdbuf(cin_rdbuf);
	}


	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(ErrMinYearTest)
		{
			try
			{
				CMyDate asd(1000, 1, 23);
			}
			catch (CMyDateException& e)
			{
				ARE_EQUAL(CMyDateException::ErrMinYear, e.what());
			}
		}
		TEST_METHOD(ErrMinDayTest)
		{
			try
			{
				auto asd = CMyDate(2000, 1, 0);
			}
			catch (CMyDateException& e)
			{
				ARE_EQUAL(CMyDateException::ErrMinDay, e.what());
			}
		}
		TEST_METHOD(ErrMaxDayTest)
		{
			try
			{
				auto asd = CMyDate(2000, 1, 100);
			}
			catch (CMyDateException& e)
			{
				ARE_EQUAL(CMyDateException::ErrMaxDay, e.what());
			}
		}
		TEST_METHOD(ErrMinMonthTest)
		{
			try
			{
				auto asd = CMyDate(2000, 0, 10);
			}
			catch (CMyDateException& e)
			{
				ARE_EQUAL(CMyDateException::ErrMinMonth, e.what());
			}
		}
		TEST_METHOD(ErrMaxMonthTest)
		{
			try
			{
				auto asd = CMyDate(2000, 13, 10);
			}
			catch (CMyDateException& e)
			{
				ARE_EQUAL(CMyDateException::ErrMaxMonth, e.what());
			}
		}
		TEST_METHOD(LeapYearTest)
		{
			try
			{
				auto asd = CMyDate(2000, 2, 29);
			}
			catch (CMyDateException& e)
			{
				ARE_NOTEQUAL(CMyDateException::ErrMaxDay, e.what());
			}
		}
		TEST_METHOD(LeapYearTest2)
		{
			try
			{
				auto asd = CMyDate(2001, 2, 29);
			}
			catch (CMyDateException& e)
			{
				ARE_EQUAL(CMyDateException::ErrMaxDay, e.what());
			}
		}
		TEST_METHOD(LeapYearTest3)
		{
			try
			{
				auto asd = CMyDate(2000, 2, 30);
			}
			catch (CMyDateException& e)
			{
				ARE_EQUAL(CMyDateException::ErrMaxDay, e.what());
			}
		}
		TEST_METHOD(DisplayTest)
		{
			std::stringstream buffer;
			std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

			auto asd = CMyDate(2000, 1, 10);
			asd.Display();

			std::string str = buffer.str();

			ARE_EQUALSTR("2000 januar 10.", str.c_str());
		}
		TEST_METHOD(DayOfTheYearTest)
		{
			auto asd = CMyDate(2000, 1, 10);
			ARE_EQUAL(10, asd.DayOfTheYear());
		}
		TEST_METHOD(DayOfTheYearTest2)
		{
			auto asd = CMyDate(2001, 12, 31);
			ARE_EQUAL(365, asd.DayOfTheYear());
		}
		TEST_METHOD(DayOfTheYearTest3)
		{
			auto asd = CMyDate(2000, 12, 31);
			ARE_EQUAL(366, asd.DayOfTheYear());
		}
		TEST_METHOD(asdasdasd)
		{
			CMyDate d;
			const char* input = "2000\n1\n8\n";
			inputtest(input, d, true);
			int y = d.GetYear();
			ARE_EQUAL(2000, y);
		}
	};
}

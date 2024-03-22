#include "pch.h"
#include "CppUnitTest.h"
#include "../CPP_feladat_04/CMyDate.h"
#include "../CPP_feladat_04/CMyDateException.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(ErrMinYearTest)
		{
			try
			{
				CMyDate asd(1000, 1, 23);
			}
			catch (const std::exception& e)
			{
				Assert::AreEqual(CMyDateException::ErrMinYear, e.what());
			}
		}
		TEST_METHOD(ErrMinDayTest)
		{
			try
			{
				auto asd = CMyDate(2000, 1, 0);
			}
			catch (const std::exception& e)
			{
				Assert::AreEqual(CMyDateException::ErrMinDay, e.what());
			}
		}
		TEST_METHOD(ErrMaxDayTest)
		{
			try
			{
				auto asd = CMyDate(2000, 1, 100);
			}
			catch (const std::exception& e)
			{
				Assert::AreEqual(CMyDateException::ErrMaxDay, e.what());
			}
		}
		TEST_METHOD(ErrMinMonthTest)
		{
			try
			{
				auto asd = CMyDate(2000, 0, 10);
			}
			catch (const std::exception& e)
			{
				Assert::AreEqual(CMyDateException::ErrMinMonth, e.what());
			}
		}
		TEST_METHOD(ErrMaxMonthTest)
		{
			try
			{
				auto asd = CMyDate(2000, 13, 10);
			}
			catch (const std::exception& e)
			{
				Assert::AreEqual(CMyDateException::ErrMaxMonth, e.what());
			}
		}
		TEST_METHOD(ErrUnexpectedTest)
		{
			try
			{

			}
			catch (const std::exception& e)
			{
				Assert::AreEqual(CMyDateException::ErrMaxMonth, e.what());
			}
		}
	};
}

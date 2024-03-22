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

		TEST_METHOD(TestMethod1)
		{
			try
			{
				auto asd = CMyDate(1000, 1, 23);
			}
			catch (const std::exception& e)
			{
				Assert::AreEqual(CMyDateException::ErrMinYear, e.what());
			}


		}
	};
}

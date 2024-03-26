#include "pch.h"
#include "CppUnitTest.h"
#include "../CPP_feladat_05/CMyString.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			CMyString str1;
			CMyString str2("Hello");
			str1 = str2;
			Assert::AreEqual(str1, str2);
		}
	};
}

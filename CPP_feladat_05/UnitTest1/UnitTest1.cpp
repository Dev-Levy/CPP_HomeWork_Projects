#include "pch.h"
#include "CppUnitTest.h"
#include "../CPP_feladat_05/CMyString.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(CtorTest1)
		{
			CMyString a;
			Assert::AreEqual((size_t)0, a.size());
		}
		TEST_METHOD(CtorTest2)
		{
			CMyString b("alma");
			Assert::AreEqual((size_t)4, b.size());
		}
		TEST_METHOD(CtorTest3)
		{
			CMyString c('s', 2);
			Assert::AreEqual((size_t)2, c.size());
		}
	};
}

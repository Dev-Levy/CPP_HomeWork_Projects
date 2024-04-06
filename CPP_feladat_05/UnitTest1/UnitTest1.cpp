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
			CMyString a("alma");
			Assert::AreEqual((size_t)4, a.size());
		}
		TEST_METHOD(CtorTest3)
		{
			CMyString a('s', 2);
			Assert::AreEqual((size_t)2, a.size());
		}
		TEST_METHOD(CtorTest4)
		{
			CMyString a("alma");
			CMyString b(a);
			Assert::AreEqual((size_t)4, b.size());
		}
		TEST_METHOD(CtorTest5)
		{
			CMyString a;
			CMyString b(a);
			Assert::AreEqual((size_t)0, b.size());
		}
		TEST_METHOD(GetatTest1)
		{
			CMyString a("alma");
			Assert::AreEqual('a', a.getat(0));
		}
		TEST_METHOD(GetatTest2)
		{
			CMyString a("péter");
			Assert::AreEqual('r', a.getat(4));
		}
		TEST_METHOD(SetatTest1)
		{
			CMyString a("alma");
			a.setat(0, 'b');
			Assert::AreEqual('b', a.getat(0));
		}
		TEST_METHOD(SetatTest2)
		{
			CMyString a("körte");
			a.setat(4, 'c');
			Assert::AreEqual('c', a.getat(4));
		}
		TEST_METHOD(EmptyTest1)
		{
			CMyString a("körte");
			Assert::AreEqual(false, a.empty());
		}
		TEST_METHOD(EmptyTest2)
		{
			CMyString a;
			Assert::AreEqual(true, a.empty());
		}
		TEST_METHOD(EmptyTest3)
		{
			CMyString a("");
			Assert::AreEqual(true, a.empty());
		}
		TEST_METHOD(OperatorTest1)
		{
			CMyString a("alma");
			CMyString b("kör");
			a = b;
			Assert::AreEqual((size_t)3, a.size());
		}

	};
}

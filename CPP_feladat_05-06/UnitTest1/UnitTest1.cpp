#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include "../CPP_feladat_05/CMyString.h"
#include "../CPP_feladat_05/CMyStringException.h"
#define ARE_NOTEQUALPTR(expVal, actVal) Assert::AreNotEqual((char *)expVal, (char *)actVal, L"-", LINE_INFO())


//	Oláh Levente
//
//	  A3C6TV
//
//	 FELADAT: 5-6.
//
//	 VERZIÓ: 6

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
		TEST_METHOD(CapacityTest1)
		{
			CMyString a("alma");
			Assert::AreEqual((size_t)5, a.capacity());
		}
		TEST_METHOD(CapacityTest2)
		{
			CMyString a('o', 99);
			Assert::AreEqual((size_t)100, a.capacity());
		}
		TEST_METHOD(ClearTest1)
		{
			CMyString a("alma");
			a.clear();
			Assert::AreEqual((size_t)0, a.size());
			Assert::AreEqual((size_t)5, a.capacity());
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
			//Assert::AreEqual(true, a.empty());
			Assert::AreEqual((size_t)0, a.size());
		}
		TEST_METHOD(EmptyTest3)
		{
			CMyString a("");
			Assert::AreEqual(true, a.empty());
		}
		TEST_METHOD(DisplayTest)
		{
			std::stringstream buffer;
			std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

			auto asd = CMyString("asdasd");
			asd.display();

			std::string str = buffer.str();

			Assert::AreEqual("asdasd", str.c_str());

			std::cout.rdbuf(old);
		}
		TEST_METHOD(ShrinkTest1)
		{
			CMyString a("alma");
			a.clear();
			a.shrink_to_fit();
			Assert::AreEqual((size_t)0, a.size());
			Assert::AreEqual((size_t)1, a.capacity());
		}
		TEST_METHOD(ShrinkTest2)
		{
			CMyString a("OláhLevente");
			a.clear();
			a.append("Levente");
			a.shrink_to_fit();
			Assert::AreEqual((size_t)7, a.size());
			Assert::AreEqual((size_t)8, a.capacity());
		}
		TEST_METHOD(ReverseTest1)
		{
			CMyString a("asd");

			Assert::AreEqual('a', a.getat(0));
			Assert::AreEqual('s', a.getat(1));
			Assert::AreEqual('d', a.getat(2));

			a.reverse();

			Assert::AreEqual('d', a.getat(0));
			Assert::AreEqual('s', a.getat(1));
			Assert::AreEqual('a', a.getat(2));
		}
		TEST_METHOD(ReverseTest2)
		{
			CMyString a("alma");
			a.clear();
			a.append("korte");

			Assert::AreEqual('k', a.getat(0));
			Assert::AreEqual('o', a.getat(1));
			Assert::AreEqual('r', a.getat(2));
			Assert::AreEqual('t', a.getat(3));
			Assert::AreEqual('e', a.getat(4));

			a.reverse();

			Assert::AreEqual('e', a.getat(0));
			Assert::AreEqual('t', a.getat(1));
			Assert::AreEqual('r', a.getat(2));
			Assert::AreEqual('o', a.getat(3));
			Assert::AreEqual('k', a.getat(4));
		}
		TEST_METHOD(AppendTest1)
		{
			CMyString a("a");
			a.append("b");

			Assert::AreEqual('a', a.getat(0));
			Assert::AreEqual('b', a.getat(1));
		}
		TEST_METHOD(AppendCountTest1)
		{
			CMyString a("a");
			a.append("b", 0, 1);

			Assert::AreEqual('a', a.getat(0));
			Assert::AreEqual('b', a.getat(1));
		}
		TEST_METHOD(AppendCountTest2)
		{
			try
			{
				CMyString a("al");
				a.append("gorilla", 0, 2);

				Assert::AreEqual('a', a.getat(0));
				Assert::AreEqual('l', a.getat(1));
				Assert::AreEqual('g', a.getat(2));
				Assert::AreEqual('o', a.getat(3));
			}
			catch (CMyStringException& e)
			{
				Assert::AreEqual(CMyStringException::ErrOutOfRange, e.what());
			}
		}
		TEST_METHOD(AppendCountTest3)
		{
			try
			{
				CMyString a("al");
				a.append("gorilla", 0, 0);

				Assert::AreEqual('a', a.getat(0));
				Assert::AreEqual('l', a.getat(1));
				Assert::AreEqual('g', a.getat(2));
				Assert::AreEqual('o', a.getat(3));
				a.getat(4);
			}
			catch (CMyStringException& e)
			{
				Assert::AreEqual(CMyStringException::ErrCount, e.what());
			}
		}
		TEST_METHOD(AppendOffsetTest1)
		{
			try
			{
				CMyString a("al");
				a.append("illa", 2, 1);

				Assert::AreEqual('a', a.getat(0));
				Assert::AreEqual('l', a.getat(1));
				Assert::AreEqual('l', a.getat(2));
				a.getat(3);
			}
			catch (CMyStringException& e)
			{
				Assert::AreEqual(CMyStringException::ErrOutOfRange, e.what());
			}
		}
		TEST_METHOD(AppendOffsetTest2)
		{
			try
			{
				CMyString a("al");
				a.append("gorilla", 2, 3);

				Assert::AreEqual('a', a.getat(0));
				Assert::AreEqual('l', a.getat(1));
				Assert::AreEqual('r', a.getat(2));
				Assert::AreEqual('i', a.getat(3));
				Assert::AreEqual('l', a.getat(4));
				Assert::AreEqual('l', a.getat(5));
				a.getat(6);
			}
			catch (CMyStringException& e)
			{
				Assert::AreEqual(CMyStringException::ErrOutOfRange, e.what());
			}

		};
		TEST_METHOD(OperatorTest1)
		{
			CMyString a("alma");
			CMyString b("korte");
			a = b;

			Assert::AreEqual('k', a.getat(0));
			Assert::AreEqual('o', a.getat(1));
			Assert::AreEqual('r', a.getat(2));
			Assert::AreEqual('t', a.getat(3));
			Assert::AreEqual('e', a.getat(4));
		}
		TEST_METHOD(OperatorTest2)
		{
			try
			{
				CMyString a("alma");
				CMyString b;
				a = b;

				Assert::AreEqual((size_t)0, a.size());
				a.getat(1);
			}
			catch (CMyStringException& e)
			{
				Assert::AreEqual(CMyStringException::ErrOutOfRange, e.what());
			}
		}
		TEST_METHOD(OperatorTest3)
		{
			CMyString a("alma");
			a = a;

			Assert::AreEqual('a', a.getat(0));
			Assert::AreEqual('l', a.getat(1));
			Assert::AreEqual('m', a.getat(2));
			Assert::AreEqual('a', a.getat(3));
		}
		TEST_METHOD(OperatorTest4)
		{
			CMyString a("alma");
			CMyString b("korte");
			CMyString c("narants");
			a = b = c;

			Assert::AreEqual('n', a.getat(0));
			Assert::AreEqual('a', a.getat(1));
			Assert::AreEqual('r', a.getat(2));
			Assert::AreEqual('a', a.getat(3));
			Assert::AreEqual('n', a.getat(4));
			Assert::AreEqual('t', a.getat(5));
			Assert::AreEqual('s', a.getat(6));
		}
		TEST_METHOD(OperatorTest5)
		{
			CMyString a("alma");
			CMyString b("korte");
			CMyString c("narants");
			a = b = c = a;

			Assert::AreEqual('a', a.getat(0));
			Assert::AreEqual('l', a.getat(1));
			Assert::AreEqual('m', a.getat(2));
			Assert::AreEqual('a', a.getat(3));
		}
		TEST_METHOD(ObjCountTest1)
		{
			CMyString::clearobjcount();
			CMyString a("alma");
			CMyString b("korte");
			CMyString c("narants");

			Assert::AreEqual((unsigned)3, CMyString::objcount());
		}
		TEST_METHOD(ObjCountTest2)
		{
			Assert::AreEqual((unsigned)0, CMyString::objcount());
		}

		TEST_METHOD(bad_allocTest)
		{
			try
			{
				CMyString a('a', UINT64_MAX - 1);
			}
			catch (CMyStringException& e)
			{
				Assert::AreEqual(CMyStringException::ErrUnexpected, e.what());
			}
		}
		TEST_METHOD(AppendPlusTest)
		{
			CMyString a;
			const char* b = a.c_str();
			a.append(nullptr);
			Assert::IsTrue(nullptr != a.c_str());
		}

		TEST_METHOD(TestSubstring)
		{
			CMyString str("Hello, world!");

			CMyString sub = str.substring(0, 5);
			Assert::AreEqual("Hello", sub.c_str());
						
			sub = str.substring(7, 1000000);
			Assert::AreEqual("world!", sub.c_str());

			try {
				sub = str.substring(20, 5);
			}
			catch (const CMyStringException& e) {
				Assert::AreEqual(CMyStringException::ErrOutOfRange, e.what());
			}
		}

		TEST_METHOD(TestSwap)
		{
			CMyString str1("Hello");
			CMyString str2("world!");

			str1.swap(str2);

			Assert::AreEqual("world!", str1.c_str());
			Assert::AreEqual("Hello", str2.c_str());
		}

		TEST_METHOD(ConstructorTest)
		{
			CMyString str("Hello");
			Assert::AreEqual("Hello", str.c_str());
		}

		TEST_METHOD(AssignmentOperatorTest)
		{
			CMyString str1("Hello");
			CMyString str2;
			str2 = str1;
			Assert::AreEqual("Hello", str2.c_str());
		}

		TEST_METHOD(EqualityOperatorTest)
		{
			CMyString str1("Hello");
			CMyString str2("Hello");
			Assert::IsTrue(str1 == str2);
		}

		TEST_METHOD(PlusOperatorTest)
		{
			CMyString str1("Hello");
			CMyString str2(" World");
			CMyString str3 = str1 + str2;
			Assert::AreEqual("Hello World", str3.c_str());
		}

		TEST_METHOD(PlusEqualOperatorTest)
		{
			CMyString str1("Hello");
			str1 += " World";
			Assert::AreEqual("Hello World", str1.c_str());
		}

		TEST_METHOD(IndexOperatorTest)
		{
			CMyString str("Hello");
			Assert::AreEqual('H', str[0]);
		}

		TEST_METHOD(SubstringTest2)
		{
			CMyString s1, s2("alma");
			s1 = s2.substring(0);
			Assert::AreEqual("alma", s1.c_str());

			s1 = s2.substring(4);
			Assert::AreEqual('\0', *s1.c_str());
		}

		TEST_METHOD(EqualityOperatorTest2)
		{
			CMyString s1("ananasz");
			CMyString s2("ananasz");
			CMyString s3("dio");
			CMyString s4;
			CMyString s5("eperdio");
			Assert::IsTrue(s1 == s2);
			Assert::IsTrue(!(s2 == s3));
			Assert::IsTrue(!(s3 == s4));
			Assert::IsTrue(!(s3 == s5));
			Assert::IsTrue(!(s4 == s5));
		}

		TEST_METHOD(MoveTest)
		{
			CMyString::clearobjcount();
			try
			{
				CMyString t("datolya");
				CMyString s = std::move(t);

				Assert::ARE_NOTEQUALPTR(nullptr, t.c_str());
				Assert::AreEqual("datolya", s.c_str());
				Assert::AreEqual('\0', *t.c_str());

				Assert::AreEqual((size_t)0, t.size());
				Assert::AreEqual((size_t)1, t.capacity());
				Assert::AreEqual((size_t)7, s.size());
				Assert::AreEqual((size_t)8, s.capacity());
			}
			catch (const std::exception&) {}

			unsigned objcount = CMyString::objcount();
			Assert::AreEqual(0u, objcount);
		}

		TEST_METHOD(AddOperatorTest2)
		{
			CMyString s1("alma");
			CMyString s2;
			s1 += s2;
			Assert::AreEqual("alma", s1.c_str());
		}

		TEST_METHOD(AddOperatorTest3)
		{
			CMyString::clearobjcount();
			try
			{
				CMyString s1("ananász");
				CMyString s2("alma");
				CMyString s3("eper");
				s1 = s2 + s3;
				Assert::AreEqual("almaeper", s1.c_str());
				Assert::AreEqual(3u, CMyString::objcount());
				CMyString s4 = std::move(s1);
			}
			catch (const std::exception&) {}
			
			Assert::AreEqual(0u, CMyString::objcount());
		}
	};
}
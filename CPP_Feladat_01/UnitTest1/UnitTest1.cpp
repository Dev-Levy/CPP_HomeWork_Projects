#include "pch.h"
#include "CppUnitTest.h"
#include "feladat1.h"

#define EPSILON 0.0001
#define FLOAT_EQ(x,v) (((v - EPSILON) < x) && (x <( v + EPSILON)))

#define ARE_EQUAL(expVal, actVal) Assert::AreEqual(expVal, actVal, L"-", LINE_INFO())

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		//Oláh Levente - A3C6TV - feladat1 - V1
		TEST_METHOD(Test_01)
		{
			ARE_EQUAL(-1234.5678, feladat1(" \n\t-1234.5678"));
		}
		TEST_METHOD(Test_02)
		{
			ARE_EQUAL(0.0, feladat1("\n\t-\t234.5678"));
		}
		TEST_METHOD(Test_03)
		{
			ARE_EQUAL(0.0, feladat1("\n\t - 1234.5678"));
		}
		TEST_METHOD(Test_04)
		{
			ARE_EQUAL(1234.56, feladat1("1234.56\n78"));
		}
		TEST_METHOD(Test_05)
		{
			ARE_EQUAL(0.0, feladat1(" \n\t"));
		}
		TEST_METHOD(Test_06)
		{
			ARE_EQUAL(12.0, feladat1("\n\t12+34.5678"));
		}
		TEST_METHOD(Test_07)
		{
			ARE_EQUAL(1234.5678, feladat1("1234.5678"));
		}
		TEST_METHOD(Test_08)
		{
			ARE_EQUAL(1234.0, feladat1("+1234"));
		}
		TEST_METHOD(Test_09)
		{
			ARE_EQUAL(0.0, feladat1(" + 1234."));
		}
		TEST_METHOD(Test_10)
		{
			ARE_EQUAL(0.0, feladat1(" + - 1234.5678"));
		}
		TEST_METHOD(Test_11)
		{
			ARE_EQUAL(0.0, feladat1("++1234.5678"));
		}
		TEST_METHOD(Test_12)
		{
			Assert::IsTrue(FLOAT_EQ(0.5678, feladat1(".5678")));
		}
		TEST_METHOD(Test_13)
		{
			ARE_EQUAL(1234.5, feladat1(" 1234.5.678"));
		}
		TEST_METHOD(Test_14)
		{
			Assert::IsTrue(FLOAT_EQ(0.1234, feladat1(".1234.5678")));
		}
		TEST_METHOD(Test_15)
		{
			ARE_EQUAL(1234.0, feladat1(" 1234..5678"));
		}
		TEST_METHOD(Test_16)
		{
			ARE_EQUAL(1234.56, feladat1(" 1234.56+78"));
		}
		TEST_METHOD(Test_17)
		{
			ARE_EQUAL(16.0, feladat1(" \n\r\r\t\f0x10"));
		}
		TEST_METHOD(Test_18)
		{
			ARE_EQUAL(11259375.0, feladat1("0xabcdef"));
		}
		TEST_METHOD(Test_19)
		{
			ARE_EQUAL(255.0, feladat1("0xFF"));
		}
		TEST_METHOD(Test_20)
		{
			ARE_EQUAL(0.0, feladat1("0x"));
		}
	};
}

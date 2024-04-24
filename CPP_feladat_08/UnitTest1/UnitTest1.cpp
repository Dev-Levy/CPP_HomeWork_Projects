#include "pch.h"
#include "CppUnitTest.h"
#include "../CPP_feladat_08/CMyVector.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestDefaultConstructor)
		{
			CMyVector<int> vec;
			Assert::AreEqual(0u, vec.size());
			Assert::AreEqual(0u, vec.capacity());
		}

		TEST_METHOD(TestSizeConstructor)
		{
			CMyVector<int> vec(5);
			Assert::AreEqual(5u, vec.size());
			Assert::AreEqual(5u, vec.capacity());
		}

		TEST_METHOD(TestPushBack)
		{
			CMyVector<int> vec;
			vec.push_back(1);
			Assert::AreEqual(1u, vec.size());
			Assert::AreEqual(1, vec[0]);
		}

		TEST_METHOD(TestOperator)
		{
			CMyVector<int> vec(1);
			vec[0] = 2;
			Assert::AreEqual(2, vec[0]);
		}

		TEST_METHOD(TestClear)
		{
			CMyVector<int> vec(5);
			vec.clear();
			Assert::AreEqual(0u, vec.size());
		}

		TEST_METHOD(TestSize)
		{
			CMyVector<int> vec(5);
			Assert::AreEqual(5u, vec.size());
		}

		TEST_METHOD(TestCapacity)
		{
			CMyVector<int> vec(5);
			Assert::AreEqual(5u, vec.capacity());
		}

		TEST_METHOD(TestShrinkToFit)
		{
			CMyVector<int> vec(5);
			vec.push_back(1);
			vec.shrink_to_fit();
			Assert::AreEqual(1u, vec.capacity());
		}
	};
}

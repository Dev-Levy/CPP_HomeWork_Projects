
//	Oláh Levente
//
//	  A3C6TV
//
//	 FELADAT: 8
//
//	 VERZIÓ: 1

#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include "../CPP_feladat_08/CMyVector.h"
#include "../CPP_feladat_08/CMyVectorException.h"
#include "../CPP_feladat_08/CMyString.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	extern template CMyVector <int>;
	extern template CMyVector <CMyString>;
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestSize)
		{
			CMyVector<int> vec(5);
			Assert::AreEqual(5u, vec.size());

			CMyVector<int> vec2(0);
			Assert::AreEqual(0u, vec2.size());

			CMyVector<CMyString> strvec(5);
			Assert::AreEqual(5u, strvec.size());

			CMyVector<CMyString> strvec2;
			Assert::AreEqual(0u, strvec2.size());
		}

		TEST_METHOD(TestCapacity)
		{
			CMyVector<int> vec(5);
			Assert::AreEqual(5u, vec.capacity());

			CMyVector<int> vec2(0);
			Assert::AreEqual(0u, vec2.capacity());

			CMyVector<CMyString> strvec(5);
			Assert::AreEqual(5u, strvec.capacity());

			CMyVector<CMyString> strvec2;
			Assert::AreEqual(0u, strvec2.capacity());
		}

		TEST_METHOD(TestDefaultConstructor)
		{
			CMyVector<int> vec;
			Assert::AreEqual(0u, vec.size());
			Assert::AreEqual(0u, vec.capacity());

			CMyVector<CMyString> strvec;
			Assert::AreEqual(0u, strvec.size());
			Assert::AreEqual(0u, strvec.capacity());
		}

		TEST_METHOD(TestSizeConstructor)
		{
			CMyVector<int> vec(5);
			Assert::AreEqual(5u, vec.size());
			Assert::AreEqual(5u, vec.capacity());

			CMyVector<CMyString> strvec(5);
			Assert::AreEqual(5u, strvec.size());
			Assert::AreEqual(5u, strvec.capacity());
		}

		TEST_METHOD(TestIndexOperator)
		{
			CMyVector<int> vec(5);
			vec[0] = 2;
			vec[1] = 3;
			vec[2] = 4;
			vec[3] = 5;
			vec[4] = 6;
			Assert::AreEqual(2, vec[0]);
			Assert::AreEqual(3, vec[1]);
			Assert::AreEqual(4, vec[2]);
			Assert::AreEqual(5, vec[3]);
			Assert::AreEqual(6, vec[4]);

			CMyVector<CMyString> strvec(5);
			strvec.push_back(CMyString("asd"));
			strvec.push_back(CMyString("qwe"));
			strvec.push_back(CMyString("zxc"));
			strvec.push_back(CMyString("rty"));
			strvec.push_back(CMyString("fgh"));

			Assert::AreEqual(CMyString("asd"), strvec[0]);
			Assert::AreEqual(CMyString("qwe"), strvec[1]);
			Assert::AreEqual(CMyString("zxc"), strvec[2]);
			Assert::AreEqual(CMyString("rty"), strvec[3]);
			Assert::AreEqual(CMyString("fgh"), strvec[4]);
		}

		TEST_METHOD(TestIndexOperatorErr1)
		{
			try
			{
				CMyVector<int> vec(2);
				vec[0] = 2;
				vec[1] = 3;
				vec[2] = 4;
			}
			catch (CMyVectorException& e)
			{
				Assert::AreEqual(CMyVectorException::ErrIndex, e.what());
			}

			try
			{
				CMyVector<CMyString> strvec(2);
				strvec[0] = CMyString("asd");
				strvec[1] = CMyString("qwe");
				strvec[2] = CMyString("zxc");
			}
			catch (CMyVectorException& e)
			{
				Assert::AreEqual(CMyVectorException::ErrIndex, e.what());
			}
		}

		TEST_METHOD(TestIndexOperatorErr2)
		{
			try
			{
				CMyVector<int> vec;
				vec[0] = 2;
			}
			catch (CMyVectorException& e)
			{
				Assert::AreEqual(CMyVectorException::ErrEmpty, e.what());
			}
			try
			{
				CMyVector<CMyString> strvec;
				strvec[0] = CMyString("asd");
			}
			catch (CMyVectorException& e)
			{
				Assert::AreEqual(CMyVectorException::ErrEmpty, e.what());
			}
		}

		TEST_METHOD(TestValueOperator1)
		{
			CMyVector<int> vec(5);
			vec[0] = 2;
			vec[1] = 3;
			vec[2] = 4;
			vec[3] = 5;
			vec[4] = 6;
			CMyVector<int> vec2(5);
			vec2 = vec;

			Assert::AreEqual(2, vec2[0]);
			Assert::AreEqual(3, vec2[1]);
			Assert::AreEqual(4, vec2[2]);
			Assert::AreEqual(5, vec2[3]);
			Assert::AreEqual(6, vec2[4]);


			//string
			CMyVector<CMyString> strvec(5);
			strvec.push_back(CMyString("asd"));
			strvec.push_back(CMyString("qwe"));
			strvec.push_back(CMyString("zxc"));
			strvec.push_back(CMyString("rty"));
			strvec.push_back(CMyString("fgh"));

			CMyVector<CMyString> strvec2(5);
			strvec2 = strvec;

			Assert::AreEqual(CMyString("asd"), strvec2[0]);
			Assert::AreEqual(CMyString("qwe"), strvec2[1]);
			Assert::AreEqual(CMyString("zxc"), strvec2[2]);
			Assert::AreEqual(CMyString("rty"), strvec2[3]);
			Assert::AreEqual(CMyString("fgh"), strvec2[4]);
		}
		TEST_METHOD(TestValueOperator2)
		{
			CMyVector<int> vec(5);
			vec[0] = 2;
			vec[1] = 3;
			vec[2] = 4;
			vec[3] = 5;
			vec[4] = 6;
			CMyVector<int> vec2(5);
			vec = vec2;

			Assert::AreEqual(0, vec[0]);
			Assert::AreEqual(0, vec[1]);
			Assert::AreEqual(0, vec[2]);
			Assert::AreEqual(0, vec[3]);
			Assert::AreEqual(0, vec[4]);


			//string
			CMyVector<CMyString> strvec(5);
			strvec.push_back(CMyString("asd"));
			strvec.push_back(CMyString("qwe"));
			strvec.push_back(CMyString("zxc"));
			strvec.push_back(CMyString("rty"));
			strvec.push_back(CMyString("fgh"));

			CMyVector<CMyString> strvec2(5);
			strvec = strvec2;

			Assert::AreEqual(CMyString(""), strvec[0]);
			Assert::AreEqual(CMyString(""), strvec[1]);
			Assert::AreEqual(CMyString(""), strvec[2]);
			Assert::AreEqual(CMyString(""), strvec[3]);
			Assert::AreEqual(CMyString(""), strvec[4]);
		}
		TEST_METHOD(TestValueOperator3)
		{
			CMyVector<int> vec(5);
			vec[0] = 2;
			vec[1] = 3;
			vec[2] = 4;
			vec[3] = 5;
			vec[4] = 6;
			CMyVector<int> vec2(1);
			vec = vec2;

			Assert::AreEqual(0, vec[0]);


			//string
			CMyVector<CMyString> strvec(5);
			strvec.push_back(CMyString("asd"));
			strvec.push_back(CMyString("qwe"));
			strvec.push_back(CMyString("zxc"));
			strvec.push_back(CMyString("rty"));
			strvec.push_back(CMyString("fgh"));

			CMyVector<CMyString> strvec2(1);
			strvec = strvec2;

			Assert::AreEqual(CMyString(""), strvec[0]);
		}
		TEST_METHOD(TestValueOperator4)
		{
			CMyVector<int> vec(5);
			vec[0] = 2;
			vec[1] = 3;
			vec[2] = 4;
			vec[3] = 5;
			vec[4] = 6;
			CMyVector<int> vec2(1);
			vec2 = vec;

			Assert::AreEqual(2, vec2[0]);
			Assert::AreEqual(3, vec2[1]);
			Assert::AreEqual(4, vec2[2]);
			Assert::AreEqual(5, vec2[3]);
			Assert::AreEqual(6, vec2[4]);


			//string
			CMyVector<CMyString> strvec(5);
			strvec.push_back(CMyString("asd"));
			strvec.push_back(CMyString("qwe"));
			strvec.push_back(CMyString("zxc"));
			strvec.push_back(CMyString("rty"));
			strvec.push_back(CMyString("fgh"));

			CMyVector<CMyString> strvec2(1);
			strvec2 = strvec;

			Assert::AreEqual(CMyString("asd"), strvec2[0]);
			Assert::AreEqual(CMyString("qwe"), strvec2[1]);
			Assert::AreEqual(CMyString("zxc"), strvec2[2]);
			Assert::AreEqual(CMyString("rty"), strvec2[3]);
			Assert::AreEqual(CMyString("fgh"), strvec2[4]);
		}
		TEST_METHOD(TestValueOperatorErr)
		{
			CMyVector<int> vec(5);
			vec[0] = 0;
			vec[1] = 1;
			vec[2] = 2;
			vec[3] = 3;
			vec[4] = 4;
			CMyVector<int> vec2;
			vec = vec2;

			Assert::AreEqual(0, vec[0]);
			Assert::AreEqual(1, vec[1]);
			Assert::AreEqual(2, vec[2]);
			Assert::AreEqual(3, vec[3]);
			Assert::AreEqual(4, vec[4]);


			//string
			CMyVector<CMyString> strvec(5);
			strvec.push_back(CMyString("asd"));
			strvec.push_back(CMyString("qwe"));
			strvec.push_back(CMyString("zxc"));
			strvec.push_back(CMyString("rty"));
			strvec.push_back(CMyString("fgh"));

			CMyVector<CMyString> strvec2;
			strvec = strvec2;

			Assert::AreEqual(CMyString("asd"), strvec[0]);
			Assert::AreEqual(CMyString("qwe"), strvec[1]);
			Assert::AreEqual(CMyString("zxc"), strvec[2]);
			Assert::AreEqual(CMyString("rty"), strvec[3]);
			Assert::AreEqual(CMyString("fgh"), strvec[4]);
		}

		TEST_METHOD(TestClear)
		{
			try
			{
				CMyVector<int> vec(5);
				vec[0] = 2;
				vec[1] = 3;
				vec[2] = 4;
				vec[3] = 5;
				vec[4] = 6;
				vec.clear();

				Assert::AreEqual(0u, vec.size());
				Assert::AreEqual(5u, vec.capacity());

				auto asd = vec[0];
			}
			catch (CMyVectorException& e)
			{
				Assert::AreEqual(CMyVectorException::ErrEmpty, e.what());
			}

			try
			{
				CMyVector<CMyString> strvec(5);
				strvec.push_back(CMyString("asd"));
				strvec.push_back(CMyString("qwe"));
				strvec.push_back(CMyString("zxc"));
				strvec.push_back(CMyString("rty"));
				strvec.push_back(CMyString("fgh"));

				strvec.clear();

				Assert::AreEqual(0u, strvec.size());
				Assert::AreEqual(5u, strvec.capacity());

				auto asd = strvec[0];
			}
			catch (CMyVectorException& e)
			{
				Assert::AreEqual(CMyVectorException::ErrEmpty, e.what());
			}
		}
		TEST_METHOD(TestPushBack1)
		{
			CMyVector<int> vec(5);
			vec.push_back(2);
			vec.push_back(3);
			vec.push_back(4);
			vec.push_back(5);
			vec.push_back(6);

			Assert::AreEqual(2, vec[0]);
			Assert::AreEqual(3, vec[1]);
			Assert::AreEqual(4, vec[2]);
			Assert::AreEqual(5, vec[3]);
			Assert::AreEqual(6, vec[4]);

			//string
			CMyVector<CMyString> strvec(5);
			strvec.push_back(CMyString("asd"));
			strvec.push_back(CMyString("qwe"));
			strvec.push_back(CMyString("zxc"));
			strvec.push_back(CMyString("rty"));
			strvec.push_back(CMyString("fgh"));

			Assert::AreEqual(CMyString("asd"), strvec[0]);
			Assert::AreEqual(CMyString("qwe"), strvec[1]);
			Assert::AreEqual(CMyString("zxc"), strvec[2]);
			Assert::AreEqual(CMyString("rty"), strvec[3]);
			Assert::AreEqual(CMyString("fgh"), strvec[4]);
		}
		TEST_METHOD(TestPushBack2)
		{
			CMyVector<int> vec(2);
			vec.push_back(2);
			vec.push_back(3);

			Assert::AreEqual(2, vec[0]);
			Assert::AreEqual(3, vec[1]);

			vec.push_back(4);

			Assert::AreEqual(2, vec[0]);
			Assert::AreEqual(3, vec[1]);
			Assert::AreEqual(4, vec[2]);

			Assert::AreEqual(3u, vec.size());
			Assert::AreEqual(4u, vec.capacity());

			//string
			CMyVector<CMyString> strvec(2);
			strvec.push_back(CMyString("asd"));
			strvec.push_back(CMyString("qwe"));

			Assert::AreEqual(CMyString("asd"), strvec[0]);
			Assert::AreEqual(CMyString("qwe"), strvec[1]);

			strvec.push_back(CMyString("zxc"));

			Assert::AreEqual(CMyString("asd"), strvec[0]);
			Assert::AreEqual(CMyString("qwe"), strvec[1]);
			Assert::AreEqual(CMyString("zxc"), strvec[2]);

			Assert::AreEqual(3u, strvec.size());
			Assert::AreEqual(4u, strvec.capacity());
		}

		TEST_METHOD(TestPushBack3)
		{
			CMyVector<int> vec;
			vec.push_back(2);
			vec.push_back(3);

			Assert::AreEqual(2, vec[0]);
			Assert::AreEqual(3, vec[1]);

			Assert::AreEqual(2u, vec.size());
			Assert::AreEqual(4u, vec.capacity());


			//string
			CMyVector<CMyString> strvec;
			strvec.push_back(CMyString("asd"));
			strvec.push_back(CMyString("qwe"));

			Assert::AreEqual(CMyString("asd"), strvec[0]);
			Assert::AreEqual(CMyString("qwe"), strvec[1]);

			Assert::AreEqual(2u, strvec.size());
			Assert::AreEqual(4u, strvec.capacity());
		}

		TEST_METHOD(TestList1)
		{
			std::stringstream buffer;
			std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

			CMyVector<int> vec(5);
			vec.push_back(2);
			vec.push_back(3);
			vec.push_back(4);
			vec.push_back(5);
			vec.push_back(6);

			vec.list();
			std::string str = buffer.str();

			Assert::AreEqual(std::string("1.: 2\n2.: 3\n3.: 4\n4.: 5\n5.: 6\n"), str);

			std::cout.rdbuf(old);
		}
		TEST_METHOD(TestList2)
		{
			std::stringstream buffer;
			std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

			CMyVector<int> vec(5);
			vec.push_back(2);

			vec.list();
			std::string str = buffer.str();

			Assert::AreEqual(std::string("1.: 2\n2.: 0\n3.: 0\n4.: 0\n5.: 0\n"), str);

			std::cout.rdbuf(old);
		}

		TEST_METHOD(TestStringList1)
		{
			std::stringstream buffer;
			std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

			CMyVector<CMyString> strvec(5);
			strvec.push_back(CMyString("asd"));
			strvec.push_back(CMyString("qwe"));
			strvec.push_back(CMyString("zxc"));
			strvec.push_back(CMyString("rty"));
			strvec.push_back(CMyString("fgh"));

			strvec.list();
			std::string str = buffer.str();

			Assert::AreEqual(std::string("1.: asd\n2.: qwe\n3.: zxc\n4.: rty\n5.: fgh\n"), str);

			std::cout.rdbuf(old);
		}
		TEST_METHOD(TestStringList2)
		{
			std::stringstream buffer;
			std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

			CMyVector<CMyString> strvec(5);
			strvec.push_back(CMyString("asd"));

			strvec.list();
			std::string str = buffer.str();

			Assert::AreEqual(std::string("1.: asd\n2.: \n3.: \n4.: \n5.: \n"), str);

			std::cout.rdbuf(old);
		}

		TEST_METHOD(TestSort1)
		{
			CMyVector<int> vec(5);
			vec.push_back(4);
			vec.push_back(1);
			vec.push_back(2);
			vec.push_back(3);
			vec.push_back(5);

			vec.sort(true);

			Assert::AreEqual(1, vec[0]);
			Assert::AreEqual(2, vec[1]);
			Assert::AreEqual(3, vec[2]);
			Assert::AreEqual(4, vec[3]);
			Assert::AreEqual(5, vec[4]);

			vec.sort(false);

			Assert::AreEqual(5, vec[0]);
			Assert::AreEqual(4, vec[1]);
			Assert::AreEqual(3, vec[2]);
			Assert::AreEqual(2, vec[3]);
			Assert::AreEqual(1, vec[4]);

		}

		TEST_METHOD(TestStringSort1)
		{
			CMyVector<CMyString> strvec(5);
			strvec.push_back(CMyString("asd"));
			strvec.push_back(CMyString("qwe"));
			strvec.push_back(CMyString("zxc"));
			strvec.push_back(CMyString("rty"));
			strvec.push_back(CMyString("fgh"));

			strvec.sort(true);

			Assert::AreEqual(CMyString("asd"), strvec[0]);
			Assert::AreEqual(CMyString("fgh"), strvec[1]);
			Assert::AreEqual(CMyString("qwe"), strvec[2]);
			Assert::AreEqual(CMyString("rty"), strvec[3]);
			Assert::AreEqual(CMyString("zxc"), strvec[4]);

			strvec.sort(false);

			Assert::AreEqual(CMyString("zxc"), strvec[0]);
			Assert::AreEqual(CMyString("rty"), strvec[1]);
			Assert::AreEqual(CMyString("qwe"), strvec[2]);
			Assert::AreEqual(CMyString("fgh"), strvec[3]);
			Assert::AreEqual(CMyString("asd"), strvec[4]);
		}
		TEST_METHOD(TestResize1)
		{
			CMyVector<int> vec(5);
			vec.resize(0);
			Assert::AreEqual(0u, vec.size());
			Assert::AreEqual(5u, vec.capacity());

			//string
			CMyVector<CMyString> strvec(5);
			strvec.resize(0);
			Assert::AreEqual(0u, strvec.size());
			Assert::AreEqual(5u, strvec.capacity());
		}
		TEST_METHOD(TestResize2)
		{
			CMyVector<int> vec(5);
			vec.resize(3);
			Assert::AreEqual(3u, vec.size());
			Assert::AreEqual(5u, vec.capacity());

			//string
			CMyVector<CMyString> strvec(5);
			strvec.resize(3);
			Assert::AreEqual(3u, strvec.size());
			Assert::AreEqual(5u, strvec.capacity());
		}
		TEST_METHOD(TestResize3)
		{
			CMyVector<int> vec(5);
			vec.resize(8);
			Assert::AreEqual(8u, vec.size());
			Assert::AreEqual(8u, vec.capacity());

			//string
			CMyVector<CMyString> strvec(5);
			strvec.resize(8);
			Assert::AreEqual(8u, strvec.size());
			Assert::AreEqual(8u, strvec.capacity());
		}

		TEST_METHOD(TestShrinkToFit)
		{
			CMyVector<int> vec(5);
			vec.resize(3);
			vec.shrink_to_fit();
			Assert::AreEqual(3u, vec.size());
			Assert::AreEqual(3u, vec.capacity());

			//string
			CMyVector<CMyString> strvec(5);
			strvec.resize(3);
			strvec.shrink_to_fit();
			Assert::AreEqual(3u, strvec.size());
			Assert::AreEqual(3u, strvec.capacity());
		}

		TEST_METHOD(TestPush)
		{
			unsigned maxtest = 5;
			CMyVector<int> vec(maxtest);
			for (unsigned i = 0; i < maxtest; i++)
				vec[i] = i + 1;

			vec.push_back(6);

			Assert::AreEqual(maxtest+1, vec.size());
			Assert::AreEqual(7u, vec.capacity());
			Assert::AreEqual(6, vec[maxtest]);
		}
	};
}


//kellett a ToString függvény, hogy a CMyString típusú változókat is ki tudja írni a test framework hiba esetén
namespace Microsoft::VisualStudio::CppUnitTestFramework
{
	template<>
	inline std::wstring ToString<CMyString>(const CMyString& t)
	{
		std::string str(t.c_str());
		return std::wstring(str.begin(), str.end());
	}
}
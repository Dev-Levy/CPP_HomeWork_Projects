#include "pch.h"
#include "CppUnitTest.h"
#include "feladat2.h"


#define ARE_EQUAL(expVal, actVal) Assert::AreEqual(expVal, actVal, L"-", LINE_INFO())
#define WRITE(s) Logger::WriteMessage((const char*)s)

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

//Oláh Levente - A3C6TV - feladat2 - V2

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(NewFifoOK)
		{
			int ret = NewFifo(3);
			ARE_EQUAL(0, ret);
			DeleteFifo();
		}
		TEST_METHOD(NewFifoOKAfterDelete)
		{
			int ret = NewFifo(37);
			ARE_EQUAL(0, ret);
			DeleteFifo();
		}
		TEST_METHOD(NewFifoNOK_negativeMem)
		{
			int ret = NewFifo(-3);
			ARE_EQUAL(-1, ret);
			DeleteFifo();
		}
		TEST_METHOD(NewFifoNOK_maxsizeInt)
		{
			int ret = NewFifo(UINT_MAX);
			ARE_EQUAL(-1, ret);
			DeleteFifo();
		}
		TEST_METHOD(NewFifoNOK_twoFifoExisting)
		{
			NewFifo(2);
			int ret = NewFifo(10);
			ARE_EQUAL(-1, ret);
			DeleteFifo();
		}


		TEST_METHOD(DeleteFifoTestOK)
		{
			NewFifo(1);
			int ret = DeleteFifo();
			ARE_EQUAL(0, ret);
		}
		TEST_METHOD(DeleteFifoTestNOK)
		{
			int ret = DeleteFifo();
			ARE_EQUAL(-1, ret);
		}



		TEST_METHOD(PushTestOK)
		{
			NewFifo(1);
			int asd = Push('s');
			ARE_EQUAL(0, asd);
			DeleteFifo();
		}
		TEST_METHOD(PushTestNOK)
		{
			NewFifo(1);
			Push('s');
			int asd = Push('s');
			ARE_EQUAL(-1, asd);
			DeleteFifo();
		}
		TEST_METHOD(PushTestNOK2)
		{
			int asd = Push('s');
			ARE_EQUAL(-1, asd);
			DeleteFifo();
		}



		TEST_METHOD(PopTestOK)
		{
			NewFifo(1);
			Push('1');
			int asd = Pop();
			ARE_EQUAL((int)'1', (int)asd);
			DeleteFifo();
		}
		TEST_METHOD(PopTestOK2)
		{
			NewFifo(1);
			Push(255);
			int asd = Pop();
			ARE_EQUAL(255, asd);
			DeleteFifo();
		}
		TEST_METHOD(PopTestNOK)
		{
			NewFifo(1);
			int asd = Pop();
			ARE_EQUAL(-1, asd);
			DeleteFifo();
		}
		TEST_METHOD(PopTestNOK2)
		{
			Push('1');
			int asd = Pop();
			ARE_EQUAL(-1, asd);
		}


		TEST_METHOD(ClearFifoTestOK)
		{
			NewFifo(30);
			int asd = ClearFifo();
			ARE_EQUAL(0, asd);
			DeleteFifo();
		}
		TEST_METHOD(ClearFifoTestNOK)
		{
			int asd = ClearFifo();
			ARE_EQUAL(-1, asd);
		}


		TEST_METHOD(GetFreeTestOK)
		{
			NewFifo(30);
			Push('s');
			Push('s');
			int asd = GetFree();
			ARE_EQUAL(28, asd);
			DeleteFifo();
		}
		TEST_METHOD(GetFreeTestOK2)
		{
			NewFifo(1);
			Push('s');
			int asd = GetFree();
			ARE_EQUAL(0, asd);
			DeleteFifo();
		}
		TEST_METHOD(GetFreeTestNOK)
		{
			int asd = GetFree();
			ARE_EQUAL(-1, asd);
		}



		TEST_METHOD(GetSizeTestOK)
		{
			NewFifo(30);
			int asd = GetSize();
			ARE_EQUAL(30, asd);
			DeleteFifo();
		}


		TEST_METHOD(SetSizeTestOK)
		{
			NewFifo(30);
			SetSize(20);
			int asd = GetSize();
			ARE_EQUAL(20, asd);
			DeleteFifo();
		}

		TEST_METHOD(SetSizeTestOK2)
		{
			NewFifo(30);
			Push('a');
			SetSize(20);
			int asd = Pop();
			ARE_EQUAL((int)'a', asd);
			DeleteFifo();
		}

		TEST_METHOD(SetSizeTestOK3)
		{
			NewFifo(3);
			Push('a');
			Push('a');
			Push('a');
			int asd = Push('0');
			ARE_EQUAL(-1, asd);

			SetSize(4);
			int asd2 = Push('0');
			ARE_EQUAL(0, asd2);
			DeleteFifo();
		}
	};
}

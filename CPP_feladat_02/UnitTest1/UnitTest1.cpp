#include "pch.h"
#include "CppUnitTest.h"
#include "feladat2.h"

#define ARE_EQUAL(expVal, actVal) Assert::AreEqual(expVal, actVal, L"-", LINE_INFO())
#define WRITE(s) Logger::WriteMessage((const char*)s)

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

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
		TEST_METHOD(PushTest)
		{
			NewFifo(1);
			int asd = Push('s');
			ARE_EQUAL(0, asd);
			DeleteFifo();
		}
	};
}

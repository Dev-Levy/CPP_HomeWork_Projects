
//	Oláh Levente
//
//	  A3C6TV
//
//	 FELADAT: 7
//
//	 VERZIÓ: 2

#include "pch.h"
#include "CppUnitTest.h"
#include "../CPP_feladat_07/CPhoneList.h"
#include "../CPP_feladat_07/CPhoneIterName.h"
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(AppendTest)
        {
            CPhoneList phoneList;
            Record newRecord("John Doe", "1234567890");

            Assert::AreEqual(OK, phoneList.append(newRecord));
            
            for (int i = 0; i < MAXLENGTH; i++)
            {
                phoneList.append(newRecord);
            }
            Assert::AreEqual(NOK, phoneList.append(newRecord));
        }

        TEST_METHOD(DisplayNameTest)
        {
            CPhoneList phoneList;

            Record r1("a", "12");
            Record r2("b", "34");

            phoneList.append(r1);
            phoneList.append(r2);

            std::stringstream ss;
            auto oldCoutBuffer = std::cout.rdbuf();
            std::cout.rdbuf(ss.rdbuf());

            phoneList.displayname();

            std::cout.rdbuf(oldCoutBuffer);

            std::string expectedOutput = "\na;12\nb;34";
            Assert::AreEqual(expectedOutput, ss.str());
        }
        TEST_METHOD(BeginTest1)
        {
            CPhoneList phoneList;
            Record r1("a", "12");
            phoneList.append(r1);

            CPhoneIterName iter(phoneList);
            Record* rec = iter.begin();

            //is it giving back anything?
            Assert::IsNotNull(rec);
            Assert::AreEqual("a", rec->name);
            Assert::AreEqual("12", rec->number);
        }
        TEST_METHOD(BeginTest2)
        {
            CPhoneList phoneList;
            Record r1("a", "12");
            Record r2("b", "34");
            phoneList.append(r1);
            phoneList.append(r2);

            CPhoneIterName iter(phoneList);
            Record* rec = iter.begin();

            //is it giving back the right one?
            Assert::IsNotNull(rec);
            Assert::AreEqual("a", rec->name);
            Assert::AreEqual("12", rec->number);
        }
        TEST_METHOD(NextPrevTest)
        {
            CPhoneList phoneList;
            Record r1("a", "12");
            Record r2("b", "34");
            phoneList.append(r1);
            phoneList.append(r2);

            CPhoneIterName iter(phoneList);
            Record* rec = iter.begin();
            rec = iter.next();

            Assert::IsNotNull(rec);
            Assert::AreEqual("b", rec->name);

            rec = iter.prev();

            Assert::IsNotNull(rec);
            Assert::AreEqual("a", rec->name);
        }

        TEST_METHOD(EndTest)
        {
            CPhoneList phoneList;
            Record r1("a", "12");
            Record r2("c", "56");
            Record r3("b", "34");
            phoneList.append(r1);
            phoneList.append(r2);
            phoneList.append(r3);

            CPhoneIterName iter(phoneList);
            Record* rec = iter.end();

            Assert::IsNotNull(rec);
            Assert::AreEqual("c", rec->name);
            Assert::AreEqual("56", rec->number);
        }

        TEST_METHOD(SizeTest)
        {
            CPhoneList phoneList;
            Record r1("a", "12");

            for (size_t i = 0; i < 3; i++)
            {
                phoneList.append(r1);
            }

            CPhoneIterName iter(phoneList);

            Assert::AreEqual(3, iter.size());
        }

        TEST_METHOD(SearchTest)
        {
            CPhoneList phoneList;
            Record r1("a", "12");
            Record r2("c", "56");
            Record r3("b", "34");
            phoneList.append(r1);
            phoneList.append(r2);
            phoneList.append(r3);

            CPhoneIterName iter(phoneList);
            Record* rec = iter.search("c");

            Assert::IsNotNull(rec);
            Assert::AreEqual("c", rec->name);
            Assert::AreEqual("56", rec->number);
        }

        TEST_METHOD(OperatorPlusPlusTest)
        {
            CPhoneList phoneList;
            Record r1("a", "12");
            Record r2("c", "56");
            Record r3("b", "34");
            phoneList.append(r1);
            phoneList.append(r2);
            phoneList.append(r3);


            CPhoneIterName iter(phoneList);
            Record* rec = iter.begin();

            Assert::IsNotNull(rec);
            Assert::AreEqual("a", rec->name);
            Assert::AreEqual("12", rec->number);

            rec = ++iter;

            Assert::IsNotNull(rec);
            Assert::AreEqual("b", rec->name);
            Assert::AreEqual("34", rec->number);

            rec = ++iter;

            Assert::IsNotNull(rec);
            Assert::AreEqual("c", rec->name);
            Assert::AreEqual("56", rec->number);
        }

        TEST_METHOD(EmptyTest)
        {
            CPhoneList phoneList;
            CPhoneIterName iter(phoneList);
            Assert::IsTrue(iter.begin() == nullptr);
            Assert::IsTrue(iter.end() == nullptr);
            Assert::IsTrue(iter.next() == nullptr);
            Assert::IsTrue(iter.prev() == nullptr);
            Assert::IsTrue(iter.size() == 0);
            Assert::IsTrue(iter.search("a") == nullptr);
            Assert::IsTrue(iter.search(nullptr) == nullptr);
		}

        TEST_METHOD(SearchTest2)
        {
            CPhoneList phoneList;
            Record r1("a", "12");
            char s1[] = "a";
            char s2[] = "12";
            char s3[] = "b";
            phoneList.append(r1);

            CPhoneIterName iter(phoneList);
            Record* rec = iter.search(s1);
            Assert::AreEqual(s1, rec->name);
            Assert::AreEqual(s2, rec->number);

            rec = iter.search(s2);
            Assert::IsTrue(nullptr == rec);

            rec = iter.search(s3);
            Assert::IsTrue(nullptr == rec);

            rec = iter.search(nullptr);
            Assert::IsTrue(nullptr == rec);

		}
	};
}

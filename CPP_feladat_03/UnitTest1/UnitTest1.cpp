//  OLÁH LEVENTE
//
//     A3C6TV
//
//    FELADAT3
//
//    VERZIÓ: 1

#include "pch.h"
#include "CppUnitTest.h"
#include <filesystem>
#include <fstream>
#include "../CPP_feladat_03/feladat3.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(FiveTestFilesTest)
		{
			std::string testfiles[] = {
			"testin5.dat",
			"testin10.dat",
			"testin50.dat",
			"testin100.dat",
			"testin10000.dat"
			};
			unsigned char buffer[MYBUFSIZE] = {};

			for (size_t i = 0; i < 5; i++)
			{
				char* infn = (char*)testfiles[i].c_str();
				std::string outfnstr = testfiles[i] + ".srt";
				char* outfn = (char*)outfnstr.c_str();

				//opens
				std::ifstream ifs(infn, std::ios::binary);
				Assert::IsTrue(ifs.is_open());
				ifs.close();

				//sorts
				int ret = sortfile(infn, outfn, buffer, MYBUFSIZE);
				Assert::AreEqual(OK, ret);

				//writes output
				Assert::IsTrue(std::filesystem::exists(outfn));

				//same size
				std::uintmax_t input_size = std::filesystem::file_size(infn);
				std::uintmax_t output_size = std::filesystem::file_size(outfn);
				Assert::AreEqual(input_size, output_size);

			}
		}
		TEST_METHOD(NOK_tests)
		{
			unsigned char buffer[MYBUFSIZE] = {};

			//nullptr
			char* infn1 = nullptr;
			char* outfn1 = nullptr;
			int ret1 = sortfile(infn1, outfn1, buffer, MYBUFSIZE);
			Assert::AreEqual(NOK, ret1);


			//negative buffer size
			std::string foo2 = "testin5.dat";
			char* infn2 = (char*)foo2.data();
			char* outfn2 = (char*)foo2.data();
			int ret2 = sortfile(infn2, outfn2, buffer, -2);
			Assert::AreEqual(NOK, ret2);

			//too big buffer size
			std::string foo3 = "testin5.dat";
			char* infn3 = (char*)foo3.data();
			char* outfn3 = (char*)foo3.data();
			int ret3 = sortfile(infn3, outfn3, buffer, MYBUFSIZE + 1);
			Assert::AreEqual(NOK, ret3);
		}
	};
}

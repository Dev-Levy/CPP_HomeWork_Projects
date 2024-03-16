#include "pch.h"
#include "CppUnitTest.h"
#include <filesystem>
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
				char* outfn = (char*)((testfiles[i] + ".srt").c_str());

				int ret = sortfile(infn, outfn, buffer, MYBUFSIZE);
				Assert::AreEqual(OK, ret);


				Assert::IsTrue(std::filesystem::exists(outfn));


				std::uintmax_t input_size = std::filesystem::file_size(infn);
				std::uintmax_t output_size = std::filesystem::file_size(outfn);
				Assert::AreEqual(input_size, output_size);
			}
		}
		TEST_METHOD(NOK_tests)
		{
			unsigned char buffer[MYBUFSIZE] = {};
			char* infn = nullptr;
			char* outfn = (char*)"testout.dat";
			int ret = sortfile(infn, outfn, buffer, MYBUFSIZE);
			Assert::AreEqual(NOK, ret);
		}
	};
}

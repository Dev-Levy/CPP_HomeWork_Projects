#include "pch.h"
#include "CppUnitTest.h"
#include "../CPP_feladat_03/feladat3.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			unsigned char buffer[MYBUFSIZE] = {};

			//ezt hogyan?
			char* infn = " ide kéne az input file path ";

			std::string outfn = std::string(infn) + ".srt";
			
			sortfile(infn, (char*)outfn.data(), buffer, MYBUFSIZE);
		}
	};
}

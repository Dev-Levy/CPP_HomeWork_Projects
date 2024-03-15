#include "feladat3.h"
#include <string>
#include <iostream>

int main(int argc, char* argv[]) {

	unsigned char buffer[MYBUFSIZE] = {};

	char* infn = argv[1];
	std::string outfn = std::string(infn) + ".srt";

	sortfile(infn, (char*)outfn.data(), buffer, MYBUFSIZE);

}
#include "feladat3.h"
#include <string>
#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {

	char** q;
	printf("argc: %d\nargv[0]: %s\nArgumentum lista:\n", argc, argv[0]);
	while (--argc > 0)
	{
		printf((argc > 1) ? "%s " : "%s\n", *++argv);
	}

	std::string filename = argv[0];
	;
}
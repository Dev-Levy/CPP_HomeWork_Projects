#include "feladat3.h"
#include <iostream>
#include <fstream>
using namespace std;
#define MYBUFSIZE 8192
#define MYMAXVALUE 65535
#define MYMAXFN 128
#define OK 0
#define NOK (-1)

int sortfile(char* infn, char* outfn, unsigned char* buf, unsigned short bufsize)
{
	//beolvasás
	ifstream ifs(infn, ios_base::binary); //binary !
	if (ifs.is_open())
	{
		unsigned short n;

		while (ifs.read((char*)&n, sizeof(n))) {

		}

		ifs.close();
	}





	//kiírás
	ofstream ofs; ofs.open(outfn, ios_base::binary);
	if (ofs.bad())
		return(NOK);
	unsigned short n = 27540;

	ofs.write((char*)&n, sizeof(n));

	ofs.close();
}

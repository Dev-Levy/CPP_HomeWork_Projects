#include "feladat3.h"
#include <iostream>
#include <fstream>



int sortfile(char* infn, char* outfn, unsigned char* buf, unsigned short bufsize)
{
	if (infn == nullptr || outfn == nullptr || buf == nullptr)
		return NOK;
	else if (bufsize < 0 || bufsize > MYBUFSIZE)
		return NOK;


	//beolvasás
	std::ifstream ifs(infn, std::ios_base::binary); //binary !
	if (ifs.is_open())
	{
		unsigned short n;
		int i = 0;
		while (ifs.read((char*)&n, sizeof(n))) {


			int whichBite = n / 8;
			int whichBit = n % 8;

			buf[whichBite] |= (1 << whichBit);
			std::cout << i++ << ". " << n << ' ' << (int)buf[whichBite] << std::endl;
		}
		ifs.close();
	}
	else
		return NOK;



	std::cout << std::endl;



	//kiírás
	std::ofstream ofs;
	ofs.open(outfn, std::ios_base::binary);
	if (ofs.bad())
		return NOK;

	unsigned short n = 0;
	int num = 0;
	for (int i = 0; i < bufsize; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (buf[i] >> j & 1) {
				n = i * 8 + j;
				ofs.write((char*)&n, sizeof(n));
				std::cout << num++ << ". " << n << std::endl;
			}
		}
	}
	ofs.close();

	//visszaállítás
	for (size_t i = 0; i < MYBUFSIZE; i++)
		buf[i] = NULL;

	return OK;
}

//  OL�H LEVENTE
//
//     A3C6TV
//
//    FELADAT3
//
//    VERZI�: 1


#pragma once
#define MYBUFSIZE 8192
#define MYMAXVALUE 65535
#define MYMAXFN 128
#define OK 0
#define NOK (-1)

int sortfile(char* infn,	// input �llom�ny neve
	char* outfn,			// output �llom�ny neve
	unsigned char* buf,     // felhaszn�lt buffer c�me
	unsigned short bufsize);// felhaszn�lt buffer m�rete
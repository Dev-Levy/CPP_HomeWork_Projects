//  OLÁH LEVENTE
//
//     A3C6TV
//
//    FELADAT3
//
//    VERZIÓ: 1


#pragma once
#define MYBUFSIZE 8192
#define MYMAXVALUE 65535
#define MYMAXFN 128
#define OK 0
#define NOK (-1)

int sortfile(char* infn,	// input állomány neve
	char* outfn,			// output állomány neve
	unsigned char* buf,     // felhasznált buffer címe
	unsigned short bufsize);// felhasznált buffer mérete
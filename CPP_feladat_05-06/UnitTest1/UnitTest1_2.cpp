#include "pch.h"
#include "CppUnitTest.h"


#include <sstream>
#include <cstddef>
#include <iostream>
#include <exception>

#include <crtdbg.h>
#include "../CPP_feladat_05/CMyString.h"
#include "../CPP_feladat_05/CMyStringException.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

// const char *	-> strcmp !!! 
// char *	-> ptr1==ptr2 !!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!

#define ARE_EQUAL(expVal, actVal) Assert::AreEqual(expVal, actVal, L"-", LINE_INFO())
#define ARE_EQUALSTR(expVal, actVal) Assert::AreEqual((const char *)expVal, (const char *)actVal, L"-", LINE_INFO())
#define ARE_EQUALPTR(expVal, actVal) Assert::AreEqual((char *)expVal, (char *)actVal, L"-", LINE_INFO())

#define ARE_NOTEQUAL(expVal, actVal) Assert::AreNotEqual(expVal, actVal, L"-", LINE_INFO())
#define ARE_NOTEQUALSTR(expVal, actVal) Assert::AreNotEqual((const char *)expVal, (const char *)actVal, L"-", LINE_INFO())
#define ARE_NOTEQUALPTR(expVal, actVal) Assert::AreNotEqual((char *)expVal, (char *)actVal, L"-", LINE_INFO())

#define IS_TRUE(b) Assert::IsTrue(b, L"-", LINE_INFO())
#define WRITE(s) Logger::WriteMessage((const char*)s)
#define TEST(expVal, actVal, msg) Assert::AreEqual(expVal, actVal, msg, LINE_INFO())

#define CMYSTRINGEXCEPTION CMyStringException
#define CMYSTRING CMyString
#define MASODIK


#ifdef MYDEBUG
#define __MYDEBUG
#endif


namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		//OK
		TEST_METHOD(TM_constructor_def)
		{//OK
			WRITE("** CMyString() **");
#ifdef __MYDEBUG
			CMYSTRING::clearobjcount(); //unittest miatt!
#endif
			try
			{
				WRITE("CMYSTRING s");
				CMyString s;
				ARE_EQUAL((size_t)0, s.size());
				ARE_EQUAL((size_t)1, s.capacity());
				const char* p = s.c_str();
				ARE_NOTEQUAL(p, nullptr);
				ARE_EQUAL('\0', *p);
				try {
					s.getat(0); // ->ErrOutOfRange
					IS_TRUE(false); //ide nem juthat
				}
				catch (CMYSTRINGEXCEPTION& e) { ARE_EQUAL(CMYSTRINGEXCEPTION::ErrOutOfRange, e.what()); }


			}
			catch (bad_alloc) { WRITE("ERROR: bad_alloc"); IS_TRUE(false);}
			catch (...) { WRITE("ERROR: catch(...)"); IS_TRUE(false);}

#ifdef __MYDEBUG
				ARE_EQUAL(0u, CMYSTRING::objcount());	
#endif
			WRITE("** Done **\n");
		}

		//OK
		TEST_METHOD(TM_constructor_const_char_ptr) //?
		{//OK
			WRITE("** CMyString(const char* psz) **");
#ifdef __MYDEBUG
			CMYSTRING::clearobjcount(); //unittest miatt!
#endif
			try
			{


				WRITE("CMYSTRING s(p)");
				const char* p = "ALMA";
				CMYSTRING s(p);
				ARE_EQUAL( strlen(p),  s.size() );
				ARE_EQUAL( strlen(p) + 1, s.capacity() );
				const char* p1 = s.c_str();
				ARE_NOTEQUAL(p1, nullptr);
				IS_TRUE(p1 != p);
				ARE_EQUAL(p, p1);
				try
				{
					s.getat(strlen(p)); // ->ErrOutOfRange
					IS_TRUE(false); //ide nem juthat
				}
				catch (CMYSTRINGEXCEPTION& e) { ARE_EQUAL(CMYSTRINGEXCEPTION::ErrOutOfRange, e.what()); }

				WRITE("CMYSTRING s1(nullptr)");
				CMYSTRING s1(nullptr); // üres str -> def.const
				ARE_EQUAL((size_t)0, s1.size());
				ARE_EQUAL((size_t)1, s1.capacity());
				const char* p2 = s1.c_str();
				IS_TRUE(p2 != nullptr);
				ARE_EQUAL('\0', *p2);
				try {
					s1.getat(0); // ->ErrOutOfRange
					IS_TRUE(false); //ide nem juthat
				}
				catch (CMYSTRINGEXCEPTION& e) { ARE_EQUAL(CMYSTRINGEXCEPTION::ErrOutOfRange, e.what()); }
			}
			catch (bad_alloc) { WRITE("ERROR: bad_alloc"); IS_TRUE(false);}
			catch (...) { WRITE("ERROR: catch(...)"); IS_TRUE(false);}
#ifdef __MYDEBUG
			ARE_EQUAL(0u, CMYSTRING::objcount());
#endif

			WRITE("** Done **\n");
		}

		//OK
		TEST_METHOD(TM_constructor_rep)
		{
			WRITE("** CMyString(char ch, size_t nRepeat = 1) **");
#ifdef __MYDEBUG
			CMYSTRING::clearobjcount(); //unittest miatt!
#endif
			try
			{
				WRITE("CMYSTRING s('*', 5)");
				const char* p = "*****";
				CMYSTRING s('*', 5);
				ARE_EQUAL(strlen(p), (size_t)s.size());
				ARE_EQUAL(strlen(p) + 1, (size_t)s.capacity());
				const char* p1 = s.c_str();
				IS_TRUE(p1 != nullptr);
				ARE_EQUALSTR(p, p1);
				try
				{
					s.getat((size_t)strlen(p)); // ->ErrOutOfRange
					IS_TRUE(false); //ide nem juthat
				}
				catch (CMYSTRINGEXCEPTION& e) { ARE_EQUAL(CMYSTRINGEXCEPTION::ErrOutOfRange, e.what()); }

				WRITE("CMYSTRING s2(' ')"); // nRepeat=1 !
				const char* p2 = " ";
				CMYSTRING s2(' ');
				ARE_EQUAL(strlen(p2), s2.size());
				ARE_EQUAL(strlen(p2) + 1, s2.capacity());
				const char* p3 = s2.c_str();
				IS_TRUE(p3 != nullptr);
				ARE_EQUAL(p2, p3);
				try
				{
					s2.getat(strlen(p2)); // ->ErrOutOfRange
					IS_TRUE(false); //ide nem juthat
				}
				catch (CMYSTRINGEXCEPTION& e) { ARE_EQUAL(CMYSTRINGEXCEPTION::ErrOutOfRange, e.what()); }

				try
				{
					WRITE("CMYSTRING s(0, 5)");
					CMYSTRING s('\0', 5); // ->ErrInvalidChar
					IS_TRUE(false); //ide nem juthat
				}
				catch (CMYSTRINGEXCEPTION& e) { ARE_EQUAL(CMYSTRINGEXCEPTION::ErrInvalidChar, e.what()); 

				
				}

				try
				{
					WRITE("CMYSTRING s('*', 0)");
					CMYSTRING s('*', 0); // ->ErrCount
					IS_TRUE(false); //ide nem juthat
				}
				catch (CMYSTRINGEXCEPTION& e) { ARE_EQUAL(CMYSTRINGEXCEPTION::ErrCount, e.what()); 
				
	
				}
			}
			catch (bad_alloc) { WRITE("ERROR: bad_alloc"); IS_TRUE(false);}
			catch (...)	{WRITE("ERROR: catch(...)"); IS_TRUE(false);}

#ifdef __MYDEBUG
			ARE_EQUAL(0u, CMYSTRING::objcount());
#endif
			WRITE("** Done **\n");
		}

		//OK
		TEST_METHOD(TM_copyconstr)
		{
			WRITE("** Copy const **");
#ifdef __MYDEBUG
			CMYSTRING::clearobjcount(); //unittest miatt!
#endif
			try
			{
				WRITE("CMYSTRING s = s2,  <- ALMA");
				const char* q = "ALMA";
				CMYSTRING s2(q);
				CMYSTRING s = s2;

				ARE_EQUAL(strlen(q), s.size());
				ARE_EQUAL(strlen(q) + 1, s.capacity());
				const char* p = s.c_str();
				IS_TRUE(p != nullptr);
				IS_TRUE(s2.c_str() != s.c_str());
				ARE_EQUAL(q, s.c_str());

				WRITE("CMYSTRING s3 = s4, <- EMPTY ");
				CMYSTRING s4;
				CMYSTRING s3 = s4;

				ARE_EQUAL((size_t)0, s3.size());
				ARE_EQUAL((size_t)1, s3.capacity());
				const char* p2 = s3.c_str();
				IS_TRUE(p2 != nullptr);
				ARE_EQUAL('\0', *p2);
				IS_TRUE(s4.c_str() != s3.c_str());

				WRITE("CMYSTRING s5 = s6, s6: m_nAllocLength > (m_nDataLength+1) ");

				CMYSTRING s6("NARANCS");
				size_t n = s6.capacity();
				CMYSTRING s7("EPER");
				s6 = s7;
				ARE_EQUAL(n, s6.capacity()); // nem változik az m_nAllocLength
				CMYSTRING s5 = s6;
				IS_TRUE(s5.c_str() != s6.c_str());
				ARE_EQUAL(s6.c_str(), s5.c_str());  //EPER
				ARE_EQUAL(s5.size(), s6.size());
				ARE_EQUAL(s5.size() + 1, s5.capacity()); 
			}
			catch (bad_alloc) { WRITE("ERROR: bad_alloc"); IS_TRUE(false);}
			catch (...) { WRITE("ERROR: catch(...)"); IS_TRUE(false);}
#ifdef __MYDEBUG
			ARE_EQUAL(0u, CMYSTRING::objcount());
#endif
			WRITE("** Done **\n");
		}

		//OK
		TEST_METHOD(TM_display)
		{
			WRITE("** display **");
#ifdef __MYDEBUG
			CMYSTRING::clearobjcount(); //unittest miatt!
#endif
			try
			{
				stringstream buffer;
				streambuf* prevcoutbuf = cout.rdbuf(buffer.rdbuf());

				WRITE("alma");
				CMYSTRING s("alma");
				buffer = std::stringstream();
				//buffer.str(std::string());
				s.display();
				string d = buffer.str();
				WRITE(d.c_str());
				IS_TRUE(!d.compare("alma"));  // nem kell \n  a Display-be!

				WRITE("empty");
				CMYSTRING s2;
				buffer = std::stringstream();
				s2.display();
				d = buffer.str();
				IS_TRUE(!d.length());
				WRITE("üres, ok");
				WRITE(d.c_str());

				cout.rdbuf(prevcoutbuf);

				
			}
			catch (bad_alloc) { WRITE("ERROR: bad_alloc"); IS_TRUE(false);}
			catch (...) { WRITE("catch(...)"); IS_TRUE(false);}
#ifdef __MYDEBUG
			ARE_EQUAL(0u, CMYSTRING::objcount());
#endif
			WRITE("** Done **\n");
			
		}
		
		//OK
		TEST_METHOD(TM_getsetat)
		{
			WRITE("** get_setat **");
#ifdef __MYDEBUG
			CMYSTRING::clearobjcount(); //unittest miatt!
#endif
			try
			{
				
								
				try
				{
					//char buf[16];
					char t[] = "EPER";
					CMYSTRING s("ALMA");
					for (size_t i = 0; i < s.size(); i++)
					{
						//sprintf_s(buf, sizeof(buf), "%d", i); WRITE(buf);
						s.setat(i, t[i]);
						IS_TRUE(s.getat(i) == t[i]);
					}
					ARE_EQUAL(t, s.c_str());
					ARE_EQUAL(strlen(t), s.size());
					ARE_EQUAL(strlen(t) + 1, s.capacity());
				}
				catch (...) { WRITE("Setgetat catch(...)"); IS_TRUE(false); }

				WRITE("getat(0)");
				try
				{
					CMYSTRING s;
					char ch = s.getat(0); // -> ErrOutOfRange
					IS_TRUE(false); //ide nem juthat
				}
				catch (CMYSTRINGEXCEPTION& e) { ARE_EQUAL(CMYSTRINGEXCEPTION::ErrOutOfRange, e.what()); }

				WRITE("setat(0,'*')");
				try
				{
					CMYSTRING s;
					s.setat(0, '*'); // -> ErrOutOfRange
					IS_TRUE(false); //ide nem juthat
				}
				catch (CMYSTRINGEXCEPTION& e) { ARE_EQUAL(CMYSTRINGEXCEPTION::ErrOutOfRange, e.what()); }

				WRITE("getat(7)");
				try
				{
					CMYSTRING s("NARANCS");
					char ch = s.getat(7); // -> ErrOutOfRange
					IS_TRUE(false); //ide nem juthat
				}
				catch (CMYSTRINGEXCEPTION& e) { ARE_EQUAL(CMYSTRINGEXCEPTION::ErrOutOfRange, e.what()); }

				WRITE("setat(7,'*')");
				try
				{
					CMYSTRING s("NARANCS");
					s.setat(7, '*'); // -> ErrOutOfRange
					IS_TRUE(false); //ide nem juthat
				}
				catch (CMYSTRINGEXCEPTION& e) { ARE_EQUAL(CMYSTRINGEXCEPTION::ErrOutOfRange, e.what()); }
				
			}
			catch (bad_alloc) { WRITE("ERROR: bad_alloc"); IS_TRUE(false);}
			catch (...) { WRITE("ERROR: catch(...)"); IS_TRUE(false);}
#ifdef __MYDEBUG
			ARE_EQUAL(0u, CMYSTRING::objcount());
#endif

			WRITE("** Done **\n");
		}

		//OK, reverse
		TEST_METHOD(TM_reverse)
		{
			WRITE("** reverse **");
#ifdef __MYDEBUG
			CMYSTRING::clearobjcount(); //unittest miatt!
#endif
			try
			{
				

				WRITE("CMYSTRING s");
				CMYSTRING s;
				s.reverse();

				WRITE("CMYSTRING s1(\"0123\")");
				CMYSTRING s1("0123");
				s1.reverse();
				ARE_EQUAL("3210", s1.c_str());

				WRITE("CMYSTRING s2(\"01234\")");
				CMYSTRING s2("01234");
				s2.reverse();
				ARE_EQUAL("43210", s2.c_str());

				WRITE("CMYSTRING s3(\"0\")");
				CMYSTRING s3("0");
				s3.reverse();
				ARE_EQUAL("0", s3.c_str());

				
			}
			catch (bad_alloc) { WRITE("ERROR: bad_alloc"); IS_TRUE(false);}
			catch (...) { WRITE("ERROR: catch(...)"); IS_TRUE(false);}
		#ifdef __MYDEBUG
				ARE_EQUAL(0u, CMYSTRING::objcount());
		#endif

			WRITE("** Done **\n");
		}

		//OK, shrink_to_fit
		TEST_METHOD(TM_srink_to_fit)
		{
			WRITE("** shrink_to_fit **");
#ifdef __MYDEBUG
			CMYSTRING::clearobjcount(); //unittest miatt!
#endif
			try
			{
				WRITE("NARANCS");
				CMYSTRING s1("NARANCSNARANCSNARANCS");
				CMYSTRING s2("EPER");
				const char* p = s1.c_str();
				s1 = s2;
				s1.shrink_to_fit();
				ARE_EQUAL((size_t)4, s1.size());
				ARE_EQUAL((size_t)5, s1.capacity());
				
				ARE_NOTEQUALPTR( p, s1.c_str()); 

				WRITE("empty");
				CMYSTRING s3;
				s3.shrink_to_fit();
				ARE_EQUAL((size_t)0, s3.size());
				ARE_EQUAL((size_t)1, s3.capacity());
				ARE_EQUAL('\0', *s3.c_str());
			}
			catch (bad_alloc) { WRITE("ERROR: bad_alloc"); IS_TRUE(false); }
			catch (...) { WRITE("ERROR: catch(...)"); IS_TRUE(false); }
#ifdef __MYDEBUG
			ARE_EQUAL(0u, CMYSTRING::objcount());
#endif

			WRITE("** Done **\n");
		}
		
		//OK
		TEST_METHOD(TM_assignmentoperator)
		{
			WRITE("** operator=(const _CMyString & str) **");
#ifdef __MYDEBUG
			CMYSTRING::clearobjcount(); //unittest miatt!
#endif
			try
			{
				

				WRITE("operator=, s = s1, EMPTY <- EMPTY");
				CMYSTRING s;
				CMYSTRING s1;
				s = s1; // két üres string, üres marad
				ARE_EQUAL((size_t)0, s.size());
				ARE_EQUAL((size_t)1, s.capacity());
				const char* p = s.c_str();
				IS_TRUE(p != nullptr);
				IS_TRUE(p != s1.c_str());
				IS_TRUE(s.c_str() != s1.c_str());
				ARE_EQUAL('\0', *p);

				
				WRITE("operator=, s4 = *p1, saját maga");
				const char* p3 = "NARANCS";
				CMYSTRING s4(p3);
				const char* p4 = s4.c_str();
				CMYSTRING* p5 = &s4;
				s4 = *p5;		// azonos string, s4 nem változik meg
				ARE_EQUAL(p4, s4.c_str()); //nem változik, THIS vizsgálat nélkül is mûködik, ha belefér a memóriába, azonos esetben belefér!
				ARE_EQUAL(strlen(p3), s4.size());
				ARE_EQUAL(strlen(p3) + 1, s4.capacity());

				WRITE("operator=, s5 = s6, DIO <- NARANCS");
				const char* p6 = "DIO";
				CMYSTRING s5(p6);			//s5 DIO
				const char* p7 = s5.c_str();
				const char* p8 = "NARANCS";
				CMYSTRING s6(p8);			//s6 NARANCS
				s5 = s6;	//DIO <- NARANCS
				IS_TRUE(s5.c_str() != nullptr);
				IS_TRUE(p7 != s5.c_str());  //p7 már érvénytelen címre mutat
				ARE_EQUAL(strlen(p8), s5.size()); //NARANCS
				ARE_EQUAL(s5.capacity(), s5.size() + 1);  //NARANCS + 1
				ARE_EQUAL(p8, s5.c_str());  //NARANCS

				WRITE("operator=, s5 = s6, NARANCS <- EPER");
				const char* p9 = "EPER";
				CMYSTRING s7(p9);
				const char* p10 = s5.c_str();
				s5 = s7;  //NARANCS <- EPER ,  m_nAllocLength - NARANCS, nem változhat!
				IS_TRUE(s5.c_str() != nullptr);
				IS_TRUE(p10 == s5.c_str()); // nagyobb helyre kerül a kisebb string, nem változhat a ptr
				ARE_EQUAL(strlen(p9), s5.size()); //EPER
				ARE_EQUAL(strlen(p8) + 1, s5.capacity()); //nem változhat, NARANCS m_nAllocLength!
				ARE_EQUAL(p9, s5.c_str()); //EPER

				WRITE("s8 = s9 = s10, DIO <- EMPTY <- EPER");
				CMYSTRING s8(p6), s9, s10(p9);
				s8 = s9 = s10; //DIO <- "" <- EPER
				ARE_EQUAL(strlen(p9), s8.size()); // p9 EPER !
				ARE_EQUAL(s8.size(), s9.size());
				ARE_EQUAL(s9.size(), s10.size());

				//TARTALOM ellenõrzés!
				ARE_EQUAL(s8.c_str(), s9.c_str());  
				ARE_EQUAL(s9.c_str(), s10.c_str());

				ARE_EQUAL(strlen(p9) + 1, s8.capacity()); // p9 EPER !
				ARE_EQUAL(s8.capacity(), s9.capacity());
				ARE_EQUAL(s9.capacity(), s10.capacity());

				//PTR ellenõrzés, más memóriára kell mutatniuk
				IS_TRUE(s8.c_str() != s9.c_str());
				IS_TRUE(s9.c_str() != s10.c_str());
				IS_TRUE(s8.c_str() != s10.c_str());
							
			}
			catch (bad_alloc) { WRITE("ERROR: bad_alloc"); IS_TRUE(false);}
			catch (...) { WRITE("ERROR: catch(...)"); IS_TRUE(false);}
#ifdef __MYDEBUG
			ARE_EQUAL(0u, CMYSTRING::objcount());
#endif

			WRITE("** Done **\n");
		}

		//OK
		TEST_METHOD(TM_append1)
		{

			// Egyes fv-nél 0xFE-vel tölti ki a buffert DEBUG módban, 
			// a fv végrehajtása elõtt a túlírás láthatóvátételéhez
			// paraméter a max buffer méret, ameddig tölti, 0 esetén tiltjaa funkciót
			//_CrtSetDebugFillThreshold(0);

			WRITE("** append1() **");
#ifdef __MYDEBUG
			CMYSTRING::clearobjcount(); //unittest miatt!
#endif
			try
			{
				WRITE("append, EMPTY += nullptr");
				CMYSTRING s;
				const char* q = s.c_str();
				s.append(nullptr); //Nem változik
				IS_TRUE(nullptr != s.c_str());
				IS_TRUE(q == s.c_str());
				ARE_EQUAL((size_t)0, s.size());
				ARE_EQUAL((size_t)1, s.capacity());
				ARE_EQUAL('\0', *s.c_str());

				WRITE("append, ALMA += nullptr");
				const char* p = "ALMA";
				CMYSTRING s1(p);
				s1.append(nullptr); //Nem változik
				IS_TRUE(nullptr != s1.c_str());
				ARE_EQUAL(strlen(p), s1.size());
				ARE_EQUAL(s1.size() + 1, s1.capacity());
				ARE_EQUAL(p, s1.c_str());

				WRITE("append, BANAN += NARANCS");
				const char* p2 = "BANAN";
				CMYSTRING s2(p2);
				const char* p3 = "NARANCS";
				s2.append(p3);
				char b[32];

				strcpy_s(b, sizeof(b), p2); //BANAN
				strcat_s(b, sizeof(b), p3); //BANANNARANCS
				ARE_EQUAL(strlen(b), s2.size());
				ARE_EQUAL(s2.size() + 1, s2.capacity());
				ARE_EQUAL((const char*)b, s2.c_str());

				//capacity, size esetei
				WRITE("operator=, BANANNARANCS <- EPER, kisebb nagyobb területre");
				const char* p4 = "EPER";
				CMYSTRING s3(p4);
				s2 = s3; //BANANNARANCS <- EPER
				ARE_EQUAL(strlen(p4), s2.size()); //érdemi tartalom változik - size
				ARE_EQUAL(strlen(b) + 1, s2.capacity());  //nem változhat a capacity
				ARE_EQUAL(s2.c_str(), p4);

				WRITE("append, EPER += DIO, (mem:BANANNARANCS)"); // nagyobb a memória az s2-ben, mint az összefuzott stringek!
				const char* p5 = "DIO";
				char b1[32];
				strcpy_s(b1, sizeof(b1), p4);   //EPER
				strcat_s(b1, sizeof(b1), p5);	//EPERDIO
				s2.append(p5);					//EPER += DIO
				ARE_EQUAL(strlen(b1), s2.size());
				ARE_EQUAL(strlen(b) + 1, s2.capacity());  //BANANNARANCS memóriaméret miatt nem változik!
				ARE_EQUAL((const char*)b1, s2.c_str());

				WRITE("append, EPER += DIO- 7  (mem:NARANCS - 7), capacity nem változik");
				CMYSTRING s4("NARANCS");
				char* p6 = (char *)s4.c_str();
				CMYSTRING s5("EPER");
				s4 = s5;
				s4.append("DIO");

				ARE_EQUAL((size_t)7, s4.size());	//EPERDIO
				ARE_EQUAL((size_t)7 + 1, s4.capacity());  //EPERDIO + '\0'
				IS_TRUE(p6 == s4.c_str()); //nem változhat a memória, hiszen el kell férnie!

				WRITE("append, EPER + DIO + X- 8  (mem:NARANCS - 7), capacity változik");
				s4.append("X");
				ARE_EQUAL((size_t)8, s4.size());	//EPERDIOX
				ARE_EQUAL((size_t)8 + (size_t)1, s4.capacity());  //EPERDIOX + '\0'
				IS_TRUE( s4.c_str() != nullptr); //nem lehet nullptr!

				{
					#include <stdio.h>
					char buf[64];
					sprintf_s(buf, sizeof(buf),"p6:%p, s4.c_str():%p", p6, s4.c_str());
					WRITE(buf);
				}
				IS_TRUE(p6 != s4.c_str()); //változnia kell a memóriának, mert nem férhet el. 
											//p6 már érvénytelen címre mutat!

			
			}
			catch (bad_alloc) { WRITE("ERROR: bad_alloc"); IS_TRUE(false);}
			catch (...) { WRITE("ERROR: catch(...)"); IS_TRUE(false); }
#ifdef __MYDEBUG
			ARE_EQUAL(0u, CMYSTRING::objcount());
#endif

			WRITE("** Done **\n");
		}
		
		//OK
		TEST_METHOD(TM_append2)
		{
			WRITE("** append2(psz, offset, count) **");
#ifdef __MYDEBUG
			CMYSTRING::clearobjcount(); //unittest miatt!
#endif
			try
			{

				WRITE("append, EMPTY += nullptr");
				CMYSTRING s;
				const char* q = s.c_str();
				s.append(nullptr, 1, 2); //Nem változik
				IS_TRUE(nullptr != s.c_str());
				IS_TRUE(q == s.c_str());
				ARE_EQUAL((size_t)0, s.size());
				ARE_EQUAL((size_t)1, s.capacity());
				ARE_EQUAL('\0', *s.c_str());

				WRITE("append, ALMA += nullptr");
				const char* p = "ALMA";
				CMYSTRING s1(p);
				s1.append(nullptr, 1, 2); //Nem változik
				IS_TRUE(nullptr != s1.c_str());
				ARE_EQUAL(strlen(p), s1.size());
				ARE_EQUAL(s1.size() + 1, s1.capacity());
				ARE_EQUAL(p, s1.c_str());

				//
				//normál érték
				
				WRITE("append(NARANCS, 2,2), BANAN += RA");
				const char* p2 = "BANAN";
				CMYSTRING s2(p2);

				const char* p3 = "NARANCS";
				s2.append(p3, 2, 2);
				char b[32];

				strcpy_s(b, sizeof(b), p2); //BANAN
				strncat_s(b, sizeof(b), p3 + 2, 2); //BANANRA
				ARE_EQUAL(strlen(b), s2.size());
				ARE_EQUAL(s2.size() + 1, s2.capacity());
				ARE_EQUAL((const char*)b, s2.c_str());
				
				{//pont a string végén az offset
					WRITE("append(NARANCS, 2,5), BANAN += RANCS");
					const char* p2 = "BANAN";
					CMYSTRING s2(p2);
					const char* p3 = "NARANCS";
					s2.append(p3, 2, 5);
					char b[32];

					strcpy_s(b, sizeof(b), p2); //BANAN
					strncat_s(b, sizeof(b), p3 + 2, 5); //BANANRANCS
					ARE_EQUAL(strlen(b), s2.size());
					ARE_EQUAL(s2.size() + 1, s2.capacity());
					ARE_EQUAL((const char*)b, s2.c_str());

				}

				{//túl mutat az offset a string végén
					WRITE("append(NARANCS, 2,10), BANAN += RANCS");
					const char* p2 = "BANAN";
					CMYSTRING s2(p2);
					const char* p3 = "NARANCS";
					s2.append(p3, 2, 5);
					char b[32];

					strcpy_s(b, sizeof(b), p2); //BANAN
					strncat_s(b, sizeof(b), p3 + 2, 5); //BANANRA
					ARE_EQUAL(strlen(b), s2.size());
					ARE_EQUAL(s2.size() + 1, s2.capacity());
					ARE_EQUAL((const char*)b, s2.c_str());

				}

				//capacity, size esetei
				strcpy_s (b, sizeof(b)-1, "BANANNARANCS");
				s2 = b;
				WRITE("operator=, BANANNARANCS <- EPER, kisebb nagyobb területre");
				const char* p4 = "EPER";
				CMYSTRING s3(p4);
				s2 = s3; //BANANNARANCS <- EPER
				ARE_EQUAL(strlen(p4), s2.size()); //érdemi tartalom változik - size
				ARE_EQUAL(strlen(b) + 1, s2.capacity());  //nem változhat a capacity
				ARE_EQUAL(s2.c_str(), p4);

				WRITE("append, EPER += I, (mem:BANANNARANCS)"); // nagyobb a memória az s2-ben, mint az összefuzott stringek!
				const char* p5 = "DIO";
				char b1[32];
				strcpy_s(b1, sizeof(b1), p4);   //EPER
				strncat_s(b1, sizeof(b1), p5+1, 1);	//EPERI
				s2.append(p5,1,1); 	//EPER += I
				ARE_EQUAL(strlen(b1), s2.size());
				ARE_EQUAL(strlen(b) + 1, s2.capacity());  //BANANNARANCS memóriaméret miatt nem változik!
				ARE_EQUAL((const char*)b1, s2.c_str());

				WRITE("append, EPER += DIO- 7  (mem:NARANCS - 7), capacity nem változik");
				CMYSTRING s4("NARANCS");
				char* p6 = (char*)s4.c_str();
				CMYSTRING s5("EPER");
				s4 = s5;
				s4.append("DIO", 0, 3);

				ARE_EQUAL((size_t)7, s4.size());	//EPERDIO
				ARE_EQUAL((size_t)7 + 1, s4.capacity());  //EPERDIO + '\0'
				IS_TRUE(p6 == s4.c_str()); //nem változhat a memória, hiszen el kell férnie!

				WRITE("append, EPER + DIO + X- 8  (mem:NARANCS - 7), capacity változik");
				char* p7 = (char*)s4.c_str();
				s4.append("X",0,1);
				ARE_EQUAL((size_t)8, s4.size());	//EPERDIOX
				ARE_EQUAL((size_t)8 + (size_t)1, s4.capacity());  //EPERDIOX + '\0'
				IS_TRUE(s4.c_str() != nullptr); //nem lehet nullptr!
				IS_TRUE( (char *)s4.c_str() != p7); //változnia kell!

				/*{
					#include <stdio.h>
					char buf[64];
					sprintf_s(buf, sizeof(buf), "p6:%p, s4.c_str():%p", p6, s4.c_str());
					WRITE(buf);
				}*/
				IS_TRUE(p6 != s4.c_str()); //változnia kell a memóriának, mert nem férhet el. p6 már érvénytelen címre mutat!

			}
			catch (bad_alloc) { WRITE("ERROR: bad_alloc"); IS_TRUE(false); }
			catch (...) { WRITE("ERROR: catch(...)"); IS_TRUE(false); }
#ifdef __MYDEBUG
			ARE_EQUAL(0u, CMYSTRING::objcount());
#endif

			WRITE("** Done **\n");
		}

		//OK
		TEST_METHOD(TM_objcount)
		{
			WRITE("** objcount **");
#ifdef __MYDEBUG
			CMYSTRING::clearobjcount(); //unittest miatt!
#endif

#ifdef __MYDEBUG
			try
			{
				{
					WRITE("MYDEBUG");
					CMYSTRING s("KORTE");
					ARE_EQUAL(1u, s.objcount());
				}
				ARE_EQUAL(0u, CMYSTRING::objcount());
			}
			catch (bad_alloc) { WRITE("ERROR: bad_alloc"); IS_TRUE(false);}
			catch (...) { WRITE("ERROR: catch(...)"); IS_TRUE(false);}
#else
			WRITE("no MYDEBUG");
#endif
	
			WRITE("** Done **\n");
		}


#ifdef MASODIK

		//OK
		TEST_METHOD(TM_move)
		{
			WRITE("** Move **");
#ifdef __MYDEBUG
			CMYSTRING::clearobjcount(); //unittest miatt!
#endif
			try
			{
				WRITE("CMyString(CMyString && str)");
				try {
					CMYSTRING t("DATOLYA");
					CMYSTRING s = move(t);
					ARE_NOTEQUALPTR(nullptr, t.c_str());
					ARE_EQUAL('\0', *t.c_str());
					ARE_EQUAL((size_t)7, s.size());
					ARE_EQUAL((size_t)8, s.capacity());
					ARE_EQUAL((size_t)0, t.size());
					ARE_EQUAL((size_t)1, t.capacity());
					ARE_EQUALSTR("DATOLYA", s.c_str());
				}
				catch (...) { WRITE("catch(...)"); IS_TRUE(false); }

				try {
					CMYSTRING t;
					CMYSTRING s = move(t);
					IS_TRUE(nullptr != t.c_str());
					ARE_EQUAL((size_t)0, s.size());
					ARE_EQUAL((size_t)1, s.capacity());
					ARE_EQUAL((size_t)0, t.size());
					ARE_EQUAL((size_t)1, t.capacity());
					ARE_NOTEQUAL((char*)s.c_str(), (char*)t.c_str()); //mind a kettõ üres, a ptr-nek nem szabad egyezniük
				}
				catch (...) { WRITE("catch(...)"); IS_TRUE(false); }

				WRITE("operator=(CMyString&& str)");
				try {
					CMYSTRING t("DATOLYA");
					CMYSTRING s("DIO");
					s = move(t);
					IS_TRUE(nullptr != t.c_str());
					ARE_EQUAL("DATOLYA", s.c_str());
					ARE_EQUAL((size_t)7, s.size());
					ARE_EQUAL((size_t)8, s.capacity());
					ARE_EQUAL((size_t)0, t.size());
					ARE_EQUAL((size_t)1, t.capacity());
				}
				catch (...) { WRITE("catch(...)"); IS_TRUE(false); }

				try {
					CMYSTRING s("NARANCS");
					CMYSTRING* p = &s;
					s = move(*p);
					ARE_EQUAL((size_t)7, s.size());  //nem változik, mert saját maga
					ARE_EQUAL((size_t)8, s.capacity());
					ARE_EQUAL("NARANCS", s.c_str());
				}
				catch (...) { WRITE("catch(...)"); IS_TRUE(false); }

				try {
					CMYSTRING t("DATOLYA");
					CMYSTRING s;
					s = move(t);
					IS_TRUE(nullptr != t.c_str());
					ARE_EQUAL("DATOLYA", s.c_str());
					ARE_EQUAL((size_t)7, s.size());
					ARE_EQUAL((size_t)8, s.capacity());
					ARE_EQUAL((size_t)0, t.size());
					ARE_EQUAL((size_t)1, t.capacity());
				}
				catch (...) { WRITE("catch(...)"); IS_TRUE(false); }

			}
			catch (bad_alloc) { WRITE("ERROR: bad_alloc"); IS_TRUE(false);}
			catch (...) { WRITE("ERROR: catch(...)"); IS_TRUE(false);}

#ifdef __MYDEBUG
			ARE_EQUAL(0u, CMYSTRING::objcount());
#endif

			WRITE("** Done **\n");
		}
		
		//OK
		TEST_METHOD(TM_simpleoperators)
		{
			WRITE("** SimpleOperators **");
#ifdef __MYDEBUG
			CMYSTRING::clearobjcount(); //unittest miatt!
#endif
			try
			{

				WRITE("operator[](size_t nIndex)");
				try {
					CMYSTRING s("ANANASZ");
					s[(size_t)1] = 'm';
					ARE_EQUAL("AmANASZ", s.c_str());
					char c = s[(size_t)3];
					ARE_EQUAL('N', c);
					ARE_EQUAL((size_t)7, s.size());
					CMYSTRING s2("EPER");
					s = s2;			// ANANASZHOZ tartozó lefoglalt memória megmarad!
					try {
						s[(size_t)7] = 'x';	
						
						IS_TRUE(false); //ide nem kerülhet, ha van ellenõrzés!
					}
					catch (CMYSTRINGEXCEPTION& e) { ARE_EQUAL(CMYSTRINGEXCEPTION::ErrOutOfRange, e.what()); /*IS_TRUE(false)*/;

					}
				}
				catch (CMYSTRINGEXCEPTION& e) { ARE_EQUAL(CMYSTRINGEXCEPTION::ErrOutOfRange, e.what()); }
				catch (bad_alloc) { WRITE("ERROR: bad_alloc"); IS_TRUE(false);}
				catch (...) { WRITE("catch(...)"); IS_TRUE(false); }

				
				try
				{
					char t[] = "EPER";
					CMYSTRING s("ALMA");
					for (size_t i = 0; i < s.size(); i++)
					{
						s[i] = t[i];
						ARE_EQUAL(t[i], s[i]);
					}
					ARE_EQUAL("EPER", s.c_str());
				}
				catch (...) { WRITE("catch(...)"); IS_TRUE(false); }




				WRITE("bool operator==(const CMyString& s1);");
				try {
					CMYSTRING s1("ANANASZ");
					CMYSTRING s2("ANANASZ");
					CMYSTRING s3("EPER");
					CMYSTRING s4;
					CMYSTRING s5("EPERDIO");
					IS_TRUE( s1 == s2 );
					IS_TRUE( !(s2 == s3) );
					IS_TRUE( !(s3 == s4) ); //empty
					IS_TRUE( !(s3 == s5) ); //egyik a másik folytatása
				}
				catch (...) { WRITE("catch(...)"); IS_TRUE(false); }

				try {
					CMYSTRING s1("EPER");
					CMYSTRING s2("ALMA");
					IS_TRUE( !(s1 == s2) );

					CMYSTRING s3("ALMA");
					CMYSTRING s4("ANANÁSZ");
					IS_TRUE(!(s3 == s4));

				}
				catch (...) { WRITE("catch(...)"); IS_TRUE(false); }



				WRITE("operator const char *()");
				try {
					CMYSTRING s("ANANASZ");
					const char* p = (const char*)s;
					ARE_EQUAL((char*)p, (char*)s.c_str());	//char *-> ptr1==ptr2 !!!
					CMYSTRING s2;
					const char* p2 = (const char*)s2;
					ARE_EQUAL((char*)p2, (char*)s2.c_str());	//char *-> ptr1==ptr2 !!!
				}
				catch (...) { WRITE("catch(...)"); IS_TRUE(false); }
			}
			catch (bad_alloc) { WRITE("ERROR: bad_alloc"); IS_TRUE(false);}
			catch (...) { WRITE("ERROR: catch(...)"); IS_TRUE(false);}

#ifdef __MYDEBUG
			ARE_EQUAL(0u, CMYSTRING::objcount());
#endif

			WRITE("** Done **\n");
		}

		//OK
		TEST_METHOD(TM_addoperators)
		{
			WRITE("** AddOperators  **");
#ifdef __MYDEBUG
			CMYSTRING::clearobjcount(); //unittest miatt!
#endif
			try
			{

				WRITE("CMyString& operator+=(const _CMyString& str)");
				try {
					CMYSTRING s1("ANANASZ");
					CMYSTRING s2("banán");
					s1 += s2;
					ARE_EQUAL("ANANASZbanán", s1.c_str());
					ARE_EQUAL((size_t)12, s1.size());
					ARE_EQUAL((size_t)13, s1.capacity()); 
					ARE_EQUAL("banán", s2.c_str());
					ARE_EQUAL((size_t)5, s2.size());
				}
				catch (...) { WRITE("catch(...)"); IS_TRUE(false); }

				try {
					CMYSTRING s1;
					CMYSTRING s2("banán");
					s1 += s2;
					ARE_EQUAL("banán", s1.c_str());
					ARE_EQUAL((size_t)5, s1.size());
					ARE_EQUAL((size_t)6, s1.capacity());
					ARE_EQUAL("banán", s2.c_str());
					ARE_EQUAL((size_t)5, s2.size());
					ARE_EQUAL((size_t)6, s2.capacity());
				}
				catch (...) { WRITE("catch(...)"); IS_TRUE(false); }

				try {
					CMYSTRING s1("ANANASZ");
					const char* p = s1.c_str();
					CMYSTRING s2;
					s1 += s2; //nem változhat semmi
					ARE_EQUAL("ANANASZ", s1.c_str());
					ARE_EQUAL(p, s1.c_str());
					ARE_EQUAL((size_t)7, s1.size());
					ARE_EQUAL((size_t)8, s1.capacity());
					ARE_EQUAL((size_t)0, s2.size());
					ARE_EQUAL((size_t)1, s2.capacity());
				}
				catch (...) { WRITE("catch(...)"); IS_TRUE(false); }

				try {
					CMYSTRING s1;
					CMYSTRING s2;
					s1 += s2; //nem változhat semmi
					ARE_EQUAL((size_t)0, s1.size());
					ARE_EQUAL((size_t)1, s1.capacity());
					ARE_EQUAL((size_t)0, s2.size());
					ARE_EQUAL((size_t)1, s2.capacity());
					IS_TRUE((char*)s2.c_str() != (char*)s1.c_str());
					
				}
				catch (...) { WRITE("catch(...)"); IS_TRUE(false); }

				WRITE("CMyString& operator+=(const char* p)");
				try {
					CMYSTRING s1("ANANASZ");
					const char* s2 = "banán";
					s1 += s2;
					ARE_EQUAL("ANANASZbanán", s1.c_str());
					ARE_EQUAL((size_t)12, s1.size());
					ARE_EQUAL((size_t)13, s1.capacity());
					IS_TRUE((char*)s2 != (char*)s1.c_str()); //ptr!
				}
				catch (...) { WRITE("catch(...)"); IS_TRUE(false); }

				try {
					CMYSTRING s1;
					const char* s2 = "banán";
					s1 += s2;
					ARE_EQUAL("banán", s1.c_str());
					ARE_EQUAL((size_t)5, s1.size());
					ARE_EQUAL((size_t)6, s1.capacity());
					IS_TRUE((char*)s2 != (char*)s1.c_str()); //ptr!
				}
				catch (...) { WRITE("catch(...)"); IS_TRUE(false); }

				try {
					CMYSTRING s1("ANANASZ");
					const char* s2 = nullptr;
					s1 += s2; //nem változik semmi
					ARE_EQUAL("ANANASZ", s1.c_str());
					ARE_EQUAL((size_t)7, s1.size());
					ARE_EQUAL((size_t)8, s1.capacity());
					IS_TRUE((char*)s2 != (char*)s1.c_str()); //ptr!
				}
				catch (...) { WRITE("catch(...)"); IS_TRUE(false); }

				try {
					CMYSTRING s1;
					const char* s2 = nullptr;
					s1 += s2; //nem változik
					ARE_EQUAL((size_t)0, s1.size());
					ARE_EQUAL((size_t)1, s1.capacity());
					IS_TRUE((char*)s2 != (char*)s1.c_str());

				}
				catch (...) { WRITE("catch(...)"); IS_TRUE(false); }

				try {
					CMYSTRING s1("111"), s2("222"), s3("333");
					s1 += s2 += s3;
					ARE_EQUAL((size_t)9, s1.size());
					ARE_EQUAL((size_t)10, s1.capacity());
					ARE_EQUAL("111222333", s1.c_str());
					ARE_EQUAL((size_t)6, s2.size());
					ARE_EQUAL((size_t)7, s2.capacity());
					ARE_EQUAL("222333", s2.c_str());
					ARE_EQUAL((size_t)3, s3.size());
					ARE_EQUAL((size_t)4, s3.capacity());
					ARE_EQUAL("333", s3.c_str());
					ARE_NOTEQUAL((char*)s1.c_str(), (char*)s2.c_str());
					ARE_NOTEQUAL((char*)s2.c_str(), (char*)s3.c_str());

				}
				catch (...) { WRITE("catch(...)"); IS_TRUE(false); }

				try {
					CMYSTRING s1("0123456789"), s2("ALMA"), s3("DIO");
					
					const char* p = s1.c_str();
					s1 = s2;	//s1:0123456789-> ALMA
					ARE_EQUAL( (char *)p, (char*)s1.c_str());
					ARE_EQUAL("ALMA", s1.c_str());
					ARE_EQUAL((size_t)4, s1.size());
					ARE_EQUAL((size_t)11, s1.capacity());
					s1 += s3;	//s1: ALMA -> ALMADIO, nem változik a capacity
					ARE_EQUAL((char*)p, (char*)s1.c_str());
					ARE_EQUAL("ALMADIO", s1.c_str());
					ARE_EQUAL((size_t)7, s1.size());
					ARE_EQUAL((size_t)11, s1.capacity());
				}
				catch (...) { WRITE("catch(...)"); IS_TRUE(false); }

				try {// s1 += s2 -> s2 = s1.c_str(); ptr-t adok hozzá!
					CMYSTRING s1("ANANASZ");
					const char* s2 = s1.c_str();
					s1 += s2;
					ARE_EQUAL("ANANASZ", s1.c_str());  //marad minden
					ARE_EQUAL((size_t)7, s1.size());
					ARE_EQUAL((size_t)8, s1.capacity());
				}
				catch (...) { WRITE("catch(...)"); IS_TRUE(false); }


				WRITE("CMyString operator +(const CMyString& str1)");
				try {
					CMYSTRING s1("ANANASZ");
					CMYSTRING s2("banán");
					CMYSTRING s3("eper");
					s1 = s2 + s3;
					ARE_EQUAL("banáneper", s1.c_str());
					ARE_EQUAL((size_t)10, s1.capacity());
					ARE_EQUAL((size_t)9, s1.size());
					ARE_EQUAL("banán", s2.c_str());
					ARE_EQUAL((size_t)5, s2.size());
					ARE_EQUAL((size_t)6, s2.capacity());
					ARE_EQUAL("eper", s3.c_str());
					ARE_EQUAL((size_t)4, s3.size());
					ARE_EQUAL((size_t)5, s3.capacity());
				}
				catch (...) { WRITE("catch(...)"); IS_TRUE(false); }

				try {
					CMYSTRING s1("ANANASZ");
					CMYSTRING s2;
					CMYSTRING s3("eper");
					s1 = s2 + s3;
					ARE_EQUAL("eper", s1.c_str());
					ARE_EQUAL((size_t)4, s1.size());
					ARE_EQUAL((size_t)5, s1.capacity());
					ARE_EQUAL((size_t)0, s2.size());
					ARE_EQUAL((size_t)1, s2.capacity());
					ARE_EQUAL("eper", s3.c_str());
					ARE_EQUAL((size_t)4, s3.size());
					ARE_EQUAL((size_t)5, s3.capacity());
				}
				catch (...) { WRITE("catch(...)"); IS_TRUE(false); }

				try {
					CMYSTRING s1("ANANASZ");
					CMYSTRING s2("banán");
					CMYSTRING s3;
					s1 = s2 + s3;
					ARE_EQUAL("banán", s1.c_str());
					ARE_EQUAL((size_t)5, s1.size());
					ARE_EQUAL((size_t)6, s1.capacity());
					ARE_EQUAL("banán", s2.c_str());
					ARE_EQUAL((size_t)5, s2.size());
					ARE_EQUAL((size_t)6, s2.capacity());
					ARE_EQUAL((size_t)0, s3.size());
					ARE_EQUAL((size_t)1, s3.capacity());
				}
				catch (...) { WRITE("catch(...)"); IS_TRUE(false); }

				try {
					CMYSTRING s1("ANANASZ");
					CMYSTRING s2("banán");
					CMYSTRING s3("eper");
					CMYSTRING s4("dió");
					s1 = s2 + s3 + s4;
					ARE_EQUAL("banáneperdió", s1.c_str());
					ARE_EQUAL((size_t)12, s1.size());
					ARE_EQUAL((size_t)13, s1.capacity());
					ARE_EQUAL("banán", s2.c_str());
					ARE_EQUAL((size_t)5, s2.size());
					ARE_EQUAL((size_t)6, s2.capacity());
					ARE_EQUAL("eper", s3.c_str());
					ARE_EQUAL((size_t)4, s3.size());
					ARE_EQUAL((size_t)5, s3.capacity());
					ARE_EQUAL("dió", s4.c_str());
					ARE_EQUAL((size_t)3, s4.size());
					ARE_EQUAL((size_t)4, s4.capacity());
				}
				catch (...) { WRITE("catch(...)"); IS_TRUE(false); }

				try {
					CMYSTRING s1;
					CMYSTRING s2("banán");
					CMYSTRING s3("eper");
					CMYSTRING s4("dió");
					s1 = s2 + s3 + s4;
					ARE_EQUAL("banáneperdió", s1.c_str());
					ARE_EQUAL((size_t)12, s1.size());
					ARE_EQUAL((size_t)13, s1.capacity());
					ARE_EQUAL("banán", s2.c_str());
					ARE_EQUAL((size_t)5, s2.size());
					ARE_EQUAL((size_t)6, s2.capacity());
					ARE_EQUAL("eper", s3.c_str());
					ARE_EQUAL((size_t)4, s3.size());
					ARE_EQUAL((size_t)5, s3.capacity());
					ARE_EQUAL("dió", s4.c_str());
					ARE_EQUAL((size_t)3, s4.size());
					ARE_EQUAL((size_t)4, s4.capacity());
				}
				catch (...) { WRITE("catch(...)"); IS_TRUE(false); }

				try {
					CMYSTRING s1;
					CMYSTRING s2;
					CMYSTRING s3;
					CMYSTRING s4;
					s1 = s2 + s3 + s4;
					ARE_NOTEQUAL((char*)s1.c_str(), (char*)s2.c_str());
					ARE_NOTEQUAL((char*)s2.c_str(), (char*)s3.c_str());
					ARE_NOTEQUAL((char*)s3.c_str(), (char*)s4.c_str());
					ARE_EQUAL((size_t)0, s1.size());
					ARE_EQUAL((size_t)1, s1.capacity());
					ARE_EQUAL((size_t)0, s2.size());
					ARE_EQUAL((size_t)1, s2.capacity());
					ARE_EQUAL((size_t)0, s3.size());
					ARE_EQUAL((size_t)1, s3.capacity());
					ARE_EQUAL((size_t)0, s4.size());
					ARE_EQUAL((size_t)1, s4.capacity());
				}
				catch (...) { WRITE("catch(...)"); IS_TRUE(false); }
			}
			catch (bad_alloc) { WRITE("ERROR: bad_alloc"); IS_TRUE(false);}
			catch (...) { WRITE("ERROR: catch(...)"); IS_TRUE(false);}

#ifdef __MYDEBUG
			ARE_EQUAL(0u, CMYSTRING::objcount());
#endif

			WRITE("** Done **\n");
		}

		//OK
		TEST_METHOD(TM_substr)
		{
			WRITE("** SubStr  **");
#ifdef __MYDEBUG
			CMYSTRING::clearobjcount(); //unittest miatt!
#endif
			try
			{
				WRITE("lm");
				CMYSTRING s1, s2("alma");
				s1 = s2.substring(1, 2);
				ARE_EQUAL("lm", s1.c_str());

				WRITE("a");
				s1 = s2.substring(0, 1);
				ARE_EQUAL("a", s1.c_str());

				WRITE("alma");
				s1 = s2.substring(0, 10);
				ARE_EQUAL("alma", s1.c_str());

				WRITE("alma,0");
				s1 = s2.substring(0);   
				ARE_EQUAL("alma", s1.c_str());

				WRITE("alma,1");
				s1 = s2.substring(1); //pos=1, len:-1 !
				ARE_EQUAL("lma", s1.c_str());

				WRITE("alma,2");
				s1 = s2.substring(2);   
				ARE_EQUAL("ma", s1.c_str());

				WRITE("alma,3");
				s1 = s2.substring(3);
				ARE_EQUAL("a", s1.c_str());

				WRITE("alma,4");
				s1 = s2.substring(4);
				ARE_EQUAL( '\0', *s1.c_str());

				WRITE("empty,10");
				s1 = s2.substring(4, 10);
				ARE_EQUAL((size_t)0, s1.size());
				ARE_EQUAL((size_t)1, s1.capacity());

				WRITE("empty,1");
				s1 = s2.substring(4, 1);
				ARE_EQUAL((size_t)0, s1.size());
				ARE_EQUAL((size_t)1, s1.capacity());

				try
				{
					WRITE("ErrOutOfRange1");
					s1 = s2.substring(10, 1);
					ARE_EQUAL((size_t)0, s1.size());
					ARE_EQUAL((size_t)1, s1.capacity());
					IS_TRUE(false); //ide nem juthat
				}
				catch (CMYSTRINGEXCEPTION& e) { ARE_EQUAL(CMYSTRINGEXCEPTION::ErrOutOfRange, e.what()); }

				try
				{
					WRITE("ErrOutOfRange2");
					s1 = s2.substring(10, -1);
					ARE_EQUAL((size_t)0, s1.size());
					ARE_EQUAL((size_t)1, s1.capacity());
					IS_TRUE(false); //ide nem juthat
				}
				catch (CMYSTRINGEXCEPTION& e) { ARE_EQUAL(CMYSTRINGEXCEPTION::ErrOutOfRange, e.what()); }
			}
			catch (bad_alloc) { WRITE("ERROR: bad_alloc"); IS_TRUE(false);}
			catch (...) { WRITE("ERROR: catch(...)"); IS_TRUE(false);}

#ifdef __MYDEBUG
			ARE_EQUAL(0u, CMYSTRING::objcount());
#endif

			WRITE("** Done **\n");
		}

		//OK
		TEST_METHOD(TM_cout)
		{
			WRITE("** Cout **");
#ifdef __MYDEBUG
			CMYSTRING::clearobjcount(); //unittest miatt!
#endif
			try
			{

				WRITE(" Cout ");
				WRITE("cout << alma");

				stringstream buffer;
				streambuf* prevcoutbuf = cout.rdbuf(buffer.rdbuf());
				CMYSTRING s("alma");
				buffer = std::stringstream();
				//buffer.str(std::string());
				cout << s;
				string d = buffer.str();
				WRITE(d.c_str());
				IS_TRUE( !d.compare("alma") );  // nem kell \n  a Display-be!

				WRITE("cout << empty");
				CMYSTRING s2;
				buffer = std::stringstream();
				cout << s2;
				d = buffer.str();
				IS_TRUE(!d.length());
				WRITE("üres, ok");
				WRITE(d.c_str());

				cout.rdbuf(prevcoutbuf);


			}
			catch (bad_alloc) { WRITE("ERROR: bad_alloc"); IS_TRUE(false);}
			catch (...) { WRITE("ERROR: catch(...)"); IS_TRUE(false);}

#ifdef __MYDEBUG
			ARE_EQUAL(0u, CMYSTRING::objcount());
#endif
			WRITE("** Done **\n");
		}

		//OK
		TEST_METHOD(TM_swap)
		{
			WRITE("** swap **");
#ifdef __MYDEBUG
			CMYSTRING::clearobjcount(); //unittest miatt!
#endif
			try
			{
				CMYSTRING s1("alma"), s2("narancs"), sEmpty1, sEmpty2;

				const char* pAlma = s1.c_str();
				const char* pNarancs = s2.c_str();
				const char* pEmpty1 = sEmpty1.c_str();
				const char* pEmpty2 = sEmpty2.c_str();
				
				WRITE("sEmpty1.swap(sEmpty2)");
				sEmpty1.swap(sEmpty2);
				IS_TRUE(sEmpty1.c_str() != sEmpty2.c_str());
				ARE_EQUAL((size_t)0, sEmpty1.size());
				ARE_EQUAL((size_t)1, sEmpty1.capacity());
				//ARE_EQUAL( pEmpty2 == sEmpty1.c_str()); üres!
				ARE_EQUAL('\0', *sEmpty2.c_str());
				ARE_EQUAL((size_t)0, sEmpty2.size());
				ARE_EQUAL((size_t)1, sEmpty2.capacity());
				//IS_TRUE(pEmpty1 == sEmpty2.c_str());  üres!
				ARE_EQUAL('\0', *sEmpty2.c_str());

				sEmpty1.swap(sEmpty2); // vissza az eredeti

				WRITE("s1.swap(s2)");
				s1.swap(s2);	// -> s1 = narancs, s2 = alma
				ARE_EQUAL((size_t)7, s1.size());
				ARE_EQUAL((size_t)8, s1.capacity());
				IS_TRUE( (char *)pNarancs == (char*)s1.c_str());
				ARE_EQUAL("narancs", s1.c_str());
				ARE_EQUAL((size_t)4, s2.size());
				ARE_EQUAL((size_t)5, s2.capacity());
				IS_TRUE((char*)pAlma == (char*)s2.c_str());
				ARE_EQUAL("alma", s2.c_str());
				s1.swap(s2); //vissza az eredeti 
				
				WRITE("s1.swap(sEmpty1)");
				s1.swap(sEmpty1);	// -> s1 = empty, sEmpty1 = alma
				ARE_EQUAL((size_t)0, s1.size());
				ARE_EQUAL((size_t)1, s1.capacity());
				ARE_EQUAL('\0', *s1.c_str()); 
				IS_TRUE(pEmpty1 == s1.c_str()); 
				ARE_EQUAL((size_t)4, sEmpty1.size());
				ARE_EQUAL((size_t)5, sEmpty1.capacity());
				ARE_EQUAL("alma", sEmpty1.c_str());
				IS_TRUE(pAlma == sEmpty1.c_str());
				s1.swap(sEmpty1); // vissza az eredeti

				WRITE("sEmpty2.swap(s2)");
				sEmpty2.swap(s2);  // -> sEmpty2 = narancs, s2 = empty
				ARE_EQUAL((size_t)0, s2.size());
				ARE_EQUAL((size_t)1, s2.capacity());
				ARE_EQUAL('\0', *s2.c_str());
				IS_TRUE(pEmpty2 == s2.c_str()); 
				ARE_EQUAL((size_t)7, sEmpty2.size());
				ARE_EQUAL((size_t)8, sEmpty2.capacity());
				ARE_EQUAL("narancs", sEmpty2.c_str());
				IS_TRUE(pNarancs == sEmpty2.c_str());
				sEmpty2.swap(s2); // vissza az eredetit
		
				WRITE("s3.swap(s4)");
				CMYSTRING s3("banan"), s4("dio");
				s3 = s4;
				const char* pDio6 = s3.c_str();
				const char* pDio4 = s4.c_str();
				ARE_EQUAL((size_t)3, s3.size());
				ARE_EQUAL((size_t)6, s3.capacity());
				s3.swap(s4);  // -> s3 = dio, 3/4,  s4 = dio 3/6
				ARE_EQUAL((size_t)3, s3.size());
				ARE_EQUAL((size_t)4, s3.capacity());
				ARE_EQUAL("dio", s3.c_str());
				IS_TRUE((char*)pDio4 == (char*)s3.c_str()); // move
				ARE_EQUAL((size_t)3, s4.size());
				ARE_EQUAL((size_t)6, s4.capacity());
				ARE_EQUAL("dio", s4.c_str()); // move!
				IS_TRUE((char*)pDio6 == (char*)s4.c_str());
				IS_TRUE((char*)s3.c_str() != (char*)s4.c_str());


				const char* pc5 = "narancs";
				
				CMYSTRING s5("narancs");
				char* p5 = (char*)s5.c_str();
				CMYSTRING* ps5 = &s5;
				s5.swap(*ps5);
				ARE_EQUAL(p5, (char*)s5.c_str());

				try {
					CMYSTRING s5("EPER");
					s5.swap(s5);
				}
				catch (...) { WRITE("ERROR: catch(...) s5.swap(s5)"); IS_TRUE(false); }

				
			}
			catch (bad_alloc) { WRITE("ERROR: bad_alloc"); IS_TRUE(false);}
			catch (...) { WRITE("ERROR: catch(...)"); IS_TRUE(false); }

#ifdef __MYDEBUG
			ARE_EQUAL(0u, CMYSTRING::objcount());
#endif


			WRITE("** Done **\n");
		}


		TEST_METHOD(TM_cin)
		{
			WRITE("** cin  **");
#ifdef __MYDEBUG
		CMYSTRING::clearobjcount(); //unittest miatt!
#endif
			try
			{
				WRITE(" cin - alma ");
				const char* p = "alma";
				std::istringstream sin{ p };
				auto cin_rdbuf = std::cin.rdbuf(sin.rdbuf());

				CMYSTRING s;
				std::cin >> s;

				WRITE(p);
				WRITE(s.c_str());
				ARE_EQUALSTR(p, s.c_str());

				std::cin.rdbuf(cin_rdbuf);
			}
			catch (bad_alloc) { WRITE("ERROR: bad_alloc"); }
			catch (...) { WRITE("ERROR: catch(...)"); }
			
#ifdef __MYDEBUG
			ARE_EQUAL(0u, CMYSTRING::objcount());
#endif
			WRITE("** Done **");
		}



//		TEST_METHOD(TM_SABLON)
//		{
//			WRITE("**  **");
//#ifdef __MYDEBUG
//		CMYSTRING::clearobjcount(); //unittest miatt!
//#endif
//			try
//			{
//		
//				WRITE(" ? ");
//		
//			}
//			catch (bad_alloc) { WRITE("ERROR: bad_alloc"); }
//			catch (...) { WRITE("ERROR: catch(...)"); }
//
//#ifdef __MYDEBUG
//			ARE_EQUAL(0u, CMYSTRING::objcount());
//#endif
//			WRITE("** Done **");
//		}
#endif

	};
}

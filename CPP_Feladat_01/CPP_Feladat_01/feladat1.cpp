#include <string>

double feladat1(const char* s)
{
	//const char* k = s + 1;
	std::string num = "";

	//trimming WS from the start
	while (*s < '!')
	{
		s++;
		//k++;
	}

	//hexa num

	//if (*s == '0' && *k == 'x')
	if (*s == '0')
	{
		//k++;
		s++;
		if (*s == 'x')
		{
			s++;
			while (*s >= '0' && *s <= '9' || *s >= 'a' && *s <= 'f' || *s >= 'A' && *s <= 'F')
			{
				num += *s;
				s++;
			}
		}
		return -5.0;
	}

	//dec num
	else
	{

		if (*s == '-')
		{
			num += '-';
			s++;
		}
		while (*s >= '0' && *s <= '9' || *s != '.')
		{
			num += *s;
			s++;
		}
		if (*s != '.')
		{
			return -5.0;
		}
		else
		{
			num += *s;
			s++;
			while (*s >= '0' && *s <= '9')
			{
				num += *s;
				s++;
			}
		}
	}
	return -5.0;
}

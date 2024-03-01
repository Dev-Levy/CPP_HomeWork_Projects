#include <string>

double feladat1(const char* s)
{
	double ans = 0.0;
	bool positive = true;
	const char* k = s + 1;

	std::string num = "";

	//trimming WS from the start
	while (*s < '!')
	{
		s++;
		k++;
	}

	//hexa num

	if (*s == '0' && *k == 'x')
	{
		k++;
		while (*k >= '0' && *k <= '9' || *k >= 'a' && *k <= 'f' || *k >= 'A' && *k <= 'F')
		{
			switch (*k)
			{
			case 'a':
			case 'A':
				ans = ans * 16 + 10;
				break;
			case 'b':
			case 'B':
				ans = ans * 16 + 11;
				break;
			case 'c':
			case 'C':
				ans = ans * 16 + 12;
				break;
			case 'd':
			case 'D':
				ans = ans * 16 + 13;
				break;
			case 'e':
			case 'E':
				ans = ans * 16 + 14;
				break;
			case 'f':
			case 'F':
				ans = ans * 16 + 15;
				break;
			default:
				ans = ans * 16 + *k - '0';
			}

			num += *k;
			k++;
		}
		return ans;
	}

	//dec num

	else
	{
		if (*s == '-')
		{
			positive = false;

			num += '-';
			s++;
		}
		while (*s >= '0' && *s <= '9')
		{
			//double
			ans = ans * 10 + *s - '0';

			num += *s;

			s++;
		}
		if (*s != '.')
		{
			//hiba van, ezért visszatér az addigi eredménnyel
			return ans;
		}
		else
		{
			num += *s;
			s++;
			int i = 10;
			while (*s >= '0' && *s <= '9')
			{
				int numericForm = (*s - '0');

				double fractionForm = static_cast<double>(numericForm) / i;

				ans = ans + fractionForm;
				i *= 10;

				num += *s;
				s++;
			}
		}
	}

	if (positive)
		return ans;
	else
		return -ans;
}

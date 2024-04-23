#include "CMyVector.h"
#include "CMyString.h"

extern template CMyVector <int>;

int main() {
	auto asd = CMyVector<CMyString>(4);
	asd.push_back(CMyString("asd"));
	asd.push_back(CMyString("qwe"));
	asd.push_back(CMyString("zxc"));
	asd.push_back(CMyString("rty"));
	asd.push_back(CMyString("fgh"));

	asd.list();
	asd.sort(true);
	asd.list();
	asd.sort(false);
	asd.list();

	return 0;
}
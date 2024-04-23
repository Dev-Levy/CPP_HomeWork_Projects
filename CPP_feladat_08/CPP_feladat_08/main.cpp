#include "CMyVector.h"

extern template CMyVector <int>;

int main() {
	auto asd = CMyVector<int>(4);
	asd.push_back(456);
	asd.push_back(346);
	asd.push_back(789);
	asd.push_back(123);
	auto asdasd = asd[2];
	asd.list();

	asd.sort(true);

	asd.list();

	asd.sort(false);

	asd.list();
	auto qwe = asd.capacity();
}
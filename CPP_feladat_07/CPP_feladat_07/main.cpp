#include "CPhoneList.h"


int main() {
	Record r1("John", "1234567");
	Record r2("Mary", "2345678");
	Record r3("Tom", "3456789");
	Record r4("Jerry", "4567890");
	Record r5("Alice", "5678901");
	Record r6("Bob", "6789012");
	Record r7("David", "7890123");
	Record r8("Eve", "8901234");
	Record r9("Frank", "9012345");
	Record r10("Grace", "0123456");

	CPhoneList list;

	list.append(r1);
	list.append(r2);
	list.append(r3);
	list.append(r4);
	list.append(r5);
	list.append(r6);
	list.append(r7);
	list.append(r8);
	list.append(r9);
	list.append(r10);

	CPhoneIterName iter1(list);


	list.displayname();
}
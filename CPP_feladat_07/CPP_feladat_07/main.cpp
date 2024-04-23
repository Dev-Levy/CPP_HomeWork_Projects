


#include "CPhoneList.h"
#include "CPhoneIterName.h"
#include <iostream>


int main() {
	Record r1("john", "123-456-7890");
	Record r2("Anne", "234-567-8901");
	Record r3("zack", "345-678-9012");
	Record r4("Sara", "456-789-0123");
	Record r5("Mike", "567-890-1234");
	Record r6("Tom", "678-901-2345");
	Record r7("jerry", "789-012-3456");
	Record r8("Linda", "890-123-4567");
	Record r9("sue", "901-234-5678");
	Record r10("Bob", "012-345-6789");

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
	

	CPhoneIterName iter(list);

	list.displayname();

	iter.search("asd");
}
#include "common.hpp"

#define TESTED_TYPE std::string

int		main(void)
{
	TESTED_NAMESPACE::list<TESTED_TYPE> lst(8);
	TESTED_NAMESPACE::list<TESTED_TYPE> lst2;
	TESTED_NAMESPACE::list<TESTED_TYPE> lst3;
	TESTED_NAMESPACE::list<TESTED_TYPE>::iterator it = lst.begin();

	for (unsigned long int i = 0; i < lst.size(); ++i)
		*it++ = std::string((lst.size() - i), i + 65);
	printSize(lst);

	std::cout << "\tpush_back():\n" << std::endl;

	lst.push_front("Hey");
	lst.push_back("One long string");
	lst2.push_back("Another long string");
	lst3.push_front("Something weird");
	lst3.push_back("Another weird thing...");

	printSize(lst);
	printSize(lst2);
	printSize(lst3);

	lst.pop_back();
	lst2.pop_front();
	lst3.pop_front();
	lst3.pop_back();

	printSize(lst);
	printSize(lst2);
	printSize(lst3);

	return (0);
}

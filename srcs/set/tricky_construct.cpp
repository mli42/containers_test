#include "common.hpp"
#include <list>

#define T1 std::string

int		main(void)
{
	std::list<T1> lst;
	std::list<T1>::iterator itlst;

	lst.push_back("lol");
	lst.push_back("mdr");
	lst.push_back("funny");
	lst.push_back("bunny");
	lst.push_back("fizz");
	lst.push_back("this key is already inside");
	lst.push_back("fuzzy");
	lst.push_back("buzz");
	lst.push_back("inside too");

	std::cout << "List contains: " << lst.size() << " elements." << std::endl;
	for (itlst = lst.begin(); itlst != lst.end(); ++itlst)
		printPair(itlst);
	std::cout << "---------------------------------------------" << std::endl;

	TESTED_NAMESPACE::set<T1> st(lst.begin(), lst.end());
	lst.clear();

	printSize(st);

	return (0);
}

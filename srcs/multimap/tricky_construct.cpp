#include "common.hpp"
#include <list>

#define T1 int
#define T2 std::string
typedef TESTED_NAMESPACE::multimap<T1, T2>::value_type T3;

int		main(void)
{
	std::list<T3> lst;
	std::list<T3>::iterator itlst;

	lst.push_back(T3(42, "lol"));
	lst.push_back(T3(50, "mdr"));
	lst.push_back(T3(35, "funny"));
	lst.push_back(T3(45, "bunny"));
	lst.push_back(T3(21, "fizz"));
	lst.push_back(T3(35, "this key is already inside"));
	lst.push_back(T3(55, "fuzzy"));
	lst.push_back(T3(38, "buzz"));
	lst.push_back(T3(55, "inside too"));

	std::cout << "List contains: " << lst.size() << " elements." << std::endl;
	for (itlst = lst.begin(); itlst != lst.end(); ++itlst)
		printPair(itlst);
	std::cout << "---------------------------------------------" << std::endl;

	TESTED_NAMESPACE::multimap<T1, T2> mp(lst.begin(), lst.end());
	lst.clear();

	printSize(mp);

	return (0);
}

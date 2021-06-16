#include "common.hpp"
#include <list>

#define T1 char

int main (void)
{
	std::list<T1> lst;

	unsigned int lst_size = 7;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back('a' + i);
	TESTED_NAMESPACE::multiset<T1> foo(lst.begin(), lst.end());

	lst.clear(); lst_size = 4;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back('z' - i);
	TESTED_NAMESPACE::multiset<T1> bar(lst.begin(), lst.end());

	TESTED_NAMESPACE::multiset<T1>::const_iterator it_foo = foo.begin();
	TESTED_NAMESPACE::multiset<T1>::const_iterator it_bar = bar.begin();

	std::cout << "BEFORE SWAP" << std::endl;

	std::cout << "foo contains:" << std::endl;
	printSize(foo);
	std::cout << "bar contains:" << std::endl;
	printSize(bar);

	foo.swap(bar);

	std::cout << "AFTER SWAP" << std::endl;

	std::cout << "foo contains:" << std::endl;
	printSize(foo);
	std::cout << "bar contains:" << std::endl;
	printSize(bar);

	std::cout << "Iterator validity:" << std::endl;
	std::cout << (it_foo == bar.begin()) << std::endl;
	std::cout << (it_bar == foo.begin()) << std::endl;

	return (0);
}

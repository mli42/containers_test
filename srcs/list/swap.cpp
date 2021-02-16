#include "common.hpp"

#define TESTED_TYPE int

int main ()
{
	TESTED_NAMESPACE::list<TESTED_TYPE> foo(3, 15);
	TESTED_NAMESPACE::list<TESTED_TYPE> bar(5, 42);
	
	TESTED_NAMESPACE::list<TESTED_TYPE>::const_iterator it_foo = foo.begin();
	TESTED_NAMESPACE::list<TESTED_TYPE>::const_iterator it_bar = bar.begin();

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

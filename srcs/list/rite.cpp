#include "common.hpp"

#define TESTED_TYPE int

int		main(void)
{
	const int size = 5;
	TESTED_NAMESPACE::list<TESTED_TYPE> lst(size);
	TESTED_NAMESPACE::list<TESTED_TYPE>::iterator it_ = lst.begin();
	TESTED_NAMESPACE::list<TESTED_TYPE>::reverse_iterator it(it_);

	for (int i = 0; i < size; ++i)
		*it_++ = (i + 1) * 7;
	it_	= lst.begin();
	printSize(lst);

	std::cout << (it_ == it.base()) << std::endl;
	std::cout << (it_ == dec(it, 3).base()) << std::endl;

	std::cout << *it.base() << std::endl;
	std::cout << *inc(it.base(), 1) << std::endl;

	std::cout << "TEST OFFSET" << std::endl;
	--it; // Otherwise prints sentinel node of the circle linked list
	std::cout << *(it) << std::endl;
	std::cout << *(it).base() << std::endl;

	return (0);
}

#include "common.hpp"

#define TESTED_TYPE foo<int>

int		main(void)
{
	const int size = 5;
	TESTED_NAMESPACE::list<TESTED_TYPE> lst(size);
	TESTED_NAMESPACE::list<TESTED_TYPE>::reverse_iterator it(lst.rbegin());
	TESTED_NAMESPACE::list<TESTED_TYPE>::const_reverse_iterator ite(lst.rend());

	for (int i = 1; it != ite; ++i)
		*it++ = (i * 7);
	printSize(lst, 1);

	it = lst.rbegin();
	ite = lst.rbegin();

	std::cout << *(++ite) << std::endl;
	std::cout << *(ite++) << std::endl;
	std::cout << *ite++ << std::endl;
	std::cout << *++ite << std::endl;

	it->m();
	ite->m();

	std::cout << *(++it) << std::endl;
	std::cout << *(it++) << std::endl;
	std::cout << *it++ << std::endl;
	std::cout << *++it << std::endl;

	std::cout << *(--ite) << std::endl;
	std::cout << *(ite--) << std::endl;
	std::cout << *--ite << std::endl;
	std::cout << *ite-- << std::endl;

	(*it).m();
	(*ite).m();

	std::cout << *(--it) << std::endl;
	std::cout << *(it--) << std::endl;
	std::cout << *it-- << std::endl;
	std::cout << *--it << std::endl;

	return (0);
}

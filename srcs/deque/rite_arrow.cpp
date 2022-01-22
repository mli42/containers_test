#include "common.hpp"

#define TESTED_TYPE foo<int>

int		main(void)
{
	const int size = 5;
	TESTED_NAMESPACE::deque<TESTED_TYPE> deq(size);
	TESTED_NAMESPACE::deque<TESTED_TYPE>::reverse_iterator it(deq.rbegin());
	TESTED_NAMESPACE::deque<TESTED_TYPE>::const_reverse_iterator ite(deq.rend());

	for (int i = 1; it != ite; ++i)
		*it++ = (i * 7);
	printSize(deq, 1);

	it = deq.rbegin();
	ite = deq.rbegin();

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

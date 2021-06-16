#include "common.hpp"

#define TESTED_TYPE int

int		main(void)
{
	const int size = 5;
	TESTED_NAMESPACE::deque<TESTED_TYPE> deq(size);
	TESTED_NAMESPACE::deque<TESTED_TYPE>::reverse_iterator it = deq.rbegin();
	TESTED_NAMESPACE::deque<TESTED_TYPE>::const_reverse_iterator ite = deq.rbegin();

	for (int i = 0; i < size; ++i)
		it[i] = (size - i) * 5;

	it = it + 5;
	it = 1 + it;
	it = it - 4;
	std::cout << *(it += 2) << std::endl;
	std::cout << *(it -= 1) << std::endl;

	*(it -= 2) = 42;
	*(it += 2) = 21;

	std::cout << "const_ite +=/-=: " << *(ite += 2) << " | " << *(ite -= 2) << std::endl;

	std::cout << "(it == const_it): " << (ite == it) << std::endl;
	std::cout << "(const_ite - it): " << (ite - it) << std::endl;
	std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

	printSize(deq, true);
	return (0);
}

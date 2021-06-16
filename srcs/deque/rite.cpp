#include "common.hpp"

#define TESTED_TYPE int

int		main(void)
{
	const int size = 5;
	TESTED_NAMESPACE::deque<TESTED_TYPE> deq(size);
	TESTED_NAMESPACE::deque<TESTED_TYPE>::iterator it_ = deq.begin();
	TESTED_NAMESPACE::deque<TESTED_TYPE>::reverse_iterator it(it_);

	for (int i = 0; i < size; ++i)
		deq[i] = (i + 1) * 5;
	printSize(deq);

	std::cout << (it_ == it.base()) << std::endl;
	std::cout << (it_ == (it + 3).base()) << std::endl;

	std::cout << *(it.base() + 1) << std::endl;
	std::cout << *(it - 3) << std::endl;

	std::cout << *(it - 3).base() << std::endl;
	it -= 3;
	std::cout << *it.base() << std::endl;

	std::cout << "TEST OFFSET" << std::endl;
	std::cout << *(it) << std::endl;
	std::cout << *(it).base() << std::endl;
	std::cout << *((it - 0) - 0) << std::endl;
	std::cout << *(it - 0).base() << std::endl;
	std::cout << *(it - 1).base() << std::endl;

	return (0);
}

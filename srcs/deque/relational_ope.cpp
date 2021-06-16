#include "common.hpp"

#define TESTED_TYPE int

template <class T, class Alloc>
void	cmp(const TESTED_NAMESPACE::deque<T, Alloc> &lhs, const TESTED_NAMESPACE::deque<T, Alloc> &rhs)
{
	static int i = 0;

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
	std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
	std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}

int		main(void)
{
	TESTED_NAMESPACE::deque<TESTED_TYPE> deq(4);
	TESTED_NAMESPACE::deque<TESTED_TYPE> deq2(4);

	cmp(deq, deq);  // 0
	cmp(deq, deq2); // 1

	deq2.resize(10);

	cmp(deq, deq2); // 2
	cmp(deq2, deq); // 3

	deq[2] = 42;

	cmp(deq, deq2); // 4
	cmp(deq2, deq); // 5

	swap(deq, deq2);

	cmp(deq, deq2); // 6
	cmp(deq2, deq); // 7

	return (0);
}

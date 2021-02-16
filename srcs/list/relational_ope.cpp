#include "common.hpp"

#define TESTED_TYPE int

template <class T, class Alloc>
void	cmp(const TESTED_NAMESPACE::list<T, Alloc> &lhs, const TESTED_NAMESPACE::list<T, Alloc> &rhs)
{
	static int i = 0;

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
	std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
	std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}

int		main(void)
{
	TESTED_NAMESPACE::list<TESTED_TYPE> lst(4);
	TESTED_NAMESPACE::list<TESTED_TYPE> lst2(4);

	cmp(lst, lst);  // 0
	cmp(lst, lst2); // 1

	lst2.resize(10);

	cmp(lst, lst2); // 2
	cmp(lst2, lst); // 3

	*++(++lst.begin()) = 42;

	cmp(lst, lst2); // 4
	cmp(lst2, lst); // 5

	swap(lst, lst2);

	cmp(lst, lst2); // 6
	cmp(lst2, lst); // 7

	return (0);
}

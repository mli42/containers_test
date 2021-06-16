#include "common.hpp"

#define T1 char
#define T2 int
typedef _pair<const T1, T2> T3;

template <class MAP>
void	cmp(const MAP &lhs, const MAP &rhs)
{
	static int i = 0;

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
	std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
	std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}

int		main(void)
{
	TESTED_NAMESPACE::multimap<T1, T2> mp1;
	TESTED_NAMESPACE::multimap<T1, T2> mp2;

	mp1.insert(TESTED_NAMESPACE::make_pair('a', 2));
	mp1.insert(TESTED_NAMESPACE::make_pair('b', 3));
	mp1.insert(TESTED_NAMESPACE::make_pair('c', 4));
	mp1.insert(TESTED_NAMESPACE::make_pair('d', 5));
	mp2.insert(TESTED_NAMESPACE::make_pair('a', 2));
	mp2.insert(TESTED_NAMESPACE::make_pair('b', 3));
	mp2.insert(TESTED_NAMESPACE::make_pair('c', 4));
	mp2.insert(TESTED_NAMESPACE::make_pair('d', 5));

	cmp(mp1, mp1); // 0
	cmp(mp1, mp2); // 1

	mp2.insert(TESTED_NAMESPACE::make_pair('e', 6));
	mp2.insert(TESTED_NAMESPACE::make_pair('f', 7));
	mp2.insert(TESTED_NAMESPACE::make_pair('h', 8));
	mp2.insert(TESTED_NAMESPACE::make_pair('h', 9));

	cmp(mp1, mp2); // 2
	cmp(mp2, mp1); // 3

	(++(++mp1.begin()))->second = 42;

	cmp(mp1, mp2); // 4
	cmp(mp2, mp1); // 5

	swap(mp1, mp2);

	cmp(mp1, mp2); // 6
	cmp(mp2, mp1); // 7

	return (0);
}

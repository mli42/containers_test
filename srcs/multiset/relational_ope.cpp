#include "common.hpp"

#define T1 char

template <class SET>
void	cst(const SET &lhs, const SET &rhs)
{
	static int i = 0;

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
	std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
	std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}

int		main(void)
{
	TESTED_NAMESPACE::multiset<T1> st1;
	TESTED_NAMESPACE::multiset<T1> st2;

	st1.insert('a');
	st1.insert('b');
	st1.insert('c');
	st1.insert('d');
	st2.insert('a');
	st2.insert('b');
	st2.insert('c');
	st2.insert('d');

	cst(st1, st1); // 0
	cst(st1, st2); // 1

	st2.insert('e');
	st2.insert('f');
	st2.insert('h');
	st2.insert('h');

	cst(st1, st2); // 2
	cst(st2, st1); // 3

	swap(st1, st2);

	cst(st1, st2); // 4
	cst(st2, st1); // 5

	return (0);
}

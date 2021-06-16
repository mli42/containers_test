#include "common.hpp"
#include <list>

#define T1 int

static int iter = 0;

template <typename SET, typename U>
void	ft_insert(SET &st, U param, U param2)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	st.insert(param, param2);
	printSize(st);
}

int		main(void)
{
	std::list<T1> lst;
	std::list<T1>::iterator itlst;

	lst.push_back(42);

	lst.push_back(50);
	lst.push_back(35);

	lst.push_back(45);
	lst.push_back(21);
	lst.push_back(38);
	lst.push_back(55);

	std::cout << "List contains:" << std::endl;
	for (itlst = lst.begin(); itlst != lst.end(); ++itlst)
		printPair(itlst);

	TESTED_NAMESPACE::multiset<T1> st;
	ft_insert(st, lst.begin(), lst.end());

	lst.clear();

	lst.push_back(87);
	lst.push_back(47);
	lst.push_back(35);
	lst.push_back(23);
	lst.push_back(1);
	lst.push_back(100);
	lst.push_back(55);

	std::cout << "List contains:" << std::endl;
	for (itlst = lst.begin(); itlst != lst.end(); ++itlst)
		printPair(itlst);

	ft_insert(st, lst.begin(), lst.begin());
	ft_insert(st, lst.begin(), lst.end());

	return (0);
}

#include "common.hpp"
#include <list>

#define T1 foo<int>

int		main(void)
{
	std::list<T1> lst;
	unsigned int lst_size = 5;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(2.5 + i);

	TESTED_NAMESPACE::multiset<T1> st(lst.begin(), lst.end());
	TESTED_NAMESPACE::multiset<T1>::iterator it(st.begin());
	TESTED_NAMESPACE::multiset<T1>::const_iterator ite(st.begin());
	printSize(st);

	printPair(++ite);
	printPair(ite++);
	printPair(ite++);
	printPair(++ite);

	it->m();
	ite->m();

	printPair(++it);
	printPair(it++);
	printPair(it++);
	printPair(++it);

	printPair(--ite);
	printPair(ite--);
	printPair(--ite);
	printPair(ite--);

	(*it).m();
	(*ite).m();

	printPair(--it);
	printPair(it--);
	printPair(it--);
	printPair(--it);

	return (0);
}

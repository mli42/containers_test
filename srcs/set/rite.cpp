#include "common.hpp"
#include <list>

#define T1 int

int		main(void)
{
	std::list<T1> lst;
	unsigned int lst_size = 5;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back((i + 1) * 7);

	TESTED_NAMESPACE::set<T1> st(lst.begin(), lst.end());
	TESTED_NAMESPACE::set<T1>::iterator it_ = st.begin();
	TESTED_NAMESPACE::set<T1>::reverse_iterator it(it_), ite;
	printSize(st);

	std::cout << (it_ == it.base()) << std::endl;
	std::cout << (it_ == dec(it, 3).base()) << std::endl;

	printPair(it.base());
	printPair(inc(it.base(), 1));

	std::cout << "TEST OFFSET" << std::endl;
	--it;
	printPair(it);
	printPair(it.base());

	it = st.rbegin(); ite = st.rend();
	while (it != ite)
		std::cout << "[rev] " << printPair(it++, false) << std::endl;
	// printReverse(st); <-- this causes a strange bug on the macos std lib ?

	return (0);
}

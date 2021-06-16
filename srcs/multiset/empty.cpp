#include "common.hpp"
#include <list>

#define T1 char

template <class T>
void	is_empty(T const &st)
{
	std::cout << "is_empty: " << st.empty() << std::endl;
}

int		main(void)
{
	std::list<T1> lst;
	unsigned int lst_size = 7;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back('a' + i);

	TESTED_NAMESPACE::multiset<T1> st(lst.begin(), lst.end()), st2;
	TESTED_NAMESPACE::multiset<T1>::iterator it;

	lst.clear();
	is_empty(st);
	printSize(st);

	is_empty(st2);
	st2 = st;
	is_empty(st2);

	it = st.begin();
	for (unsigned long int i = 3; i < 6; ++i)
		st.insert(i * 7);

	printSize(st);
	printSize(st2);

	st2.clear();
	is_empty(st2);
	printSize(st2);
	return (0);
}

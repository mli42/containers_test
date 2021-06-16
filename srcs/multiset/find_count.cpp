#include "common.hpp"

#define T1 int

TESTED_NAMESPACE::multiset<T1> st;
TESTED_NAMESPACE::multiset<T1>::iterator it = st.end();

void	ft_find(T1 const &k)
{
	TESTED_NAMESPACE::multiset<T1>::iterator ret = st.find(k);

	if (ret != it)
		printPair(ret);
	else
		std::cout << "multiset::find(" << k << ") returned end()" << std::endl;
}

void	ft_count(T1 const &k)
{
	std::cout << "multiset::count(" << k << ")\treturned [" << st.count(k) << "]" << std::endl;
}

int		main(void)
{
	st.insert(42);
	st.insert(25);
	st.insert(80);
	st.insert(12);
	st.insert(27);
	st.insert(90);
	printSize(st);

	std::cout << "\t-- FIND --" << std::endl;
	ft_find(12);
	ft_find(3);
	ft_find(35);
	ft_find(90);
	ft_find(100);

	std::cout << "\t-- COUNT --" << std::endl;
	ft_count(-3);
	ft_count(12);
	ft_count(3);
	ft_count(35);
	ft_count(90);
	ft_count(100);

	st.erase(st.find(27));

	printSize(st);

	TESTED_NAMESPACE::multiset<T1> const c_multiset(st.begin(), st.end());
	std::cout << "const multiset.find(" << 42 << ")->second: [" << *(c_multiset.find(42)) << "]" << std::endl;
	std::cout << "const multiset.count(" << 80 << "): [" << c_multiset.count(80) << "]" << std::endl;
	return (0);
}

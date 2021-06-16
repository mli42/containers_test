#include "common.hpp"

#define T1 int

TESTED_NAMESPACE::set<T1> st;
TESTED_NAMESPACE::set<T1>::iterator it = st.end();

void	ft_find(T1 const &k)
{
	TESTED_NAMESPACE::set<T1>::iterator ret = st.find(k);

	if (ret != it)
		printPair(ret);
	else
		std::cout << "set::find(" << k << ") returned end()" << std::endl;
}

void	ft_count(T1 const &k)
{
	std::cout << "set::count(" << k << ")\treturned [" << st.count(k) << "]" << std::endl;
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

	TESTED_NAMESPACE::set<T1> const c_set(st.begin(), st.end());
	std::cout << "const set.find(" << 42 << ")->second: [" << *(c_set.find(42)) << "]" << std::endl;
	std::cout << "const set.count(" << 80 << "): [" << c_set.count(80) << "]" << std::endl;
	return (0);
}

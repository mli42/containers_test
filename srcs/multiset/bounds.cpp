#include "common.hpp"
#include <list>

#define T1 int
typedef TESTED_NAMESPACE::multiset<T1>::iterator ft_iterator;
typedef TESTED_NAMESPACE::multiset<T1>::const_iterator ft_const_iterator;

static int iter = 0;

template <typename SET>
void	ft_bound(SET &st, const T1 &param)
{
	ft_iterator ite = st.end(), it[2];
	_pair<ft_iterator, ft_iterator> ft_range;

	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	std::cout << "with key [" << param << "]:" << std::endl;
	it[0] = st.lower_bound(param); it[1] = st.upper_bound(param);
	ft_range = st.equal_range(param);
	std::cout << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], false)) << std::endl;
	std::cout << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], false)) << std::endl;
	std::cout << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
}

template <typename SET>
void	ft_const_bound(const SET &st, const T1 &param)
{
	ft_const_iterator ite = st.end(), it[2];
	_pair<ft_const_iterator, ft_const_iterator> ft_range;

	std::cout << "\t-- [" << iter++ << "] (const) --" << std::endl;
	std::cout << "with key [" << param << "]:" << std::endl;
	it[0] = st.lower_bound(param); it[1] = st.upper_bound(param);
	ft_range = st.equal_range(param);
	std::cout << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], false)) << std::endl;
	std::cout << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], false)) << std::endl;
	std::cout << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
}

int		main(void)
{
	std::list<T1> lst;
	unsigned int lst_size = 10;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back((i + 1) * 3);
	TESTED_NAMESPACE::multiset<T1> st(lst.begin(), lst.end());
	printSize(st);

	ft_const_bound(st, -10);
	ft_const_bound(st, 1);
	ft_const_bound(st, 5);
	ft_const_bound(st, 10);
	ft_const_bound(st, 50);

	printSize(st);

	ft_bound(st, 5);
	ft_bound(st, 7);

	printSize(st);
	return (0);
}

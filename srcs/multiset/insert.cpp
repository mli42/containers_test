#include "common.hpp"

#define T1 std::string
typedef TESTED_NAMESPACE::multiset<T1>::iterator iterator;

static int iter = 0;

template <typename SET, typename U>
void	ft_insert(SET &st, U param)
{
	_pair<iterator, bool> tmp;

	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	tmp = st.insert(param);
	std::cout << "insert return: " << printPair(tmp.first);
	std::cout << "Created new node: " << tmp.second << std::endl;
	printSize(st);
}

template <typename SET, typename U, typename V>
void	ft_insert(SET &st, U param, V param2)
{
	iterator tst;

	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	tst = st.insert(param, param2);
	std::cout << "insert return: " << printPair(tst);
	printSize(st);
}

int		main(void)
{
	TESTED_NAMESPACE::multiset<T1> st, st2;

	ft_insert(st, "lol");
	ft_insert(st, "mdr");

	ft_insert(st, "mdr");
	ft_insert(st, "funny");

	ft_insert(st, "bunny");
	ft_insert(st, "fizz");
	ft_insert(st, "buzz");

	ft_insert(st, st.begin(), "fuzzy");

	ft_insert(st2, st2.begin(), "beauty");
	ft_insert(st2, st2.end(), "Hello");
	ft_insert(st2, st2.end(), "World");

	return (0);
}

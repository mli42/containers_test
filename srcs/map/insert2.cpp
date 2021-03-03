#include "common.hpp"
#include <list>

#define T1 int
#define T2 std::string
typedef TESTED_NAMESPACE::map<T1, T2>::value_type T3;

static int iter = 0;

template <typename MAP, typename U>
void	ft_insert(MAP &mp, U param, U param2)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	mp.insert(param, param2);
	printSize(mp);
}

int		main(void)
{
	std::list<T3> lst;
	std::list<T3>::iterator itlst;

	lst.push_back(T3(42, "lol"));

	lst.push_back(T3(50, "mdr"));
	lst.push_back(T3(35, "funny"));

	lst.push_back(T3(45, "bunny"));
	lst.push_back(T3(21, "fizz"));
	lst.push_back(T3(38, "buzz"));
	lst.push_back(T3(55, "fuzzy"));

	std::cout << "List contains:" << std::endl;
	for (itlst = lst.begin(); itlst != lst.end(); ++itlst)
		printPair(itlst);

	TESTED_NAMESPACE::map<T1, T2> mp;
	ft_insert(mp, lst.begin(), lst.end());

	lst.clear();

	lst.push_back(T3(87, "hey"));
	lst.push_back(T3(47, "eqweqweq"));
	lst.push_back(T3(35, "this key is already inside"));
	lst.push_back(T3(23, "but not that one"));
	lst.push_back(T3(1, "surprising isnt it?"));
	lst.push_back(T3(100, "is it enough??"));
	lst.push_back(T3(55, "inside map too"));

	std::cout << "List contains:" << std::endl;
	for (itlst = lst.begin(); itlst != lst.end(); ++itlst)
		printPair(itlst);

	ft_insert(mp, lst.begin(), lst.begin());
	ft_insert(mp, lst.begin(), lst.end());

	return (0);
}

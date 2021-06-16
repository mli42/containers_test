#include "common.hpp"

#define T1 int
#define T2 std::string

TESTED_NAMESPACE::multimap<T1, T2> mp;
TESTED_NAMESPACE::multimap<T1, T2>::iterator it = mp.end();

void	ft_find(T1 const &k)
{
	TESTED_NAMESPACE::multimap<T1, T2>::iterator ret = mp.find(k);

	if (ret != it)
		printPair(ret);
	else
		std::cout << "multimap::find(" << k << ") returned end()" << std::endl;
}

void	ft_count(T1 const &k)
{
	std::cout << "multimap::count(" << k << ")\treturned [" << mp.count(k) << "]" << std::endl;
}

int		main(void)
{
	mp.insert(TESTED_NAMESPACE::make_pair(42, "fgzgxfn"));
	mp.insert(TESTED_NAMESPACE::make_pair(25, "funny"));
	mp.insert(TESTED_NAMESPACE::make_pair(80, "hey"));
	mp.insert(TESTED_NAMESPACE::make_pair(12, "no"));
	mp.insert(TESTED_NAMESPACE::make_pair(27, "bee"));
	mp.insert(TESTED_NAMESPACE::make_pair(90, "8"));
	printSize(mp);

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

	mp.find(27)->second = "newly inserted multimapped_value";

	printSize(mp);

	TESTED_NAMESPACE::multimap<T1, T2> const c_multimap(mp.begin(), mp.end());
	std::cout << "const multimap.find(" << 42 << ")->second: [" << c_multimap.find(42)->second << "]" << std::endl;
	std::cout << "const multimap.count(" << 80 << "): [" << c_multimap.count(80) << "]" << std::endl;
	return (0);
}

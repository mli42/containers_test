#include "common.hpp"
#include <list>

#define T1 int
#define T2 std::string
typedef _pair<const T1, T2> T3;

static int iter = 0;

template <typename MAP, typename U>
void	ft_erase(MAP &mp, U param)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	mp.erase(param);
	printSize(mp);
}

template <typename MAP, typename U, typename V>
void	ft_erase(MAP &mp, U param, V param2)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	mp.erase(param, param2);
	printSize(mp);
}

int		main(void)
{
	std::list<T3> lst;
	unsigned int lst_size = 10;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3(i, std::string((lst_size - i), i + 65)));
	TESTED_NAMESPACE::multimap<T1, T2> mp(lst.begin(), lst.end());
	printSize(mp);

	ft_erase(mp, ++mp.begin());

	ft_erase(mp, mp.begin());
	ft_erase(mp, --mp.end());

	ft_erase(mp, mp.begin(), ++(++(++mp.begin())));
	ft_erase(mp, --(--(--mp.end())), --mp.end());

	mp.insert(TESTED_NAMESPACE::make_pair(10, "Hello"));
	mp.insert(TESTED_NAMESPACE::make_pair(11, "Hi there"));
	printSize(mp);
	ft_erase(mp, --(--(--mp.end())), mp.end());

	mp.insert(TESTED_NAMESPACE::make_pair(12, "ONE"));
	mp.insert(TESTED_NAMESPACE::make_pair(13, "TWO"));
	mp.insert(TESTED_NAMESPACE::make_pair(14, "THREE"));
	mp.insert(TESTED_NAMESPACE::make_pair(15, "FOUR"));
	printSize(mp);
	ft_erase(mp, mp.begin(), mp.end());

	return (0);
}

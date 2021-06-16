#include "common.hpp"

#define T1 int
#define T2 std::string

struct ft_more {
	bool	operator()(const T1 &first, const T1 &second) const {
		return (first > second);
	}
};

typedef TESTED_NAMESPACE::multimap<T1, T2, ft_more> ft_mp;
typedef TESTED_NAMESPACE::multimap<T1, T2, ft_more>::iterator ft_mp_it;

int		main(void)
{
	ft_mp mp;

	mp.insert(TESTED_NAMESPACE::make_pair(42, "fgzgxfn"));
	mp.insert(TESTED_NAMESPACE::make_pair(25, "funny"));
	mp.insert(TESTED_NAMESPACE::make_pair(80, "hey"));
	mp.insert(TESTED_NAMESPACE::make_pair(12, "no"));
	mp.insert(TESTED_NAMESPACE::make_pair(27, "bee"));
	mp.insert(TESTED_NAMESPACE::make_pair(90, "8"));
	printSize(mp);

	return (0);
}

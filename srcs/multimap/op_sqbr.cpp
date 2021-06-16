#include "common.hpp"

#define T1 int
#define T2 int

int		main(void)
{
	TESTED_NAMESPACE::multimap<T1, T2> const mp;

	mp[4] = 15; // <-- error expected

	return (0);
}

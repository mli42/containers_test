#include "common.hpp"

#define T1 int
#define T2 int

int		main(void)
{
	TESTED_NAMESPACE::multiset<T1> const st;

	st[4] = 15; // <-- error expected

	return (0);
}

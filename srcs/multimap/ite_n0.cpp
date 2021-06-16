#include "common.hpp"

#define T1 int
#define T2 int

int		main(void)
{
	TESTED_NAMESPACE::multimap<T1, T2> mp;

	TESTED_NAMESPACE::multimap<T1, T2>::const_iterator ite = mp.begin();
	*ite = 42; // < -- error
	return (0);
}

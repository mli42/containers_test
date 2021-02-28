#include "common.hpp"

#define T1 int
#define T2 int

int		main(void)
{
	TESTED_NAMESPACE::map<T1, T2> mp;
	mp[1] = 2;

	TESTED_NAMESPACE::map<T1, T2>::const_iterator ite = mp.begin();
	*ite = 42; // < -- error
	return (0);
}

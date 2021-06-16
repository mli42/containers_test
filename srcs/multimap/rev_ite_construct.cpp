#include "common.hpp"

#define T1 int
#define T2 int

int		main(void)
{
	TESTED_NAMESPACE::multimap<T1, T2> mp;
	TESTED_NAMESPACE::multimap<T1, T2>::iterator it = mp.begin();
	TESTED_NAMESPACE::multimap<T1, T2>::const_iterator cit = mp.begin();

	TESTED_NAMESPACE::multimap<T1, T2>::reverse_iterator rit(it);

	TESTED_NAMESPACE::multimap<T1, T2>::const_reverse_iterator crit(rit);
	TESTED_NAMESPACE::multimap<T1, T2>::const_reverse_iterator crit_(it);
	TESTED_NAMESPACE::multimap<T1, T2>::const_reverse_iterator crit_2(cit);

	/* error expected
	TESTED_NAMESPACE::multimap<T1, T2>::reverse_iterator rit_(crit);
	TESTED_NAMESPACE::multimap<T1, T2>::reverse_iterator rit2(cit);
	TESTED_NAMESPACE::multimap<T1, T2>::iterator it2(rit);
	TESTED_NAMESPACE::multimap<T1, T2>::const_iterator cit2(crit);
	*/

	std::cout << "OK" << std::endl;
	return (0);
}

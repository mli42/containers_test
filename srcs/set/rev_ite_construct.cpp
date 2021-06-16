#include "common.hpp"

#define T1 int

int		main(void)
{
	TESTED_NAMESPACE::set<T1> st;
	TESTED_NAMESPACE::set<T1>::iterator it = st.begin();
	TESTED_NAMESPACE::set<T1>::const_iterator cit = st.begin();

	TESTED_NAMESPACE::set<T1>::reverse_iterator rit(it);

	TESTED_NAMESPACE::set<T1>::const_reverse_iterator crit(rit);
	TESTED_NAMESPACE::set<T1>::const_reverse_iterator crit_(it);
	TESTED_NAMESPACE::set<T1>::const_reverse_iterator crit_2(cit);

	(void)crit;
	(void)crit_;
	(void)crit_2;
	/* error expected
	TESTED_NAMESPACE::set<T1>::reverse_iterator rit_(crit);
	TESTED_NAMESPACE::set<T1>::reverse_iterator rit2(cit);
	TESTED_NAMESPACE::set<T1>::iterator it2(rit);
	TESTED_NAMESPACE::set<T1>::const_iterator cit2(crit);
	*/

	std::cout << "OK" << std::endl;
	return (0);
}

#include "common.hpp"

#define T1 int

int		main(void)
{
	TESTED_NAMESPACE::multiset<T1> const st;
	TESTED_NAMESPACE::multiset<T1>::iterator it = st.begin(); // <-- no error, actually ! multiset allows for const_iterator => iterator conversion

	(void)it;
	return (0);
}

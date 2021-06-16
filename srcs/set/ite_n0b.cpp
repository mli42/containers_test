#include "common.hpp"

#define T1 int

int		main(void)
{
	TESTED_NAMESPACE::set<T1> st;

	TESTED_NAMESPACE::set<T1>::iterator ite = st.begin();
	*ite = 42; // < -- error as well ; T is always const, even with regular iterator
	return (0);
}

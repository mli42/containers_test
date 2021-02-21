#include "common.hpp"

#define TESTED_TYPE int

int		main(void)
{
	TESTED_NAMESPACE::list<TESTED_TYPE> lst(2);
	TESTED_NAMESPACE::list<TESTED_TYPE>::const_iterator ite = lst.begin();

	*ite = 42; // < -- error
	return (0);
}

#include "common.hpp"

#define TESTED_TYPE int

int		main(void)
{
	TESTED_NAMESPACE::list<TESTED_TYPE> const lst(5);
	TESTED_NAMESPACE::list<TESTED_TYPE>::iterator it = lst.begin(); // <-- error expected

	(void)it;
	return (0);
}

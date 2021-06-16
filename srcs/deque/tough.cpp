#include "common.hpp"

#define TESTED_TYPE int

int		main(void)
{
	TESTED_TYPE x;

	TESTED_NAMESPACE::deque<TESTED_TYPE>::iterator it(&x);

	(void)it;
	return (0);
}

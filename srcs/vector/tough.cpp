#include "common.hpp"

#define TESTED_TYPE int

int		main(void)
{
	TESTED_TYPE x;

	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it(&x);

	(void)it;
	return (0);
}

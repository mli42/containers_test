#include "vector.hpp"
#include <vector>

#ifndef TESTED_NAMESPACE
# define TESTED_NAMESPACE ft
#endif

#define TESTED_TYPE int

int		main(void)
{
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(5);
	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin();
	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator ite = vct.end();
	TESTED_NAMESPACE::vector<TESTED_TYPE> vect(ite, it); // <-- error expected (abort)

	(void)vect;
	return (0);
}

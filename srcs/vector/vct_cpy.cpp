#include "common.hpp"

#define TESTED_TYPE int

int		main(void)
{
	const int size = 5;
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(size);
	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin();
	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator ite = vct.end();

	std::cout << (ite - it) << std::endl;
	for (; it != ite; ++it)
		*it = (ite - it);

	TESTED_NAMESPACE::vector<TESTED_TYPE> vect(vct.begin(), ite);

	printSize(vct, true);
	printSize(vect, true);
	return (0);
}

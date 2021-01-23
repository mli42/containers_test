#include "common.hpp"

#define TESTED_TYPE int

int		main(void)
{
	const int size = 20;
	//TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator ite = vct.begin();
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(size, 20);
	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin();

	for (int i = 5; i < size; ++i)
		it[i] = i;

	printSize(vct, true);
	return (0);
}

#include "common.hpp"

#define TESTED_TYPE int

int		main(void)
{
	const int size = 5;
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(size);
	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it_;
	TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it(it_);
	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator ite(it_);

	for (int i = 0; i < size; ++i)
		vct[i] = i;

	it = vct.rbegin();

	for (int i = 0; i < size; ++i)
	{
		std::cout << *it << std::endl;
		*it += 40;
		++it;
	}
	it = vct.rbegin();

	for (int i = 0; i < size; ++i)
	{
		std::cout << *it++ << std::endl;
	}

	ite = it;
	
	ite = 3 + it;

	return (0);
}

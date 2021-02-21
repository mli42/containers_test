#include "common.hpp"

int		main(void)
{
	TESTED_NAMESPACE::list<int>::iterator it;
	TESTED_NAMESPACE::list<float>::const_iterator ite;

	std::cout << (it != ite) << std::endl;
	return (0);
}

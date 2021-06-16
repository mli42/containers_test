#include "common.hpp"

int		main(void)
{
	TESTED_NAMESPACE::set<int>::iterator it;
	TESTED_NAMESPACE::set<float>::const_iterator ite;

	std::cout << (it != ite) << std::endl; // <-- error expected
	return (0);
}

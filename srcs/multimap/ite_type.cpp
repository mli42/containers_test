#include "common.hpp"

int		main(void)
{
	TESTED_NAMESPACE::multimap<char, int>::iterator it;
	TESTED_NAMESPACE::multimap<char, float>::const_iterator ite;

	std::cout << (it != ite) << std::endl; // <-- error expected
	return (0);
}

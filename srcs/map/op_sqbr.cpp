#include "common.hpp"

#define T1 char
#define T2 foo<std::string>

int		main(void)
{
	TESTED_NAMESPACE::map<T1, T2> mp;

	mp['a'] = "an element";
	mp['b'] = "another element";
	mp['c'] = mp['b'];
	mp['b'] = "old element";

	printSize(mp);

	std::cout << "insert a new element via operator[]: " << mp['d'] << std::endl;

	printSize(mp);
	return (0);
}

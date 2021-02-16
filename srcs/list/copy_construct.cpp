#include "common.hpp"

#define TESTED_TYPE int

int		main(void)
{
	const int size = 5;
	TESTED_NAMESPACE::list<TESTED_TYPE> lst(size);
	TESTED_NAMESPACE::list<TESTED_TYPE>::iterator it = lst.begin();
	TESTED_NAMESPACE::list<TESTED_TYPE>::iterator ite = lst.end();

	for (int i = 0; it != ite; ++it)
		*it = ++i;

	it = lst.begin();
	TESTED_NAMESPACE::list<TESTED_TYPE> lst_cpy(it, ite);

	for (int i = 0; it != ite; ++it)
		*it = ++i * 5;

	printSize(lst);
	printSize(lst_cpy);
	return (0);
}

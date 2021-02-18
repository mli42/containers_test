#include "common.hpp"

#define TESTED_TYPE int

int		main(void)
{
	TESTED_NAMESPACE::list<TESTED_TYPE> lst(10);
	TESTED_NAMESPACE::list<TESTED_TYPE> lst2;

	TESTED_NAMESPACE::list<TESTED_TYPE>::iterator it = lst.begin();

	for (unsigned long int i = 0; i < lst.size(); ++i)
		*it++ = (lst.size() - i) * 3;
	printSize(lst);

	lst2.insert(lst2.end(), 42);
	lst2.insert(lst2.begin(), 2, 21);
	printSize(lst2);

	lst2.insert(--(--lst2.end()), 42);
	printSize(lst2);

	lst2.insert(lst2.end(), 2, 84);
	printSize(lst2);

	lst2.resize(4);
	printSize(lst2);

	lst2.insert(++(++lst2.begin()), lst.begin(), lst.end());
	lst.clear();

	printSize(lst2);
	printSize(lst);
	return (0);
}

#include "common.hpp"

#define TESTED_TYPE int

int		main(void)
{
	TESTED_NAMESPACE::list<TESTED_TYPE> lst(5), lst2(1, 42), lst3;
	TESTED_NAMESPACE::list<TESTED_TYPE>::iterator it = lst.begin();

	for (unsigned long int i = 0; i < lst.size();)
		*it++ = (++i * 3);
	printSize(lst);
	printSize(lst2);
	printSize(lst3);

	lst.reverse();
	lst2.reverse();
	lst3.reverse();

	printSize(lst);
	printSize(lst2);
	printSize(lst3);
	std::cout << "################# printReverse(): #############" << std::endl;
	printReverse(lst);
	printReverse(lst2);
	printReverse(lst3);
	return (0);
}

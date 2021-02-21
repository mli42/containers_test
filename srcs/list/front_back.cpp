#include "common.hpp"

#define TESTED_TYPE int

int		main(void)
{
	TESTED_NAMESPACE::list<TESTED_TYPE> lst(7);
	TESTED_NAMESPACE::list<TESTED_TYPE>::iterator it = lst.begin();

	for (unsigned long int i = 0; i < lst.size(); ++i)
		*it++ = (lst.size() - i) * 3;
	printSize(lst);

	TESTED_NAMESPACE::list<TESTED_TYPE> const lst_c(lst);

	std::cout << "front(): " << lst.front() << " " << lst_c.front() << std::endl;
	std::cout << "back(): " << lst.back() << " " <<  lst_c.back() << std::endl;

	lst.front() = 42;
	lst.back() = 404;
	printSize(lst);
	return (0);
}

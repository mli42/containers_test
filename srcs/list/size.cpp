#include "common.hpp"

#define TESTED_TYPE int

void	is_empty(TESTED_NAMESPACE::list<TESTED_TYPE> const &lst)
{
	std::cout << "is_empty: " << lst.empty() << std::endl;
}

int		main(void)
{
	TESTED_NAMESPACE::list<TESTED_TYPE> lst(7, 20);
	TESTED_NAMESPACE::list<TESTED_TYPE> lst2;
	TESTED_NAMESPACE::list<TESTED_TYPE>::iterator it = lst.begin();

	for (unsigned long int i = 2; i < lst.size(); ++i)
		*it++ = (lst.size() - i) * 3;
	printSize(lst);

	lst.resize(10, 42);
	printSize(lst);

	is_empty(lst2);
	lst2 = lst;
	is_empty(lst2);

	it = lst.begin();
	lst.resize(8, 84);
	for (unsigned long int i = 3; i < lst.size(); ++i)
		*it++ = (lst.size() - i) * 7;

	printSize(lst);
	printSize(lst2);

	lst2.resize(0);
	is_empty(lst2);
	printSize(lst2);
	return (0);
}

#include "common.hpp"

#define TESTED_TYPE int

int		main(void)
{
	TESTED_NAMESPACE::list<TESTED_TYPE> lst(5);
	TESTED_NAMESPACE::list<TESTED_TYPE>::iterator it = lst.begin(), ite = lst.end();
	for (int i = 0; it != ite; ++it)
		*it = ++i;

	it = lst.begin();
	TESTED_NAMESPACE::list<TESTED_TYPE> lst_range(it, --(--ite));
	for (int i = 0; it != ite; ++it)
		*it = ++i * 5;

	it = lst.begin();
	TESTED_NAMESPACE::list<TESTED_TYPE> lst_copy(lst);
	for (int i = 0; it != ite; ++it)
		*it = ++i * 7;
	lst_copy.push_back(42);
	lst_copy.push_back(21);

	std::cout << "\t-- PART ONE --" << std::endl;
	printSize(lst);
	printSize(lst_range);
	printSize(lst_copy);

	lst = lst_copy;
	lst_copy = lst_range;
	lst_range.clear();

	std::cout << "\t-- PART TWO --" << std::endl;
	printSize(lst);
	printSize(lst_range);
	printSize(lst_copy);
	return (0);
}

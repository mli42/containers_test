#include "common.hpp"

#define TESTED_TYPE int

int		main(void)
{
	TESTED_NAMESPACE::list<TESTED_TYPE> lst(7);
	TESTED_NAMESPACE::list<TESTED_TYPE> lst_two(4);
	TESTED_NAMESPACE::list<TESTED_TYPE> lst_three;
	TESTED_NAMESPACE::list<TESTED_TYPE> lst_four;

	TESTED_NAMESPACE::list<TESTED_TYPE>::iterator it;

	it = lst.begin();
	for (unsigned long int i = 0; i < lst.size(); ++i)
		*it++ = (lst.size() - i) * 3;

	it = lst_two.begin();
	for (unsigned long int i = 0; i < lst_two.size(); ++i)
		*it++ = (lst_two.size() - i) * 5;

	printSize(lst);
	printSize(lst_two);

	lst_three.assign(lst.begin(), lst.end());
	lst.assign(lst_two.begin(), lst_two.end());
	lst_two.assign(2, 42);
	lst_four.assign(4, 21);

	std::cout << "\t### After assign(): ###" << std::endl;

	printSize(lst);
	printSize(lst_two);
	printSize(lst_three);
	printSize(lst_four);

	lst_four.assign(6, 84);
	printSize(lst_four);

	std::cout << "\t### assign() : ###" << std::endl;

	lst.assign(5, 53);

	it = lst_three.begin(); ++it; ++it; ++it;
	lst_two.assign(lst_three.begin(), it);

	printSize(lst);
	printSize(lst_two);

	return (0);
}

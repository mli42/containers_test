#include "common.hpp"

#define TESTED_TYPE int

void	ft_remove(TESTED_NAMESPACE::list<TESTED_TYPE> &lst, TESTED_TYPE val)
{
	lst.remove(val);
	printSize(lst);
}

int		main(void)
{
	TESTED_NAMESPACE::list<TESTED_TYPE> lst(4);
	TESTED_NAMESPACE::list<TESTED_TYPE>::iterator it = lst.begin();

	for (unsigned long int i = 0; i < lst.size(); ++i)
		*it++ = (lst.size() - i) * 3;
	printSize(lst);

	std::cout << "\t-- REMOVE --" << std::endl;

	ft_remove(lst, 9);
	ft_remove(lst, 15);
	ft_remove(lst, 12);
	ft_remove(lst, 3);
	ft_remove(lst, 6);
	return (0);
}

#include "common.hpp"

#define TESTED_TYPE int

bool	ft_even(TESTED_TYPE val)
{
	return !(val % 2);
}

bool	ft_odd(TESTED_TYPE val)
{
	return (val % 2);
}

bool	ft_false(TESTED_TYPE val)
{
	(void)val;
	return false;
}

template <class Pred>
void	ft_remove(TESTED_NAMESPACE::list<TESTED_TYPE> &lst, Pred pred)
{
	lst.remove_if(pred);
	printSize(lst);
}

int		main(void)
{
	TESTED_NAMESPACE::list<TESTED_TYPE> lst(6), lst2, lst3;
	TESTED_NAMESPACE::list<TESTED_TYPE>::iterator it = lst.begin();

	for (unsigned long int i = 0; i < lst.size(); ++i)
		*it++ = i;
	lst2.assign(lst.begin(), --lst.end());
	lst3.assign(++lst.begin(), lst.end());

	printSize(lst);
	printSize(lst2);
	printSize(lst3);

	std::cout << "\t-- REMOVE IF --" << std::endl;

	ft_remove(lst, ft_even);
	ft_remove(lst2, ft_even);
	ft_remove(lst3, ft_even);
	ft_remove(lst3, ft_false);
	ft_remove(lst3, ft_odd);
	return (0);
}

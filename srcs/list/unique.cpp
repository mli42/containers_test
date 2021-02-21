#include "common.hpp"
#include <cmath>

#define TESTED_TYPE double

bool	ft_true(TESTED_TYPE first, TESTED_TYPE second)
{
	(void)first; (void)second;
	return true;
}

bool	ft_false(TESTED_TYPE first, TESTED_TYPE second)
{
	(void)first; (void)second;
	return false;
}

bool	same_integral_part(TESTED_TYPE first, TESTED_TYPE second)
{
	return (int(first) == int(second));
}

struct is_near {
	bool	operator()(TESTED_TYPE first, TESTED_TYPE second)
	{
		return (fabs(first - second) < 5.0);
	}
};

template <class Pred>
void	ft_unique(TESTED_NAMESPACE::list<TESTED_TYPE> &lst, Pred pred)
{
	lst.unique(pred);
	printSize(lst);
}

void	ft_unique(TESTED_NAMESPACE::list<TESTED_TYPE> &lst)
{
	lst.unique();
	printSize(lst);
}

int		main(void)
{
	TESTED_TYPE init[] = {	 2.72,  3.14, 12.15, 12.77, 12.77,
							15.3 , 72.25, 72.25, 73.0 , 73.35 };
	TESTED_NAMESPACE::list<TESTED_TYPE> lst(init, init + 10);
	printSize(lst);

	std::cout << "\t-- UNIQUE --" << std::endl;

	ft_unique(lst);
	ft_unique(lst, same_integral_part);
	ft_unique(lst, is_near());
	ft_unique(lst, ft_false);
	ft_unique(lst, ft_true);
	return (0);
}

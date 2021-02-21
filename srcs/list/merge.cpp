#include "common.hpp"

#define TESTED_TYPE double

struct t_cmp {
	bool	operator()(const TESTED_TYPE &first, const TESTED_TYPE &second)
	{
		return (int(first) < int(second));
	}
};

template <class Pred>
void	ft_merge(TESTED_NAMESPACE::list<TESTED_TYPE> &lst,
				TESTED_NAMESPACE::list<TESTED_TYPE> &lst2, Pred pred)
{
	lst.merge(lst2, pred);
	printSize(lst);
	printSize(lst2);
}

void	ft_merge(TESTED_NAMESPACE::list<TESTED_TYPE> &lst,
				TESTED_NAMESPACE::list<TESTED_TYPE> &lst2)
{
	lst.merge(lst2);
	printSize(lst);
	printSize(lst2);
}

void	ft_sort(TESTED_NAMESPACE::list<TESTED_TYPE> &lst)
{
	lst.sort();
	printSize(lst);
}

int		main(void)
{
	TESTED_NAMESPACE::list<TESTED_TYPE> first, second;

	first.push_back(3.1);
	first.push_back(2.2);
	first.push_back(2.9);

	second.push_back(3.7);
	second.push_back(7.1);
	second.push_back(1.4);

	ft_sort(first);
	ft_sort(second);

	std::cout << "\t-- MERGE --" << std::endl;

	ft_merge(first, second);

	second.push_back(2.1);

	ft_merge(first, second, t_cmp());

	second.push_back(5.2);
	second.push_back(3.4);

	ft_merge(first, second, t_cmp());

	return (0);
}

#include "common.hpp"

typedef double UNDER_TYPE;
typedef foo<UNDER_TYPE> TESTED_TYPE;

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
	if (&lst != &lst2)
		printSize(lst2);
}

void	ft_merge(TESTED_NAMESPACE::list<TESTED_TYPE> &lst,
				TESTED_NAMESPACE::list<TESTED_TYPE> &lst2)
{
	lst.merge(lst2);
	printSize(lst);
	if (&lst != &lst2)
		printSize(lst2);
}

void	ft_push_back(TESTED_NAMESPACE::list<TESTED_TYPE> &lst, const UNDER_TYPE val)
{
	lst.push_back(val);
	lst.back().switchVerbose();
}

int		main(void)
{
	TESTED_NAMESPACE::list<TESTED_TYPE> first, second;

	ft_push_back(first, 2.2);
	ft_push_back(first, 2.9);
	ft_push_back(first, 3.1);

	ft_push_back(second, 1.4);
	ft_push_back(second, 3.7);
	ft_push_back(second, 7.1);

	std::cout << "\t-- MERGE --" << std::endl;

	ft_merge(first, first);
	ft_merge(first, second);

	ft_push_back(second, 2.1);

	ft_merge(first, second, t_cmp());

	ft_push_back(second, 5.2);
	ft_push_back(second, 3.4);

	second.back() = TESTED_TYPE(3.4); // Reassign the same value but prints something

	ft_merge(first, second, t_cmp());

	return (0);
}

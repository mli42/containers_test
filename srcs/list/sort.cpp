#include "common.hpp"
#include <cctype>

#define TESTED_TYPE std::string

struct case_insensitive {
	bool	operator()(const TESTED_TYPE &first, const TESTED_TYPE &second)
	{
		unsigned int i = 0;

		while ((i < first.length()) && (i < second.length()))
		{
			if (tolower(first[i]) < tolower(second[i]))
				return true;
			else if (tolower(first[i]) > tolower(second[i]))
				return false;
			++i;
		}
		return (first.length() < second.length());
	}
};

template <class Pred>
void	ft_sort(TESTED_NAMESPACE::list<TESTED_TYPE> &lst, Pred pred)
{
	lst.sort(pred);
	printSize(lst);
}

void	ft_sort(TESTED_NAMESPACE::list<TESTED_TYPE> &lst)
{
	lst.sort();
	printSize(lst);
}

int		main(void)
{
	TESTED_TYPE init[] = {"one", "two", "Three", "FOUR", "five"};
	int init_size = (sizeof(init) / sizeof(TESTED_TYPE));
	TESTED_NAMESPACE::list<TESTED_TYPE> lst(init, init + init_size);
	TESTED_NAMESPACE::list<TESTED_TYPE> lst2(1, "Hello World!");
	printSize(lst);

	std::cout << "\t-- SORT --" << std::endl;

	ft_sort(lst);
	ft_sort(lst, case_insensitive());
	ft_sort(lst2);
	lst2.clear();
	ft_sort(lst2);
	return (0);
}

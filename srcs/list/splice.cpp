#include "common.hpp"

#define TESTED_TYPE foo<int>

unsigned int spliced = 0;

template <class Ite, class T_List>
void	ft_splice(T_List &caller, Ite position, T_List &x)
{
	std::cout << "\t-- BEGIN SPLICE [" << spliced++ << "] --" << std::endl;
	caller.splice(position, x);
	printSize(caller);
	if (&caller != &x)
		printSize(x);
}

template <class Ite, class T_List>
void	ft_splice(T_List &caller, Ite position, T_List &x, Ite i)
{
	std::cout << "\t-- BEGIN SPLICE [" << spliced++ << "] --" << std::endl;
	caller.splice(position, x, i);
	printSize(caller);
	if (&caller != &x)
		printSize(x);
}

template <class Ite, class T_List>
void	ft_splice(T_List &caller, Ite position, T_List &x, Ite first, Ite last)
{
	std::cout << "\t-- BEGIN SPLICE [" << spliced++ << "] --" << std::endl;
	caller.splice(position, x, first, last);
	printSize(caller);
	if (&caller != &x)
		printSize(x);
}

int		main(void)
{
	TESTED_NAMESPACE::list<TESTED_TYPE> lst, lst2;
	TESTED_NAMESPACE::list<TESTED_TYPE>::iterator it;

	// Fill lists
	for (int i = 1; i <= 4; ++i)
		lst.push_back(i * 1);
	for (int i = 1; i <= 3; ++i)
		lst2.push_back(i * 10);
	printSize(lst);
	printSize(lst2);

	// Enable verbose for all
	for (it = lst.begin(); it != lst.end(); ++it)
		it->switchVerbose();
	for (it = lst2.begin(); it != lst2.end(); ++it)
		it->switchVerbose();

	*lst.begin() = TESTED_TYPE(42); // Outputs something

	// Start testing splice
	it = ++lst.begin();

	ft_splice(lst, it, lst2);
	ft_splice(lst2, lst2.begin(), lst, it);

	it = ++(++(++lst.begin()));

	ft_splice(lst, lst.begin(), lst, it, lst.end());
	printReverse(lst);

	return (0);
}

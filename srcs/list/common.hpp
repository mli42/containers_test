#include "../base.hpp"
#if !defined(USING_STD)
# include "list.hpp"
#else
# include <list>
#endif /* !defined(STD) */

template <typename T>
void	printSize(TESTED_NAMESPACE::list<T> const &lst, bool print_content = 1)
{
	std::cout << "size: " << lst.size() << std::endl;
	std::cout << "max_size: " << lst.max_size() << std::endl;
	if (print_content)
	{
		typename TESTED_NAMESPACE::list<T>::const_iterator it = lst.begin(), ite = lst.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

template <typename T>
void	printReverse(TESTED_NAMESPACE::list<T> &lst)
{
	typename TESTED_NAMESPACE::list<T>::iterator it = lst.end(), ite = lst.begin();

	std::cout << "printReverse:" << std::endl;
	while (it != ite) {
		it--;
		std::cout << "-> " << *it << std::endl;
	}
	std::cout << "_______________________________________________" << std::endl;
}

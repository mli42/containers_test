#include "../base.hpp"
#if !defined(USING_STD)
# include "deque.hpp"
#else
# include <deque>
#endif /* !defined(STD) */

template <typename T>
void	printSize(TESTED_NAMESPACE::deque<T> const &deq, bool print_content = 1)
{
	std::cout << "size: " << deq.size() << std::endl;
	std::cout << "max_size: " << deq.max_size() << std::endl;
	if (print_content)
	{
		typename TESTED_NAMESPACE::deque<T>::const_iterator it = deq.begin();
		typename TESTED_NAMESPACE::deque<T>::const_iterator ite = deq.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

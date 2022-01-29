#include "../base.hpp"
#if !defined(USING_STD)
# include "queue.hpp"
#else
# include <queue>
#endif /* !defined(STD) */

template <typename T_QUEUE>
void	printSize(T_QUEUE &qu_, bool print_content = 1)
{
	std::cout << "size: " << qu_.size() << std::endl;
	if (print_content)
	{
		std::cout << std::endl << "Content was:" << std::endl;
		while (qu_.size() != 0) {
			std::cout << "- " << qu_.front() << std::endl;
			qu_.pop();
		}
	}
	std::cout << "###############################################" << std::endl;
}

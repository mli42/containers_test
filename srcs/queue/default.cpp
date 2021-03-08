#include "common.hpp"

#define TESTED_TYPE foo<int>
#define t_queue_ TESTED_NAMESPACE::queue
typedef t_queue_<TESTED_TYPE>::container_type container_type;

int		main(void)
{
	TESTED_NAMESPACE::queue<TESTED_TYPE> qu_;

	std::cout << "empty: " << qu_.empty() << std::endl;
	std::cout << "size: " << qu_.size() << std::endl;

	qu_.push(41);
	qu_.push(29);
	qu_.push(10);
	qu_.push(42);
	std::cout << "Added some elements" << std::endl;

	std::cout << "empty: " << qu_.empty() << std::endl;
	printSize(qu_);

	return (0);
}

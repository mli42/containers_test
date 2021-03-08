#include "common.hpp"

#define TESTED_TYPE foo<int>
#define t_queue_ TESTED_NAMESPACE::queue<TESTED_TYPE>
typedef t_queue_::container_type container_type;

int		main(void)
{
	container_type	ctnr;

	ctnr.push_back(21);
	ctnr.push_back(42);
	ctnr.push_back(1337);
	ctnr.push_back(19);
	ctnr.push_back(0);
	ctnr.push_back(183792);

	t_queue_		qu_(ctnr);

	std::cout << "empty: " << qu_.empty() << std::endl;
	std::cout << "size: " << qu_.size() << std::endl;

	qu_.push(1);
	qu_.push(2);
	qu_.push(3);
	qu_.push(4);
	qu_.push(5);
	qu_.push(6);

	std::cout << "Added some elements" << std::endl;

	std::cout << "empty: " << qu_.empty() << std::endl;
	printSize(qu_);

	return (0);
}

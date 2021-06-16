#include "common.hpp"

#define TESTED_TYPE int

int		main(void)
{
	TESTED_NAMESPACE::deque<TESTED_TYPE> deq(7);

	for (unsigned long int i = 0; i < deq.size(); ++i)
	{
		deq[i] = (deq.size() - i) * 3;
		std::cout << "deq.at(): " << deq.at(i) << std::endl;
	}
	printSize(deq, true);

	TESTED_NAMESPACE::deque<TESTED_TYPE> const deq_c(deq);

	std::cout << "front(): " << deq.front() << " " << deq_c.front() << std::endl;
	std::cout << "back(): " << deq.back() << " " <<  deq_c.back() << std::endl;

	deq.at(10) = 42;
	return (0);
}

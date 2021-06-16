#include "common.hpp"

#define TESTED_TYPE int

int		main(void)
{
	TESTED_NAMESPACE::deque<TESTED_TYPE> deq(7);
	TESTED_NAMESPACE::deque<TESTED_TYPE> deq_two(4);
	TESTED_NAMESPACE::deque<TESTED_TYPE> deq_three;
	TESTED_NAMESPACE::deque<TESTED_TYPE> deq_four;

	for (unsigned long int i = 0; i < deq.size(); ++i)
		deq[i] = (deq.size() - i) * 3;
	for (unsigned long int i = 0; i < deq_two.size(); ++i)
		deq_two[i] = (deq_two.size() - i) * 5;
	printSize(deq);
	printSize(deq_two);

	deq_three.assign(deq.begin(), deq.end());
	deq.assign(deq_two.begin(), deq_two.end());
	deq_two.assign(2, 42);
	deq_four.assign(4, 21);

	std::cout << "\t### After assign(): ###" << std::endl;

	printSize(deq);
	printSize(deq_two);
	printSize(deq_three);
	printSize(deq_four);

	deq_four.assign(6, 84);
	printSize(deq_four);

	std::cout << "\t### assign() on enough capacity and low size: ###" << std::endl;

	deq.assign(5, 53);
	deq_two.assign(deq_three.begin(), deq_three.begin() + 3);

	printSize(deq);
	printSize(deq_two);

	return (0);
}

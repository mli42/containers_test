#include "common.hpp"

#define TESTED_TYPE int

int		main(void)
{
	TESTED_NAMESPACE::deque<TESTED_TYPE> deq(5);
	TESTED_NAMESPACE::deque<TESTED_TYPE>::iterator it = deq.begin(), ite = deq.end();

	std::cout << "len: " << (ite - it) << std::endl;
	for (; it != ite; ++it)
		*it = (ite - it);

	it = deq.begin();
	TESTED_NAMESPACE::deque<TESTED_TYPE> deq_range(it, --(--ite));
	for (int i = 0; it != ite; ++it)
		*it = ++i * 5;

	it = deq.begin();
	TESTED_NAMESPACE::deque<TESTED_TYPE> deq_copy(deq);
	for (int i = 0; it != ite; ++it)
		*it = ++i * 7;
	deq_copy.push_back(42);
	deq_copy.push_back(21);

	std::cout << "\t-- PART ONE --" << std::endl;
	printSize(deq);
	printSize(deq_range);
	printSize(deq_copy);

	deq = deq_copy;
	deq_copy = deq_range;
	deq_range.clear();

	std::cout << "\t-- PART TWO --" << std::endl;
	printSize(deq);
	printSize(deq_range);
	printSize(deq_copy);
	return (0);
}


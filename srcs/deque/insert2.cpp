#include "common.hpp"

#define TESTED_TYPE int

int		main(void)
{
	TESTED_NAMESPACE::deque<TESTED_TYPE> deq(5);
	TESTED_NAMESPACE::deque<TESTED_TYPE> deq2;
	const int cut = 3;

	for (unsigned long int i = 0; i < deq.size(); ++i)
		deq[i] = (deq.size() - i) * 7;
	printSize(deq);

	deq2.insert(deq2.begin(), deq.begin(), deq.begin() + cut);
	printSize(deq2);
	deq2.insert(deq2.begin(), deq.begin() + cut, deq.end());
	printSize(deq2);
	deq2.insert(deq2.end(), deq.begin(), deq.begin() + cut);
	printSize(deq2);

	std::cout << "insert return:" << std::endl;

	std::cout << *deq2.insert(deq2.end(), 42) << std::endl;
	std::cout << *deq2.insert(deq2.begin() + 5, 84) << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	printSize(deq2);
	return (0);
}

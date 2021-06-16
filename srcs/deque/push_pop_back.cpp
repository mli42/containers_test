#include "common.hpp"

#define TESTED_TYPE std::string

int		main(void)
{
	TESTED_NAMESPACE::deque<TESTED_TYPE> deq(8);
	TESTED_NAMESPACE::deque<TESTED_TYPE> deq2;
	TESTED_NAMESPACE::deque<TESTED_TYPE>::iterator it = deq.begin();

	for (unsigned long int i = 0; i < deq.size(); ++i)
		it[i] = std::string((deq.size() - i), i + 65);
	printSize(deq, true);

	std::cout << "push_back():\n" << std::endl;

	deq.push_back("One long string");
	deq2.push_back("Another long string");

	printSize(deq);
	printSize(deq2);

	deq.pop_back();
	deq2.pop_back();

	printSize(deq);
	printSize(deq2);

	return (0);
}

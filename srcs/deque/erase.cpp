#include "common.hpp"

#define TESTED_TYPE std::string

void	checkErase(TESTED_NAMESPACE::deque<TESTED_TYPE> const &deq,
					TESTED_NAMESPACE::deque<TESTED_TYPE>::const_iterator const &it)
{
	static int i = 0;
	std::cout << "[" << i++ << "] " << "erase: " << it - deq.begin() << std::endl;
	printSize(deq);
}

int		main(void)
{
	TESTED_NAMESPACE::deque<TESTED_TYPE> deq(10);

	for (unsigned long int i = 0; i < deq.size(); ++i)
		deq[i] = std::string((deq.size() - i), i + 65);
	printSize(deq);

	checkErase(deq, deq.erase(deq.begin() + 2));

	checkErase(deq, deq.erase(deq.begin()));
	checkErase(deq, deq.erase(deq.end() - 1));

	checkErase(deq, deq.erase(deq.begin(), deq.begin() + 3));
	checkErase(deq, deq.erase(deq.end() - 3, deq.end() - 1));

	deq.push_back("Hello");
	deq.push_back("Hi there");
	printSize(deq);
	checkErase(deq, deq.erase(deq.end() - 3, deq.end()));

	deq.push_back("ONE");
	deq.push_back("TWO");
	deq.push_back("THREE");
	deq.push_back("FOUR");
	printSize(deq);
	checkErase(deq, deq.erase(deq.begin(), deq.end()));

	return (0);
}

#include "common.hpp"

#define TESTED_TYPE int

int		main(void)
{
	const int size = 5;
	TESTED_NAMESPACE::deque<TESTED_TYPE> deq(size);
	TESTED_NAMESPACE::deque<TESTED_TYPE>::iterator it = deq.begin();
	TESTED_NAMESPACE::deque<TESTED_TYPE>::const_iterator ite = deq.begin();

	for (int i = 0; i < size; ++i)
		it[i] = i;

	ite[1] = 42; // < -- error

	return (0);
}

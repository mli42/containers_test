#include "common.hpp"

#define TESTED_TYPE int

int		main(void)
{
	const int size = 5;
	TESTED_NAMESPACE::deque<TESTED_TYPE> const deq(size);
	TESTED_NAMESPACE::deque<TESTED_TYPE>::iterator it = deq.begin(); // <-- error expected

	for (int i = 0; i < size; ++i)
		it[i] = i;

	return (0);
}

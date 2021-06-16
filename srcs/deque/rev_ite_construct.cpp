#include "common.hpp"

#define TESTED_TYPE int

int		main(void)
{
	TESTED_NAMESPACE::deque<TESTED_TYPE> deq;
	TESTED_NAMESPACE::deque<TESTED_TYPE>::iterator it = deq.begin();
	TESTED_NAMESPACE::deque<TESTED_TYPE>::const_iterator cit = deq.begin();

	TESTED_NAMESPACE::deque<TESTED_TYPE>::reverse_iterator rit(it);

	TESTED_NAMESPACE::deque<TESTED_TYPE>::const_reverse_iterator crit(rit);
	TESTED_NAMESPACE::deque<TESTED_TYPE>::const_reverse_iterator crit_(it);
	TESTED_NAMESPACE::deque<TESTED_TYPE>::const_reverse_iterator crit_2(cit);

	/* error expected
	TESTED_NAMESPACE::deque<TESTED_TYPE>::reverse_iterator rit_(crit);
	TESTED_NAMESPACE::deque<TESTED_TYPE>::reverse_iterator rit2(cit);
	TESTED_NAMESPACE::deque<TESTED_TYPE>::iterator it2(rit);
	TESTED_NAMESPACE::deque<TESTED_TYPE>::const_iterator cit2(crit);
	*/

	std::cout << "OK" << std::endl;
	return (0);
}

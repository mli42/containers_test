#include "common.hpp"
#include <list>

#define TESTED_TYPE int

int		main(void)
{
	std::list<TESTED_TYPE> lst;
	std::list<TESTED_TYPE>::iterator lst_it;
	for (int i = 1; i < 5; ++i)
		lst.push_back(i * 3);

	TESTED_NAMESPACE::deque<TESTED_TYPE> deq(lst.begin(), lst.end());
	printSize(deq);

	lst_it = lst.begin();
	for (int i = 1; lst_it != lst.end(); ++i)
		*lst_it++ = i * 5;
	deq.assign(lst.begin(), lst.end());
	printSize(deq);

	deq.insert(deq.end(), lst.rbegin(), lst.rend());
	printSize(deq);
	return (0);
}

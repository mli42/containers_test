#include "common.hpp"

/*
single element (1)
	iterator insert (iterator position, const value_type& val);

fill (2)
    void insert (iterator position, size_type n, const value_type& val);

range (3)
	template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last);
*/

#define TESTED_TYPE int

int		main(void)
{
	TESTED_NAMESPACE::deque<TESTED_TYPE> deq(10);
	TESTED_NAMESPACE::deque<TESTED_TYPE> deq2;

	for (unsigned long int i = 0; i < deq.size(); ++i)
		deq[i] = (deq.size() - i) * 3;
	printSize(deq);

	deq2.insert(deq2.end(), 42);
	deq2.insert(deq2.begin(), 2, 21);
	printSize(deq2);

	deq2.insert(deq2.end() - 2, 42);
	printSize(deq2);

	deq2.insert(deq2.end(), 2, 84);
	printSize(deq2);

	deq2.resize(4);
	printSize(deq2);

	deq2.insert(deq2.begin() + 2, deq.begin(), deq.end());
	deq.clear();
	printSize(deq2);

	printSize(deq);
	return (0);
}

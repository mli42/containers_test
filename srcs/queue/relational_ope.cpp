#include "common.hpp"

#define TESTED_TYPE int
#define t_queue_ TESTED_NAMESPACE::queue<TESTED_TYPE>
typedef t_queue_::container_type container_type;

template <class T_STACK>
void	cmp(const T_STACK &lhs, const T_STACK &rhs)
{
	static int i = 0;

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
	std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
	std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}

int		main(void)
{
	container_type	ctnr;

	ctnr.push_back(21);
	ctnr.push_back(42);
	ctnr.push_back(1337);
	ctnr.push_back(19);
	ctnr.push_back(0);
	ctnr.push_back(183792);

	t_queue_	qu_(ctnr);
	t_queue_	qu_2(ctnr);

	cmp(qu_, qu_);  // 0
	cmp(qu_, qu_2); // 1

	qu_2.push(60);
	qu_2.push(61);
	qu_2.push(62);

	cmp(qu_, qu_2); // 2
	cmp(qu_2, qu_); // 3

	qu_.push(42);

	cmp(qu_, qu_2); // 4
	cmp(qu_2, qu_); // 5

	qu_.push(100);

	cmp(qu_, qu_2); // 6
	cmp(qu_2, qu_); // 7
	return (0);
}

#include "common.hpp"

#define TESTED_TYPE foo<int>
#define t_stack_ TESTED_NAMESPACE::stack
typedef t_stack_<TESTED_TYPE>::container_type container_type;

int		main(void)
{
	TESTED_NAMESPACE::stack<TESTED_TYPE> stck;

	std::cout << "empty: " << stck.empty() << std::endl;
	std::cout << "size: " << stck.size() << std::endl;

	stck.push(41);
	stck.push(29);
	stck.push(10);
	stck.push(42);
	std::cout << "Added some elements" << std::endl;

	std::cout << "empty: " << stck.empty() << std::endl;
	printSize(stck);

	return (0);
}

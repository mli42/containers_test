#include "common.hpp"

#define TESTED_TYPE int

int		main(void)
{
	TESTED_NAMESPACE::list<TESTED_TYPE> lst(5);
	TESTED_NAMESPACE::list<TESTED_TYPE> lst2;
	TESTED_NAMESPACE::list<TESTED_TYPE> lst3(5);
	TESTED_NAMESPACE::list<TESTED_TYPE>::iterator it = lst.begin();
	const int cut = 3;

	for (unsigned long int i = 0; i < lst.size(); ++i)
		*it++ = (lst.size() - i) * 7;
	it = lst3.begin();
	for (unsigned long int i = 0; i < lst3.size(); ++i)
		*it++ = i;
	printSize(lst);
	printSize(lst3);

	lst2.insert(lst2.begin(), lst.begin(), inc(lst.begin(), cut));
	printSize(lst2);
	lst2.insert(lst2.begin(), inc(lst.begin(), cut), lst.end());
	printSize(lst2);
	lst2.insert(lst2.end(), lst3.begin(), inc(lst3.begin(), cut));
	printSize(lst2);

	std::cout << "insert return:" << std::endl;

	std::cout << *lst2.insert(lst2.end(), 42) << std::endl;
	std::cout << *lst2.insert(inc(lst2.begin(), 5), 84) << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	printSize(lst2);
	return (0);
}

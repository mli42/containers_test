#include "common.hpp"

#define TESTED_TYPE std::string

void	checkErase(TESTED_NAMESPACE::list<TESTED_TYPE> const &lst,
					TESTED_NAMESPACE::list<TESTED_TYPE>::const_iterator const &it)
{
	static int i = 0;

	int j = 0;
	TESTED_NAMESPACE::list<TESTED_TYPE>::const_iterator ite = lst.end();
	while (it != ite) {
		--ite;
		++j;
	}

	std::cout << "[" << i++ << "] " << "erase: " << j << std::endl;
	printSize(lst);
}

int		main(void)
{
	TESTED_NAMESPACE::list<TESTED_TYPE> lst(10);
	TESTED_NAMESPACE::list<TESTED_TYPE>::iterator it = lst.begin();

	for (unsigned long int i = 0; i < lst.size(); ++i)
		*it++ = std::string((lst.size() - i), i + 65);
	printSize(lst);

	checkErase(lst, lst.erase(++lst.begin()));

	checkErase(lst, lst.erase(lst.begin()));
	checkErase(lst, lst.erase(--lst.end()));

	checkErase(lst, lst.erase(lst.begin(), ++(++(++lst.begin()))));
	checkErase(lst, lst.erase(--(--(--lst.end())), --lst.end()));

	lst.push_back("Hello");
	lst.push_back("Hi there");
	printSize(lst);
	checkErase(lst, lst.erase(--(--(--lst.end())), lst.end()));

	lst.push_back("ONE");
	lst.push_back("TWO");
	lst.push_back("THREE");
	lst.push_back("FOUR");
	printSize(lst);
	checkErase(lst, lst.erase(lst.begin(), lst.end()));

	return (0);
}

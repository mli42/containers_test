#include "../base.hpp"
#if !defined(USING_STD)
# include "set.hpp"
#else
# include <set>
#endif /* !defined(STD) */

#define _pair TESTED_NAMESPACE::pair

template <typename T>
std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	o << "value: " << *iterator;
	if (nl)
		o << std::endl;
	return ("");
}

template <typename T_SET>
void	printSize(T_SET const &st, bool print_content = 1)
{
	std::cout << "size: " << st.size() << std::endl;
	std::cout << "max_size: " << st.max_size() << std::endl;
	if (print_content)
	{
		typename T_SET::const_iterator it = st.begin(), ite = st.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << printPair(it, false) << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

template <typename T1>
void	printReverse(TESTED_NAMESPACE::set<T1> &st)
{
	typename TESTED_NAMESPACE::set<T1>::iterator it = st.end(), ite = st.begin();

	std::cout << "printReverse:" << std::endl;
	while (it-- != ite)
		std::cout << "-> " << printPair(it, false) << std::endl;
	std::cout << "_______________________________________________" << std::endl;
}

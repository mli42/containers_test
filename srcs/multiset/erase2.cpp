#include "common.hpp"
#include <list>

#define T1 int

static int iter = 0;

template <typename SET, typename U>
void	ft_erase(SET &st, U param)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	std::cout << "ret: " << st.erase(param) << std::endl;
	printSize(st);
}

int		main(void)
{
	std::list<T1> lst;
	unsigned int lst_size = 6;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(i);
	TESTED_NAMESPACE::multiset<T1> st(lst.begin(), lst.end());
	printSize(st);

	for (int i = 2; i < 4; ++i)
		ft_erase(st, i);

	ft_erase(st, *st.begin());
	ft_erase(st, *(--st.end()));

	st.insert(-1);
	st.insert(10);
	st.insert(10);
	printSize(st);

	ft_erase(st, 0);
	ft_erase(st, 1);
	printSize(st);

	return (0);
}

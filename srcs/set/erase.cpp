#include "common.hpp"
#include <list>

#define T1 std::string

static int iter = 0;

template <typename SET, typename U>
void	ft_erase(SET &st, U param)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	st.erase(param);
	printSize(st);
}

template <typename SET, typename U, typename V>
void	ft_erase(SET &st, U param, V param2)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	st.erase(param, param2);
	printSize(st);
}

int		main(void)
{
	std::list<T1> lst;
	unsigned int lst_size = 10;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(std::string((lst_size - i), i + 65));
	TESTED_NAMESPACE::set<T1> st(lst.begin(), lst.end());
	printSize(st);

	ft_erase(st, ++st.begin());

	ft_erase(st, st.begin());
	ft_erase(st, --st.end());

	ft_erase(st, st.begin(), ++(++(++st.begin())));
	ft_erase(st, --(--(--st.end())), --st.end());

	st.insert("Hello");
	st.insert("Hi there");
	printSize(st);
	ft_erase(st, --(--(--st.end())), st.end());

	st.insert("ONE");
	st.insert("TWO");
	st.insert("THREE");
	st.insert("FOUR");
	printSize(st);
	ft_erase(st, st.begin(), st.end());

	return (0);
}

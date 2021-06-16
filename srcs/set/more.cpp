#include "common.hpp"

#define T1 int

struct ft_more {
	bool	operator()(const T1 &first, const T1 &second) const {
		return (first > second);
	}
};

typedef TESTED_NAMESPACE::set<T1, ft_more> ft_st;
typedef TESTED_NAMESPACE::set<T1, ft_more>::iterator ft_st_it;

int		main(void)
{
	ft_st st;

	st.insert(42);
	st.insert(25);
	st.insert(80);
	st.insert(12);
	st.insert(12);
	st.insert(27);
	st.insert(90);
	st.insert(25);
	printSize(st);

	return (0);
}

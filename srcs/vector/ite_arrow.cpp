#include "common.hpp"

class foo {
	public:
		foo(void) { };
		~foo(void) { };
		void m(void) { std::cout << "foo::m called" << std::endl; };
		void m(void) const { std::cout << "foo::m const called" << std::endl; };
};

#define TESTED_TYPE foo

int		main(void)
{
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(1);
	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it(vct.begin());
	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator ite(vct.end());

	it->m();
	ite->m();

	(*it).m();
	(*ite).m();

	return (0);
}

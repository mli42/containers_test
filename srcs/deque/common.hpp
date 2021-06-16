#include "deque.hpp"
#include <deque>
#include <iostream>
#include <string>

#ifndef TESTED_NAMESPACE
# define TESTED_NAMESPACE ft
#endif

template <typename T>
void	printSize(TESTED_NAMESPACE::deque<T> const &deq, bool print_content = 1)
{
	std::cout << "size: " << deq.size() << std::endl;
	std::cout << "max_size: " << deq.max_size() << std::endl;
	if (print_content)
	{
		typename TESTED_NAMESPACE::deque<T>::const_iterator it = deq.begin();
		typename TESTED_NAMESPACE::deque<T>::const_iterator ite = deq.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

class foo {
	public:
		foo(void) { };
		~foo(void) { };
		void m(void) { std::cout << "foo::m called [" << this->value << "]" << std::endl; };
		void m(void) const { std::cout << "foo::m const called [" << this->value << "]" << std::endl; };
		foo &operator=(int src) { this->value = src; return *this; };
		int getValue(void) const { return this->value; };
	private:
		int	value;
};

std::ostream	&operator<<(std::ostream &o, foo const &bar) {
	o << bar.getValue();
	return o;
}

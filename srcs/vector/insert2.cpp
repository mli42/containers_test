#include "common.hpp"

#define TESTED_TYPE int

int		main(void)
{
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(5);
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct2;
	const int cut = 3;

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 7;
	printSize(vct);

	vct2.insert(vct2.begin(), vct.begin(), vct.begin() + cut);
	printSize(vct2);
	vct2.insert(vct2.begin(), vct.begin() + cut, vct.end());
	printSize(vct2);
	vct2.insert(vct2.end(), vct.begin(), vct.begin() + cut);
	printSize(vct2);

	std::cout << "insert return:" << std::endl;

	std::cout << *vct2.insert(vct2.end(), 42) << std::endl;
	std::cout << *vct2.insert(vct2.begin() + 5, 84) << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	printSize(vct2);
	return (0);
}

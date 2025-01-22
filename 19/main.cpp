#include "solution.h"
#include <iostream>

int main()
{
	int x = 10;

	Solution solution;

	bool result = solution.isMatch("aaa", "a*a");
	if (result) std::cout << "True" << std::endl;
	else std::cout << "False" << std::endl;
	

	return 0;
}
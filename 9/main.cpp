#include "solution.h"
#include <iostream>

int main()
{
	int x = 10;

	Solution solution;

	bool result = solution.isPalindrome(x);
	if (result) std::cout << "True" << std::endl;
	else std::cout << "False" << std::endl;
	

	return 0;
}
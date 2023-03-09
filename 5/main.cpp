#include <iostream>
#include "solution.h"

int main()
{
	std::string s = "aaaaa";

	std::string result;

	Solution solution;

	result = solution.longestPalindrome(s);

	std::cout << result;

	return 0;
}
#include "solution.h"
#include <iostream>

int main()
{
	std::string s = "abcabcbb";

	Solution solution;

	int result = solution.lengthOfLongestSubstring(s);

	std::cout << result;
	return 0;
}
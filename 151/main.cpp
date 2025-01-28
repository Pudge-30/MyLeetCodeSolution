#include "solution.h"
#include <iostream>

int main()
{
	int x = 10;

	Solution solution;

	std::string s = "  hello world  ";
	std::string t = solution.reverseWords(s);
	std::cout << s << std::endl;
	return 0;
}
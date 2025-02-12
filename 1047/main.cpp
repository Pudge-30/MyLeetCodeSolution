#include "solution.h"
#include <iostream>

int main()
{
	int x = 10;

	Solution solution;

	string s = "abbaca";
	string p = solution.removeDuplicates(s);
	std::cout << p;
	return 0;
}
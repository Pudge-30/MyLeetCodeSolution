#include "solution.h"
#include <iostream>

int main()
{
	string x = "   -123 word";

	Solution solution;

	int y = solution.myAtoi(x);
	std::cout << y << std::endl;
	

	return 0;
}
#include "solution.h"
#include <iostream>

int main()
{
	int x = 10;

	Solution solution;

	if (solution.repeatedSubstringPattern("ababac")) std::cout << "True";
	else std::cout << "False";
	
	return 0;
}
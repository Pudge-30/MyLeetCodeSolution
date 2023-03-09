#include "solution.h"
#include <iostream>

int main()
{
	std::vector<int> num1{1,3}; 
	std::vector<int> num2{2};

	Solution solution;

	int result = solution.findMedianSortedArrays(num1,num2);

	std::cout << result;
	return 0;
}
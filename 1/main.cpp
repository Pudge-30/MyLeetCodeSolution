#include "solution.h"
#include <iostream>

int main()
{
	std::vector<int> input{3,2,4};
	int target = 6;

	Solution solution;

	std::vector resuilt = solution.twoSum(input,target);
	for (auto number :resuilt)
	{
		std::cout << number << " ";
	}

	return 0;
}
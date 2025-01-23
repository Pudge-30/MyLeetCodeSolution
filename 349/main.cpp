#include "solution.h"
#include <iostream>

int main()
{
	int x = 10;

	Solution solution;

	vector<int> nums = { 1,1,1,1,1,1,1,1 };
	int target = 5;
	std::cout << solution.minSubArrayLen(target, nums) ;
	
	return 0;
}
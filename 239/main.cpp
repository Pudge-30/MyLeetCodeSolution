#include "solution.h"
#include <iostream>

int main()
{
	int x = 10;

	std::vector<int> nums = { 1,3,-1,-3,5,3,6,7 };
	Solution solution;
	std::vector<int> max_val = solution.maxSlidingWindow(nums, 3);
	for (auto val : max_val)
	{
		std::cout << val << " ";
	}

	return 0;
}
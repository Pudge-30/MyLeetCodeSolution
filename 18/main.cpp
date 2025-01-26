#include "solution.h"
#include <iostream>

int main()
{
	int x = 10;

	Solution solution;

	std::vector<int> nums = {-3,-1,0,2,4,5};
	int target = 2;
	std::vector<vector<int>> result = solution.fourSum(nums, target);

	for (auto vec : result)

	{
		for (auto num : vec)
		{
			std::cout << num << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}
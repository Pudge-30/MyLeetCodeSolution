#include "solution.h"
#include <iostream>

int main()
{
	int x = 10;

	Solution solution;

	std::vector<int> nums = {-1, 0, 1, 2, -1, -4};

	std::vector<vector<int>> result = solution.threeSum(nums);

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
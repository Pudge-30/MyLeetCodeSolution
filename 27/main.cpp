#include "solution.h"
#include <iostream>

int main()
{
	int x = 10;

	Solution solution;

	vector<int> nums = { 2 };

	int result = solution.removeElement(nums , 3);
	std::cout << result << std::endl;
	for (int i = 0; i < nums.size(); i++)
	{
		std::cout << nums[i] << ' ';
	}
	std::cout << std::endl;
	
	return 0;
}
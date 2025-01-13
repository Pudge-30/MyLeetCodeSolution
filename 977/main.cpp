#include "solution.h"
#include <iostream>

int main()
{
	int x = 10;

	Solution solution;

	vector<int> nums = { -7,-3,2,3,11 };

	vector<int> retval = solution.sortedSquares(nums);
	for (int i = 0; i < retval.size(); i++)
	{
		std::cout << retval[i] << ' ';
	};
	
	return 0;
}
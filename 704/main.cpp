#include "solution.h"
#include <iostream>

int main()
{
	int x = 10;

	Solution solution;

	vector<int> nums = {-1,0,3,5,9,12};

	int result = solution.search(nums , 2);
	std::cout << result << std::endl;
	
	return 0;
}
#include "solution.h"
#include <string>
#include <iostream>

int main()
{
	Solution solution;
	std::string result = solution.convert("PAYPALISHIRING", 4);

	std::cout << result;
}
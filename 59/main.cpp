#include "solution.h"
#include <iostream>

int main()
{
	int x = 10;

	Solution solution;

	vector<vector<int>> matrix;

	int n = 4;
	matrix = solution.generateMatrix(n);


	for (int i = 0; i <n ;i ++)
	{
		for (int j = 0; j < n ; j++)
		{
			std::cout << matrix[i][j] << ' ';
		}
		std::cout << std::endl;
	}
	
	return 0;
}
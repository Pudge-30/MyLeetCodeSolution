#include "solution.h"
#include <iostream>

int main()
{
	int x = 10;

	Solution solution;

	vector<int> inorder{9,3,15,20,7};
	vector<int> postorder{9,15,7,20,3};

	TreeNode* root = solution.buildTree(inorder, postorder);
	
	
	return 0;
}
#include "solution.h"
#include <iostream>

int main()
{
	int x = 10;

	Solution solution;

	TreeNode* node1 = new TreeNode(1);
	TreeNode* node3 = new TreeNode(3);
	TreeNode* node2 = new TreeNode(2,node1,node3);
	TreeNode* node7 = new TreeNode(7);
	TreeNode* node4 = new TreeNode(4,node2, node7);

	solution.insertIntoBST(node4, 5);
	return 0;
}
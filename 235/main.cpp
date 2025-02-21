#include "solution.h"
#include <iostream>

int main()
{
	int x = 10;

	Solution solution;

	TreeNode* node0 = new TreeNode(0);
	TreeNode* node3 = new TreeNode(3);
	TreeNode* node5 = new TreeNode(5);
	TreeNode* node7 = new TreeNode(7);
	TreeNode* node9 = new TreeNode(9);
	TreeNode* node4 = new TreeNode(4, node3, node5);
	TreeNode* node2 = new TreeNode(2, node0, node4);
	TreeNode* node8 = new TreeNode(8, node7, node9);
	TreeNode* node6 = new TreeNode(6, node2, node8);
	
	TreeNode* ancestor = solution.lowestCommonAncestor(node6, node2, node8);

	return 0;
}
#include "solution.h"
#include <iostream>

int main()
{
	ListNode* l1_3 = new ListNode(3);
	ListNode* l1_2 = new ListNode(4, l1_3);
	ListNode* l1_1 = new ListNode{2, l1_2};
	
	ListNode* l2_3 = new ListNode(4);
	ListNode* l2_2 = new ListNode(6, l2_3);
	ListNode* l2_1 = new ListNode{5, l2_2};

	Solution solution;

	ListNode* result = solution.addTwoNumbers(l1_1, l2_1);
	ListNode* currentnode = result;
	while (currentnode != nullptr)
	{
		std::cout << currentnode->val;
		currentnode = currentnode->next;
	}

	return 0;
}
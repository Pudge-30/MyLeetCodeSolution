#include "solution.h"
#include <iostream>

int main()
{
	int x = 10;

	Solution solution;

	ListNode* p6 = new ListNode(6,nullptr);
	ListNode* p5 = new ListNode(5,p6);
	ListNode* p4 = new ListNode(4, p5);
	ListNode* p3 = new ListNode(3, p4);
	ListNode* p2 = new ListNode(6, p3);
	ListNode* p1 = new ListNode(2, p2);
	ListNode* p0 = new ListNode(1, p1);

	ListNode* p = nullptr;

	p = solution.reverseList(p0);
	while (p != nullptr)
	{
		std::cout << p->val << " ";
		p = p->next;
	}
	
	return 0;
}
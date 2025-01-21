#include "solution.h"
#include <iostream>

int main()
{
	int x = 10;

	MyLinkedList* myLinkedList = new MyLinkedList();
	myLinkedList->addAtHead(1); myLinkedList->printval();
	myLinkedList->addAtTail(3); myLinkedList->printval();
	myLinkedList->addAtIndex(1, 2);   myLinkedList->printval(); // 链表变为 1->2->3
	std::cout << myLinkedList->get(1) << std::endl;              // 返回 2
	myLinkedList->deleteAtIndex(1);   myLinkedList->printval(); // 现在，链表变为 1->3
	std::cout << myLinkedList->get(1) << std::endl;   myLinkedList->printval();           // 返回 3
	return 0;
}
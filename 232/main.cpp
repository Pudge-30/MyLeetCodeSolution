#include "solution.h"
#include <iostream>

int main()
{
	int x = 10;

	MyQueue* obj = new MyQueue();
	obj->push(x);
	int param_2 = obj->pop();
	int param_3 = obj->peek();
	bool param_4 = obj->empty();

	return 0;
}
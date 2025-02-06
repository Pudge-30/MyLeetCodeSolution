#include "solution.h"
#include <iostream>

int main()
{
	int x = 10;

	MyStack* obj = new MyStack();
	obj->push(1);
	obj->push(2);

	int param_2 = obj->top();
	int param_3 = obj->pop();
	bool param_4 = obj->empty();

	std::cout << param_2 << ' ' << param_3 << std::endl;

	return 0;
}
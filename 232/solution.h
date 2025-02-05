#pragma once

#include <string>
#include <cmath>
#include <vector>
#include <stack>
using std::string;
using std::vector;


class MyQueue {
private:
    bool which_stack;   // which stack is working on. True means stack_1, false means stack_2;
    std::stack<int> stack_1;    //stack top = queue end. Use stack 1 when push into queue
    std::stack<int> stack_2;    //stack top = queue top. Use stack 2 when pop from queue

    /*
    * move stack2 to stack1
    */
    void reverse(std::stack<int> &stack1, std::stack<int> &stack2)
    {
        while (!stack2.empty())
        {
            stack1.push(stack2.top());
            stack2.pop();
        }
    }

public:
    MyQueue() {
        which_stack = true;
    }
    
    void push(int x) {
        if (!which_stack)
        {
            reverse(stack_1, stack_2);
            which_stack = true;
        }
            
        stack_1.push(x);
    }
    
    int pop() {
        if (which_stack)
        {
            reverse(stack_2, stack_1);
            which_stack = false;
        }
        if (stack_2.empty()) return 0;

        int top_value = stack_2.top();
        stack_2.pop();
        return top_value;
    }
    
    int peek() {
        if (which_stack)
        {
            reverse(stack_2, stack_1);
            which_stack = false;
        }
        if (stack_2.empty()) return 0;
        return stack_2.top();
    }
    
    bool empty() {
        if (stack_1.empty() && stack_2.empty())
            return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
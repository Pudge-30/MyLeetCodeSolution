#pragma once

#include <string>
#include <cmath>
#include <vector>
#include <queue>
using std::string;
using std::vector;


class MyStack {
private:
    bool which_queue;   //which queue is working on;true means using end_to_top, false means using top_to_end;
    std::queue<int> end_to_top;
    std::queue<int> top_to_end;

    void ooo()
    {

    }

    //Reverse queue2 to queue1
    void reverse(std::queue<int> &queue1, std::queue<int> &queue2)
    {
        if (!queue2.empty())
        {
            int data = queue2.front();
            queue2.pop();
            reverse(queue1, queue2);
            queue1.push(data);
        }
    }

public:
    MyStack() {
        which_queue = false;
    }
    
    void push(int x) {
        if (!which_queue)
        {
            reverse(end_to_top, top_to_end);
            which_queue = true;
        }
        end_to_top.push(x);
    }
    
    int pop() {
        if (which_queue)
        {
            reverse(top_to_end,end_to_top);
            which_queue = false;
        }
        int data = 0;
        if (!top_to_end.empty())
        {
            data = top_to_end.front();
            top_to_end.pop();
        }
        
        return data;
    }
    
    int top() {
        if (which_queue)
        {
            reverse(top_to_end, end_to_top);
            which_queue = false;
        }
        if (top_to_end.empty()) return 0;
        return top_to_end.front();
    }
    
    bool empty() {
        if (top_to_end.empty() && end_to_top.empty()) return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
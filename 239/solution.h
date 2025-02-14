#pragma once

#include <string>
#include <cmath>
#include <vector>
#include <deque>
#include <iostream>
using std::string;
using std::vector;


class Solution {
    public:
        class MyQueue{
        private:
            std::deque<int> que;
        public:
            MyQueue()
            {
                que.clear();
            }

            void pop()
            {
                if (!que.empty())
                    que.pop_front();
            }
    
            int top()
            {
                if (!que.empty())
                {
                    return que.front();
                }
                return 0;
            }
    
            void push(int x)
            {
                while (!que.empty() && (que.back() < x))
                {
                    que.pop_back();
                }
                que.push_back(x);
            }
        };
    
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            MyQueue queue_;
            std::vector<int> max_val;
            for (int i = 0; i < k; i++)
            {
                queue_.push(nums[i]);
            }
            max_val.push_back(queue_.top());

            for (int i = 0; i < (nums.size() - k); i++)
            {

                queue_.push(nums[k + i]);
                if (nums[i] == queue_.top())
                {
                    queue_.pop();
                }

                max_val.push_back(queue_.top());
            }

            return max_val;
        }
    };
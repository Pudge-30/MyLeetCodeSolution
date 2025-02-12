#pragma once

#include <string>
#include <cmath>
#include <vector>
#include <stack>
using std::string;
using std::vector;


class Solution {
    public:
        string removeDuplicates(string s) {
            std::stack<char> c_stack;
            int s_size = s.size();
            for (int i = 0; i<s.size(); i++)
            {
                if (c_stack.empty() || c_stack.top() != s[i])
                    c_stack.push(s[i]);
                else
                {
                    c_stack.pop();
                    s_size = s_size - 2;
                }
            }
            s.resize(s_size);
            for (int i = s_size-1; i>=0;i--)
            {
                s[i] = c_stack.top();
                c_stack.pop();
            }
            return s;
        }
    };
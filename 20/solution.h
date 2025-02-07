#pragma once

#include <string>
#include <cmath>
#include <stack>
using std::string;



class Solution {
public:
    bool isMatch(char c1, char c2)
    {
        if (c1 == '(' && c2 == ')') return true;
        if (c1 == '[' && c2 == ']') return true;
        if (c1 == '{' && c2 == '}') return true;
        return false;
    }

    bool isValid(string s) {
        std::stack<char> st;
        for (int i = 0; i<s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') st.push(s[i]);
            else
            {
                if (st.empty()) return false;
                if (isMatch(st.top(), s[i]))
                    st.pop();
                else return false;
            }
        }

        if (!st.empty()) return false;
        return true;
    }
};
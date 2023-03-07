#pragma once

#include <string>
#include <vector>
#include <algorithm>
using std::string;
using std::vector;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::vector<char> existingchr;
        existingchr.clear();
        int maxlen = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (std::find(existingchr.begin(), existingchr.end(), s[i]) != existingchr.end())
            {
                if (existingchr.size() > maxlen)
                {
                    maxlen = existingchr.size();
                }

                std::vector<char>::iterator it;
                it = std::find(existingchr.begin(), existingchr.end(), s[i]);
                existingchr.erase(existingchr.begin(), it + 1);
                existingchr.push_back(s[i]);
            } else
            {
                existingchr.push_back(s[i]);
            }
        }
        if (existingchr.size() > maxlen)
        {
            maxlen = existingchr.size();
        }
        return maxlen;
    }
};
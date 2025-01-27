#pragma once

#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <unordered_map>
using std::string;
using std::vector;
using std::set;

class Solution {
public:
    string reverseStr(string s, int k) {
        int time = s.size() / (2 * k);
        int left = s.size() - time * 2 * k;
        if (left >= k)
        {
            time++;
        }
        for (int i = 0 ; i < time; i++)
        {
            int start_index = i * 2 * k;
            for (int j = 0; j < k / 2; j++)
            {
                char tmp= s[start_index + j];
                s[start_index + j] = s[start_index + k - 1 - j];
                s[start_index + k - 1 - j] = tmp;
            }
        }
        if (left < k)
        {
            int start_index = time * 2 * k;
            for (int j = 0; j < left/2; j++)
            {
                char tmp= s[start_index + j];
                s[start_index + j] = s[start_index + left - 1 - j];
                s[start_index + left - 1 - j] = tmp;
            }
        }

        return s;
    }
};
#pragma once

#include <string>
#include <cmath>
#include <vector>
using std::string;
using std::vector;


class Solution {
public:
    void get_next(string t, vector<int> &next)
    {
        int i = 0, j =-1;
        next[0] = -1;

        while (i < t.size() - 1)
        {
            if (j == -1 || t[i] == t[j])
            {
                ++i; ++j;
                next[i] = j;
            } else
            {
                j = next[j];
            }
        }
    }

    bool repeatedSubstringPattern(string s) {
        std::vector<int> next(s.size());
        get_next(s, next);

        if (s.size() == 1) return false;

        int p = next[s.size() - 1];
        while ( p!= -1 && s[s.size() - 1] != s[p])
        {
            p = next[p];
        }
        p++;

        int q = 2 * p - (int)s.size();
        if (q < 0) return false;
        if (q == 0) return true;
        if ((p - q) > q) return false;
        if (q % (p - q) != 0) return false;
        return true;
    }
};
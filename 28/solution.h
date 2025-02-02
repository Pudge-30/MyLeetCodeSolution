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

        //next[i] = j, 即t[i]匹配失败后需要重新和t[j]进行匹配，也可理解为在t[0]_t[i-1]子串中，最长相等前后缀的长度为j
        //所以接下来要比较t[i]与t[j]是否相等
        //若相等，则t[i+1] = j+1
        //若不等，则要找到t[j]前的最长相等前后缀，即j=next[j]
        while (i < t.size() - 1)
        {
            // 从首个字母开始匹配(j = -1)，或者t[i] = t[j]
            if (j == -1 || t[i] == t[j])
            {
                ++i; ++j;
                if (t[i] != t[j])   next[i] = j;    //j = -1
                    else next[i] = next[j];     //优化后的kmp，即t[i] = t[j]时，将next[j]修正为next[next[j]]
            } else
            {
                j = next[j];
            }
        }
    }

    int strStr(string haystack, string needle) {
        vector<int> next(needle.size());
        get_next(needle, next);

        int i = 0, j = 0;   //i,j分别指向正在比较的字母
        //持续比较，直到任一指针超过比较范围
        while ((i < (int)haystack.size()) && (j < (int)needle.size()))  //c++ string.size()的返回值为无符号数，与负数比较时需要类型转换
        {
            //j = -1， 意为与子串的首字母都无法匹配，此时需要将i与j均向后移动一格（j=0，即重新与首字母进行匹配）
            if (j == -1 || haystack[i] == needle[j])
            {
                ++i; ++j;
            } else{
                j = next[j];
            }
        }

        if (j >= needle.size())
            return (i - needle.size());
        else 
            return -1;
    }
};
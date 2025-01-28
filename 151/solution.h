#pragma once

#include <string>
#include <cmath>
#include <vector>
using std::string;
using std::vector;


class Solution {
public:
    void reverseWord(string &s, int start, int end){
        char tmp;
        for (int i = start; i < (start + end + 1) / 2; i++)
        {
            tmp = s[i];
            s[i] = s[end - i + start];
            s[end - i + start] = tmp;
        }
    }

    string reverseWords(string s) {
        //删除多余的空格
        int index = 0;
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (s[i] == ' ' && (i == 0 || s[i-1] == ' ' || i == (s.size() -1)))
            {
                continue;
            }
            s[index] = s[i];
            index++;
        }
        s.resize(index);

        //将整个字符串逆置
        reverseWord(s, 0 ,s.size()-1);

        //再单独将每一个单词逆置
        
        int word_start = 0;
        for (int i = 0; i <= s.size(); i ++)
        {
            if (s[i] == ' ' || i == s.size())
            {
                reverseWord(s, word_start, i-1);
                word_start = i+1;
            }
        }
        
        return s;
    }
};
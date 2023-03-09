#pragma once
#include <vector>
#include <string>


using std::string;
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        std::string ret = "";
        int row = 0;
        int column = 0;

        std::vector<std::vector<char>> result(numRows, std::vector<char>());

         for (int i = 0; i < s.length(); i++)
        {
            int currentrow = i % (numRows * 2 - 2);
            if (currentrow < numRows)
            {
                result[currentrow].push_back(s[i]);
            }             
            else
            {
                for (int j = 0; j < numRows; j++)
                {
                    if (j != (numRows * 2 - 2 - currentrow ))
                    {
                        //result[j].push_back(' ');
                    }
                    else {
                        result[j].push_back(s[i]);
                    }
                }
            }
        }

        for (int i = 0; i < numRows; i++)
        {
            for (auto ch : result[i])
            {
                ret = ret + ch;
            }
            //ret = ret + '\n';
        }

        return ret;
    }
};
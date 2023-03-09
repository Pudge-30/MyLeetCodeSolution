#pragma once
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 1) return s;
        if (s.length() == 2)
        {
            if (s[0] == s[1]) return s;
            else
            {
                std::string ret = s.substr(0, 1);
                return ret;
            }

        }

        std::vector<std::vector<bool>> ispalindrome(s.length(), std::vector<bool>(s.length(), false));


        int distance = 2;
        int start = 0;
        int end = 0;
        for (int i = 0; i < s.length(); i++)
        {
            ispalindrome[i][i] = true;
        }
        for (int i = 0; i < s.length() - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                ispalindrome[i][i + 1] = true;
                start = i;
                end = i + 1;
            }
        }


        for (distance = 2; distance < s.length(); distance++)
        {
            for (int i = 0; i < s.length() - distance; i++)
            {
                if (ispalindrome[i + 1][i + distance - 1] == true && s[i] == s[i + distance])
                {
                    ispalindrome[i][i + distance] = true;
                    start = i;
                    end = i + distance;
                }
            }
        }

        std::string ret = s.substr(start, end - start + 1);

        return ret;


    }
};
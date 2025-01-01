#pragma once

#include <string>
#include <cmath>
using std::string;


class Solution {
public:
    bool isMatch(string s, string p) {
        // The charactor being checked now.
        int sbit = 0;
        int pbit = 0;

        while (sbit != s.size()  && pbit != p.size())
        {
            // if current p char is ., which means all charactors are accpectable.
            if (p[pbit] == '.')
            {
                sbit++;
                pbit++;
            } 
            else if (p[pbit] == '*')
            {
                if (s[sbit] == p[pbit - 1] || p[pbit-1] == '.')
                {
                    sbit++;
                } else{
                    pbit++;
                }
            }
            else if (s[sbit] == p[pbit])
            {
                sbit++;
                pbit++;
            } else{
                if (pbit != p.size() - 1 && p[pbit+1] == '*')
                {
                    pbit++;
                } else return false;
            }
        }

        // Return true only when all charactors match.
        if (sbit == (s.size()) && (pbit == (p.size()) || (pbit == (p.size() - 1) && p[pbit] == '*')))
        {
            return true;
        } else{
            return false;
        }
    }
};
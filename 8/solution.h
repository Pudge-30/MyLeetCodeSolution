#pragma once

#include <string>
using std::string;


class Solution {
public:
    int myAtoi(string s) {
        int retval = 0;
        // Judge if its a valid number
        bool valid = false;
        // Judge if its a negative number
        bool negative = false;
        // Judge if its a overflow number
        bool overflow = false;
        for (int charindex = 0; charindex < s.size(); charindex++)
        {
            if (valid && (s[charindex] < '0' || s[charindex] > '9'))
            {
                break;
            }

            if (s[charindex] == '-')
            {
                if (charindex < s.size() - 1 && s[charindex + 1] >= '0' && s[charindex + 1] <= '9')
                {
                    valid = true;
                    negative = true;
                }
                else
                {
                    break;
                }
            }
            else if (s[charindex] == '+')
            {
                if (charindex < s.size() - 1 && s[charindex + 1] >= '0' && s[charindex + 1] <= '9')
                {
                    valid = true;
                    negative = false;
                }
                else
                {
                    break;
                }
            }
            else if (s[charindex] >= '0' && s[charindex] <= '9')
            {
                if (!valid /* First time enter the valid part*/)
                {
                    valid = true;
                }
                if (CheckOverflow(retval, s[charindex] - '0'))
                {
                    overflow = true;
                    break;
                }
                else {
                    retval = retval * 10 + (s[charindex] - '0');
                }
            }
            else
            {
                if (!valid && s[charindex] != ' ')
                {
                    break;
                }
            }
        }
        if (!overflow)
        {
            if (negative)
            {
                retval = -retval;
            }
        }
        else
        {
            if (!negative)
            {
                retval = INT_MAX;
            }
            else
            {
                retval = -INT_MAX - 1;
            }
        }
        

        return retval;
    }

private:
    // If (a*10 + b) overflow, the return value would be false; otherwise, it would be true;
    bool CheckOverflow(int a, int b)
    {
        if (a != 0 && (a > INT_MAX / 10))
        {
            return true;
        }

        int tena = a * 10;

        if (b > INT_MAX - tena)
        {
            return true;
        }

        return false;
    }

};
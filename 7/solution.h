#pragma once

#include <string>

class Solution {
public:
    int reverse(int x) {
        std::string intmaxstr = std::to_string(INT_MAX);
        std::string oldabsstr = std::to_string(x);

        if (x > 0)
        {
            intmaxstr[9] = '7';
        }
        int overrangeoffset = 0;
        if (x < 0)
        {
            overrangeoffset = 1;
        }

        bool overrange = false;
        if ((oldabsstr.length() - overrangeoffset) == intmaxstr.length())
        {

            for (int i = 0; i < intmaxstr.length(); i++)
            {
               
                if (oldabsstr[oldabsstr.length() - i - 1] > intmaxstr[i])
                {
                    overrange = true;
                    break;
                }
                else if (oldabsstr[oldabsstr.length() - i - 1] < intmaxstr[i])
                {
                    overrange = false;
                    break;
                }
            }
        }

        if (overrange)
        {
            return 0;
        }


        std::string oldstr = std::to_string(x);
        


        std::string newstr = "";
        int offset = 0;
        if (x < 0)
        {
            newstr += '-';
            offset = 1;
        }
        for (int i = 0; i < (oldstr.length() - offset); i++)
        {
            newstr = newstr + oldstr[oldstr.length() - i - 1];
        }
        int ret = 0;
        ret = atoi(newstr.c_str());

        return ret;
    }
};
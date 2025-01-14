#pragma once

#include <string>
#include <cmath>
#include <vector>
using std::string;
using std::vector;


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low = 0;
        int high = 0;
        int sum = 0;
        int retval = 0;

        while (high < nums.size() && sum < target)
        {
            sum += nums[high];
            high++;
        }

        if (sum < target) return 0;

        retval = high - low;

        while (low < nums.size())
        {
            sum -= nums[low];
            low ++;
            while (high < nums.size() && sum < target)
            {
                sum += nums[high];
                high++;
            }

            if ((sum >= target) && ((high - low) < retval)) retval = high - low;
        }

        return retval;
    }
};
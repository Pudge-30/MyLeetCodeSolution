#pragma once

#include <string>
#include <cmath>
#include <vector>
using std::string;
using std::vector;


class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int low = 0;               
        int high = nums.size() - 1;

        vector<int> retval(nums.size(), 0);


        // 
        while (low <= high)
        {
            if (abs(nums[low]) < abs(nums[high]))
            {
                retval[high - low] = nums[high] * nums[high];
                high--;
            } else
            {
                retval[high-low] = nums[low] * nums[low];
                low++;
            }
            
        } 

        return retval;
    }
};
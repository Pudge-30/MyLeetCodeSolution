#pragma once

#include <string>
#include <cmath>
#include <vector>
using std::string;
using std::vector;


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int low = 0;    //used to find the first element not equal to val
        int high = nums.size() - 1; //used to find the first element equal to val
        int temp = 0;   //used to exchange nums[low] and nums[high]
        
        while (low <= high)
        {
            while (low <= nums.size() - 1  && nums[low] != val)   //find the first element not equal to val
                low++;
            while (high >= 0  && nums[high] == val)      //find the first element equal to val
                high--;
            
            if (low < high && low < nums.size() && high >= 0)
            {
                temp = nums[low];
                nums[low] = nums[high];
                nums[high] = temp;
            }
        }

        return low;
    }
};
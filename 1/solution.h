#pragma once

#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int index = 0;
        while (nums.size() != 0)
        {
            int current_num = nums.front();
            for (int i =1; i< nums.size(); i++)
            {
                if (current_num + nums.at(i) == target)
                {
                    std::vector<int> output = {index, index + i};
                    return output;
                }
            }
            nums.erase(nums.begin());
            index++;
        }
        return std::vector<int>();
    }
};
#pragma once

#include <string>
#include <vector>
#include <unordered_map>
using std::string;
using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map <int,int> nums_map;
        nums_map.clear();
        std::unordered_map<int, int>::iterator iter;
        for (int i = 0; i < nums.size(); i++)
        {
            iter = nums_map.find(target - nums[i]);
            if (iter != nums_map.end())
            {
                return{iter->second, i};
            };
            nums_map.insert(std::pair<int,int>(nums[i], i));
        }
        return {0,0};
    }
};
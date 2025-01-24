#pragma once

#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>

using std::string;
using std::vector;

class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {
        // Used to map the value and the frequency
        std::unordered_map<int, int> nums_count_map;
        nums_count_map.clear();
        // Used to store the three numbers that meet the require
        vector<vector<int>> result;
        // Sort before search
        sort(nums.begin(), nums.end());
        for (int num : nums)
        {
            nums_count_map[num]++;
        }
        std::unordered_map<int,int>::iterator i_iter;
        std::unordered_map<int,int>::iterator j_iter;
        std::unordered_map<int,int>::iterator k_iter;
        for (i_iter = nums_count_map.begin(); i_iter != nums_count_map.end(); i_iter++)
        {
            if (i_iter->second >=3)
            {
                if (i_iter->first == 0)
                    result.push_back(vector<int>{0, 0, 0});
            }
            if (i_iter->second >=2)
            {
                k_iter = nums_count_map.find(-2 * i_iter->first);
                if ((k_iter != nums_count_map.end()) && (k_iter->first > i_iter->first)){
                     result.push_back(vector<int>{i_iter->first, i_iter->first, -2 * i_iter->first});
                }
                   
            }
            //j_iter = i_iter;
            //j_iter++;
            for (j_iter = nums_count_map.begin(); j_iter != nums_count_map.end(); j_iter++)
            {
                if (j_iter->first > i_iter->first)
                {
                    if ((i_iter->first == -2 * j_iter->first) && (j_iter->second >= 2))
                        result.push_back(vector<int>{i_iter->first, j_iter->first, j_iter->first});
                    k_iter = nums_count_map.find(-(i_iter->first + j_iter->first));
                    if ((k_iter != nums_count_map.end()) && (k_iter->first > j_iter->first))
                    {
                        result.push_back(vector<int>{i_iter->first, j_iter->first,k_iter->first});
                    }
                }
            }

        }
        return result;
    }
};
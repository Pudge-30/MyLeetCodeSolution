#pragma once

#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <unordered_set>
using std::string;
using std::vector;
using std::set;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_set <int> result_set;
        std::unordered_set <int> nums_set(nums1.begin(), nums1.end());
        for (int num : nums2)
        {
            if (nums_set.find(num) != nums_set.end())
            {
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};
#pragma once

#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <unordered_map>
using std::string;
using std::vector;
using std::set;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        std::unordered_map<int, int> two_vec_sum_map;

        int sum = 0;

        for (int n1 : nums1)
        {
            for (int n2 : nums2)
                two_vec_sum_map[n1 + n2]++;
        }

        for (int n3 : nums3)
        {
            for (int n4 : nums4)
                sum += two_vec_sum_map[-(n3+n4)];
        }

        return sum;

    }
};
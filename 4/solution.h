#pragma once

#include <string>
#include <vector>
#include <algorithm>
using std::string;
using std::vector;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() == 0)
        {
            if (nums2.size() % 2 == 0)
            {
                return (nums2[nums2.size() / 2] + nums2[nums2.size() / 2 - 1]) / 2.0;
            } else{
                return nums2[(int)(nums2.size() / 2.)];
            }
        }

        if (nums2.size() == 0)
        {
            if (nums1.size() % 2 == 0)
            {
                return (nums1[nums1.size() / 2] + nums1[nums1.size() / 2 - 1]) / 2.0;
            } else{
                return nums1[(int)(nums1.size() / 2.)];
            }
        }


        int result1 = 0;
        int result2 = 0;
        int midpos = (int)(nums1.size() + nums2.size()) /2;
        int mark1 = 0;
        int mark2 = 0;
        while ((mark1+mark2 - 1) < midpos && (mark1 < nums1.size() || mark2 < nums2.size()))
        {
            if (mark2 >= nums2.size() || mark1 < nums1.size() && nums1.at(mark1) <= nums2.at(mark2) )
            {
                result2 = result1;
                result1 = nums1.at(mark1);
                mark1++;
            } else{
                result2 = result1;
                result1 = nums2.at(mark2);
                mark2++;
            }
        }
        double ret = 0.0;
        if ((nums1.size() + nums2.size()) % 2 == 0)
        {
            ret = (result2 + result1) / 2.;
        } else{
            ret = result1;
        }

        return ret;
    }
};
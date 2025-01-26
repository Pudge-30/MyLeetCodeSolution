#pragma once

#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>

using std::string;
using std::vector;

bool outofrange(long long data)
{
    if (data > 1000000000 || data < -1000000000)
    {
        return true;
    }
    return false;
}

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::vector<int> nonrepeat_nums;
        std::unordered_map<int, int> num_freq_map;
        num_freq_map.clear();
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0 || nums[i] != nums[i - 1])
            {
                nonrepeat_nums.push_back(nums[i]);
            }
            num_freq_map[nums[i]]++;
        }
        int left = 0;
        int right = 0;
        for (int i = 0; i < nonrepeat_nums.size(); i++)
        {
            int i_num = nonrepeat_nums[i];
            int i_freq = num_freq_map[i_num];

            //aaaa
            if ((i_freq >= 4) &&
                !outofrange(static_cast<long long>(i_num) * 4) &&
                (i_num * 4 == target))
                result.push_back(vector<int>(4, i_num));
            for (int j = i + 1; j < nonrepeat_nums.size(); j++)
            {
                int j_num = nonrepeat_nums[j];
                int j_freq = num_freq_map[j_num];

                //aaab
                if ((i_freq >= 3) &&
                    !outofrange(static_cast<long long>(i_num) * 3 + j_num) &&
                    (i_num * 3 + j_num == target))
                    result.push_back(vector<int>{i_num, i_num, i_num, j_num});
                //aabb
                if ((i_freq >= 2) &&
                    (j_freq >= 2) &&
                    !outofrange(static_cast<long long>(i_num) * 2 + static_cast<long long>(j_num) * 2) &&
                    (i_num * 2 + j_num * 2 == target))
                    result.push_back(vector<int>{i_num, i_num, j_num, j_num});
                //abbb
                if ((j_freq >= 3) &&
                    !outofrange(static_cast<long long>(i_num) + static_cast<long long>(j_num) * 3) &&
                    (i_num + j_num * 3 == target))
                    result.push_back(vector<int>{i_num, j_num, j_num, j_num});

                //aabc
                if ((i_freq >= 2) &&
                    !outofrange(target - (static_cast<long long>(i_num) * 2 + j_num)) &&
                    ((target - (static_cast<long long>(i_num) * 2 + j_num)) > j_num))
                {
                    if (num_freq_map.find(target - (i_num * 2 + j_num)) != num_freq_map.end())
                    {
                        result.push_back(vector<int>{i_num, i_num, j_num, target - (i_num * 2 + j_num)});
                    }
                }

                //abbc
                if ((j_freq >= 2) &&
                    !outofrange(target - (i_num + static_cast<long long>(j_num) * 2)) &&
                    ((target - (i_num + static_cast<long long>(j_num) * 2)) > j_num))
                {
                    if (num_freq_map.find(target - (i_num + j_num * 2)) != num_freq_map.end())
                    {
                        result.push_back(vector<int>{i_num, j_num, j_num, target - (i_num + j_num * 2)});
                    }
                }
                //abcc
                if (((target - (static_cast<long long>(i_num) + j_num)) % 2 == 0) &&
                    !outofrange((target - (static_cast<long long>(i_num) + j_num)) / 2) &&
                    (target - (static_cast<long long>(i_num) + j_num)) > (2 * static_cast<long long>(j_num)))
                {
                    int c = (target - (i_num + j_num)) / 2;
                    if ((num_freq_map.find(c) != num_freq_map.end()) && (num_freq_map[c] >= 2))
                    {
                        result.push_back(vector<int>{i_num, j_num, c, c});
                    }
                }
                //abcd
                for (int k = j + 1; k < nonrepeat_nums.size(); k++)
                {
                    int k_num = nonrepeat_nums[k];
                    if (!outofrange(target - (static_cast<long long>(i_num) + j_num + k_num)) &&
                        (num_freq_map.find(target - (i_num + j_num + k_num)) != num_freq_map.end()) &&
                        ((target - (i_num + j_num + k_num)) > k_num))
                    {
                        result.push_back(vector<int>{i_num, j_num, k_num, target - (i_num + j_num + k_num) });
                    }
                }

            }
        }

        return result;
    }
};


//双指针法
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int k = 0; k < nums.size(); k++) {
            // 剪枝处理
            if (nums[k] > target && nums[k] >= 0) {
            	break; // 这里使用break，统一通过最后的return返回
            }
            // 对nums[k]去重
            if (k > 0 && nums[k] == nums[k - 1]) {
                continue;
            }
            for (int i = k + 1; i < nums.size(); i++) {
                // 2级剪枝处理
                if (nums[k] + nums[i] > target && nums[k] + nums[i] >= 0) {
                    break;
                }

                // 对nums[i]去重
                if (i > k + 1 && nums[i] == nums[i - 1]) {
                    continue;
                }
                int left = i + 1;
                int right = nums.size() - 1;
                while (right > left) {
                    // nums[k] + nums[i] + nums[left] + nums[right] > target 会溢出
                    if ((long) nums[k] + nums[i] + nums[left] + nums[right] > target) {
                        right--;
                    // nums[k] + nums[i] + nums[left] + nums[right] < target 会溢出
                    } else if ((long) nums[k] + nums[i] + nums[left] + nums[right]  < target) {
                        left++;
                    } else {
                        result.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
                        // 对nums[left]和nums[right]去重
                        while (right > left && nums[right] == nums[right - 1]) right--;
                        while (right > left && nums[left] == nums[left + 1]) left++;

                        // 找到答案时，双指针同时收缩
                        right--;
                        left++;
                    }
                }

            }
        }
        return result;
    }
};

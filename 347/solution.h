#pragma once

#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
    public:
        class compare{
            public:
                bool operator()(const pair<int , int>& lhs, const pair<int, int>& rhs)
                {
                    return lhs.second > rhs.second;
                }
        };
        vector<int> topKFrequent(vector<int>& nums, int k) {
            std::unordered_map<int, int> num_freq_map;
            num_freq_map.clear();
            for (auto num : nums)
            {
                num_freq_map[num]++;
            }
            
            priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pri_que;

            for (unordered_map<int ,int>::iterator it = num_freq_map.begin(); it != num_freq_map.end(); it++)
            {
                pri_que.push(*it);
                if (pri_que.size() > k)
                {
                    pri_que.pop();
                }
            }

            vector<int> result(k);
            for (int i = k -1; i >=0; i--)
            {
                result[i] = pri_que.top().first;
                pri_que.pop();
            }
            return result;
        }
    };
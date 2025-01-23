#pragma once

#include <string>
#include <cmath>
#include <vector>
#include <unordered_set>
using std::string;
using std::vector;

class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set<int> appeared_num;
        int elem = 0;
        int sum = 0;
        while (appeared_num.find(n) == appeared_num.end())
        {
            appeared_num.insert(n);
            sum = 0;
            while (n != 0)
            {
                sum += (n % 10) * (n % 10);
                n = n / 10;
            }
            n = sum;
            if (n == 1) return true;
        }
        return false;
    }
};
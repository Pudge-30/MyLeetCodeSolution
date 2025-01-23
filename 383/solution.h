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
    bool canConstruct(string ransomNote, string magazine) {
        int record[26] = {0};
        for (char c : magazine)
            record[c - 'a']++;
        for (char c : ransomNote)
        {
            record[c - 'a']--;
            if (record[c - 'a'] <0) return false;
        }
        return true;
    }
};
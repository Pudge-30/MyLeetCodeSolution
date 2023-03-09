#pragma once

#include <string>
#include <cmath>
using std::string;


class Solution {
public:
    bool isPalindrome(int x) {
        // if its a negative number, it is obviously not a palindrome.
        if (x < 0) return false;
        // log(0) is meaningless;
        // log(0) is meaningless;
        if (x == 0) return true;

        short bits = short(log(x) / log(10));

        short highest = 0;
        short lowest = 0;

        // Run till x is a single digit.
        while (bits > 0)
        {
            // Get the highest bit;
            highest = (short)(x / pow(10, bits));
            // Get the lowest bit;
            lowest = short(x % 10);
            
            // Retuen false immediately when the highest bit is not equal to the lowest number.
            if (highest != lowest) return false;

            x = (int)(x - highest * pow(10, bits) - lowest) / 10;

            bits = bits - 2;
        }

        // When x finally become a single digit, it is obviously a palindrome.
        return true;
    }
};
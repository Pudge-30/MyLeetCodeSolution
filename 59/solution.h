#pragma once

#include <string>
#include <cmath>
#include <vector>
using std::string;
using std::vector;


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> retmatrix(n, vector<int>(n, 0));

        int x = 0;
        int y = 0;
        int num = 1;

        int i = 0;
        for (i = n-1; i > 0 ; i = i - 2)
        {
            for (int j = 0; j < i; j++)
            {
                retmatrix[x][y] = num;
                num++;
                y++;
            }

            for (int j = 0; j < i; j++)
            {
                retmatrix[x][y] = num;
                num++;
                x++;
            }

            for (int j = 0; j < i; j++)
            {
                retmatrix[x][y] = num;
                num++;
                y--;
            }

            for (int j = 0; j < i; j++)
            {
                retmatrix[x][y] = num;
                num++;
                x--;
            }

            x = x+1; y=y+1;
        }

        if (i == 0) retmatrix[x][y] = num;
        return retmatrix;
    }
};
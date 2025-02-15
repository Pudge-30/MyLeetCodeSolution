#pragma once

#include <string>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;


/**
 Definition for a binary tree node.
**/
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
 class Solution {
    public:
        vector<vector<int>> levelOrder(TreeNode* root) {
            std::queue<TreeNode*> que;  
            if (root != nullptr)
            {
                que.push(root);
            }
            vector<vector<int>> result;
            vector<int> current_level;
            while (!que.empty())
            {
                int que_size = que.size();
                for (int i = 0; i < que_size; i++)
                {
                    current_level.push_back(que.front()->val);
                    if (que.front()->left != nullptr) que.push(que.front()->left);
                    if (que.front()->right != nullptr) que.push(que.front()->right);
                    que.pop();
                }
                result.push_back(current_level);
                current_level.clear();
            }
            return result;
        }
    };
#pragma once

#include <string>
#include <cmath>
#include <vector>
using std::string;
using std::vector;
using namespace std;

/**
 * Definition for a binary tree node.
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
        TreeNode* nextNode(TreeNode* node, int val)
        {
            if (val > node->val && node->right != nullptr) 
                return node->right;
            if (val < node->val && node->left != nullptr) 
                return node->left;
            return nullptr;
        }
    
        TreeNode* insertIntoBST(TreeNode* root, int val) {
            TreeNode* newnode =new TreeNode(val);
            TreeNode* node = root;
            while (nextNode(node, val) != nullptr)
            {
                node = nextNode(node,val);
            }
            if (val > node->val) node->right = newnode;
            if (val < node->val) node->left = newnode;
            return root;
        }
    };
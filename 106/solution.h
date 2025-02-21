#pragma once

#include <string>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;


/**
 * Definition for a binary tree node.
 **/ struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
    public:
        TreeNode* build(vector<int> &inorder, vector<int>&postorder, int instart, int inend, int poststart, int postend)
        {
            if ((instart > inend) || (poststart > postend)) return nullptr;
            if ((instart == inend) && (poststart == postend))
            {
                TreeNode* node = new TreeNode();
                node->val = inorder[instart];
                node->left = nullptr;
                node->right = nullptr;
                return node;
            }
            TreeNode* node = new TreeNode();
            node->val = postorder[postend];
            int midindex = 0;
            for (int i = instart; i <= inend;i++)
            {
                if (inorder[i] == postorder[postend])
                {
                    midindex = i;
                    break;
                }
            }
            node->left = build(inorder, postorder, instart, midindex -1, poststart, poststart + midindex -1 - instart);
            node->right = build(inorder, postorder, midindex+1, inend, poststart + midindex - instart, postend - 1);
            return node;
        }
    
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            if (inorder.size() == 0) return nullptr;
            return build(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
        }
    };
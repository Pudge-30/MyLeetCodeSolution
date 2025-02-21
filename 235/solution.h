#pragma once

#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <unordered_map>
#include <queue>

using namespace std;

/**
 * Definition for a binary tree node.
 **/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
    TreeNode(int x,TreeNode* l, TreeNode* r)
    {
        this->val = x;
        this->left = l;
        this->right = r;
    }
};


 class Solution {
    public:
        int traversal(TreeNode* node,TreeNode* p, TreeNode* q,TreeNode* &ancestor)
        {
            int lb=0,rb =0;
            if (node->left != nullptr) lb = traversal(node->left, p, q, ancestor);
            if (node->right != nullptr) rb = traversal(node->right, p, q, ancestor);
            
            if (node->val == p->val)
            {
                if (lb == 2 || rb == 2)
                {
                    ancestor = node;
                    return 3;
                } else
                {
                    return 1;
                }
            }
    
            if (node->val == q->val)
            {
                if (lb == 1 || rb == 1)
                {
                    ancestor = node;
                    return 3;
                } else
                {
                    return 2;
                }
            }
    
            if ((lb == 1 && rb == 2) || (lb == 2 && rb == 1))
            {
                ancestor = node;
                return 3;
            }
    
            return (lb + rb);
        }
    
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            TreeNode * ancestor = nullptr;
            traversal(root, p, q, ancestor);
            return ancestor;
        }
    };
#pragma once

#include <stack>


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


class Solution112
{
public:
    bool Traverse(TreeNode* cur, int curSum, int targetSum)
    {
        if (cur == nullptr)
            return false;
        
        if (cur->left == nullptr && cur->right == nullptr)
        {
            if (curSum + cur->val == targetSum)
                return true;
        }
        bool left = Traverse(cur->left, curSum + cur->val, targetSum);
        bool right = Traverse(cur->right, curSum + cur->val, targetSum);
        
        return left || right;
    }


    bool hasPathSum(TreeNode* root, int targetSum)
    {
        return Traverse(root, 0, targetSum);
    }
};
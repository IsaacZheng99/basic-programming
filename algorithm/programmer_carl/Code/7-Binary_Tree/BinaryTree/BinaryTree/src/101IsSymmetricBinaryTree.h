#pragma once


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


class Solution
{
public:
    bool CompareLeftRight(TreeNode* left, TreeNode* right)
    {
        if (left && !right || 
            !left && right || 
            left && right && left->val != right->val)
            return false;
        else if (!left && !right)
            return true;

        bool outside = CompareLeftRight(left->left, right->right);
        bool inside = CompareLeftRight(left->right, right->left);
        return outside && inside;
    }

    bool isSymmetric(TreeNode* root)
    {
        if (!root)
            return true;
        return CompareLeftRight(root->left, root->right);
    }
};
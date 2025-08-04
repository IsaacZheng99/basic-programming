#pragma once

#include <iostream>


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
    bool isValidBST(TreeNode* root)
    {
        if (root == nullptr)
            return true;

        bool isLeftValid = isValidBST(root->left);
        if (!isLeftValid)
            return false;

        if (pre && root->val <= pre->val)
            return false;
        else
            pre = root;
        bool isRightValid = isValidBST(root->right);
        if (!isRightValid)
            return false;

        return true;
    }
private:
    TreeNode* pre = nullptr;
};
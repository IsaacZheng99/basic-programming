#pragma once

#include <algorithm>


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


class Solution110
{
public:
    int GetHeight(TreeNode* cur)
    {
        if (cur == nullptr)
            return 0;
        int leftHeight = GetHeight(cur->left);
        int rightHeight = GetHeight(cur->right);
        if (leftHeight == -1 || rightHeight == -1 || std::abs(leftHeight - rightHeight) > 1)
            return -1;
        return 1 + std::max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root)
    {
        return GetHeight(root) == -1 ? false : true;
    }
};



// Problem: There are two layers of recursion, we can simplify them.
//class Solution110
//{
//public:
//    int GetHeight(TreeNode* cur)
//    {
//        if (cur == nullptr)
//            return 0;
//        int leftHeight = GetHeight(cur->left);
//        int rightHeight = GetHeight(cur->right);
//        return 1 + std::max(leftHeight, rightHeight);
//    }
//
//    bool isBalanced(TreeNode* root)
//    {
//        if (root == nullptr)
//            return true;
//        int leftHeight = GetHeight(root->left);
//        int rightHeight = GetHeight(root->right);
//        if (std::abs(leftHeight - rightHeight) > 1)
//            return false;
//        return isBalanced(root->left) && isBalanced(root->right);
//    }
//};
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


class Solution
{
public:
    TreeNode* searchBST(TreeNode* root, int val)
    {
        TreeNode* cur = root;
        while (cur)
        {
            if (cur->val == val)
                return cur;
            else if (cur->val > val)
                cur = cur->left;
            else
                cur = cur->right;
        }

        return nullptr;
    }
};


//class Solution700
//{
//public:
//    TreeNode* searchBST(TreeNode* root, int val)
//    {
//        std::stack<TreeNode*> stack;
//        stack.push(root);
//
//        while (!stack.empty())
//        {
//            TreeNode* cur = stack.top();
//            stack.pop();
//
//            if (cur == nullptr || cur->val == val)
//                return cur;
//            else if (val > cur->val)
//                stack.push(cur->right);
//            else
//                stack.push(cur->left);
//        }
//
//        return nullptr;
//    }
//};


class Solution700
{
public:
    TreeNode* searchBST(TreeNode* root, int val)
    {
        if (root == nullptr)
            return nullptr;

        if (root->val == val)
            return root;
        else if (root->val > val)
            return searchBST(root->left, val);
        else
            return searchBST(root->right, val);
    }
};
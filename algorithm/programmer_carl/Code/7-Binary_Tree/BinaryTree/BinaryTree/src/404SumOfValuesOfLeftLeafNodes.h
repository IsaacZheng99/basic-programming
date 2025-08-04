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


class Solution404
{
public:
    int sumOfLeftLeaves(TreeNode* root)
    {
        std::stack<TreeNode*> stack;
        stack.push(root);
        int result = 0;

        while (!stack.empty())
        {
            TreeNode* cur = stack.top();
            stack.pop();
            if (cur == nullptr)
                continue;

            if (cur->left && cur->left->left == nullptr && cur->left->right == nullptr)
                result += cur->left->val;

            stack.push(cur->left);
            stack.push(cur->right);
        }

        return result;
    }
};


class Solution404
{
public:
    int sumOfLeftLeaves(TreeNode* root)
    {
        if (root == nullptr)
            return 0;

        int curValue = 0;
        if (root->left && !root->left->left && !root->left->right)
            curValue = root->left->val;
        int leftValue = sumOfLeftLeaves(root->left);
        int rightValue = sumOfLeftLeaves(root->right);
        return curValue + leftValue + rightValue;
    }
};
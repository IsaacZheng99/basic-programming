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
    void Traverse(TreeNode* cur, TreeNode*& pre, int& result)
    {
        if (cur == nullptr)
            return;

        Traverse(cur->left, pre, result);

        if (pre)
            result = std::min(result, std::abs(cur->val - pre->val));
        pre = cur;

        Traverse(cur->right, pre, result);
    }

    int getMinimumDifference(TreeNode* root)
    {
        int result = INT_MAX;
        TreeNode* pre = nullptr;
        Traverse(root, pre, result);

        return result;
    }

};


class Solution
{
public:
    void Traverse(TreeNode* cur)
    {
        if (cur == nullptr)
            return;

        Traverse(cur->left);
       
        if (m_Pre)
            m_Result = std::min(m_Result, std::abs(cur->val - m_Pre->val));
        m_Pre = cur;

        Traverse(cur->right);
    }

    int getMinimumDifference(TreeNode* root)
    {
        Traverse(root);

        return m_Result;
    }
private:
    TreeNode* m_Pre = nullptr;
    int m_Result = INT_MAX;
};
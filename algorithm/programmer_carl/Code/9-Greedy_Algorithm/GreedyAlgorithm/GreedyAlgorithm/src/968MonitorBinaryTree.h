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


class Solution968
{
public:
    bool Traverse(TreeNode* cur)
    {
        if (cur == nullptr)
            return true;

        bool left = Traverse(cur->left);
        bool right = Traverse(cur->right);

        if (!(left && right))
        {
            cur->val = 1;
            m_Result += 1;
            return true;
        }
        else if (cur->left && cur->left->val == 1
            || cur->right && cur->right->val == 1)
            return true;
        return false;
    }

    int minCameraCover(TreeNode* root)
    {
        if (!Traverse(root))
            m_Result += 1;
        return m_Result;
    }
private:
    int m_Result = 0;
};

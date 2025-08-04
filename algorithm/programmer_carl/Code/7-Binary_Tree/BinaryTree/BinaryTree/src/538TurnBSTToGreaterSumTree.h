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
    void Traverse(TreeNode* cur, int& curSum)
    {
        if (cur == nullptr)
            return;

        Traverse(cur->right, curSum);
        cur->val += curSum;
        curSum = cur->val;
        Traverse(cur->left, curSum);
    }

    TreeNode* convertBST(TreeNode* root)
    {
        int curSum = 0;
        Traverse(root, curSum);
        return root;
    }
};
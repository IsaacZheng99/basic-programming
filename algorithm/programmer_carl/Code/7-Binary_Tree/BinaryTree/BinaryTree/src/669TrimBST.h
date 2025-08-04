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


class Solution669
{
public:
    TreeNode* trimBST(TreeNode* root, int low, int high)
    {
        if (root == nullptr)
            return nullptr;

        while (root && (root->val < low || root->val > high))
        {
            if (root->val < low)
                root = root->right;
            else if (root->val > high)
                root = root->left;
        }

        TreeNode* cur = root;
        while (cur)
        {
            while (cur->left && cur->left->val < low)
                cur->left = cur->left->right;
            cur = cur->left;
        }
        
        cur = root;
        while (cur)
        {
            while (cur->right && cur->right->val > high)
                cur->right = cur->right->left;
            cur = cur->right;
        }

        return root;
    }
};


class Solution669
{
public:
    TreeNode* trimBST(TreeNode* root, int low, int high)
    {
        if (root == nullptr)
            return nullptr;

        if (root->val < low)
            return trimBST(root->right, low, high);
        else if (root->val > high)
            return trimBST(root->left, low, high);
        else
        {
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
        }
        return root;
    }
};

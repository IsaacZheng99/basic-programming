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


class Solution701
{
public:
    TreeNode* insertIntoBST(TreeNode* root, int val)
    {
        if (root == nullptr)
            return new TreeNode(val);
        
        TreeNode* parent = nullptr;
        TreeNode* cur = root;
        while (cur)
        {
            parent = cur;
            
            if (cur->val > val)
                cur = cur->left;
            else if (cur->val < val)
                cur = cur->right;
        }

        if (parent->val > val)
            parent->left = new TreeNode(val);
        else if (parent->val < val)
            parent->right = new TreeNode(val);

        return root;
    }
};


class Solution701
{
public:
    TreeNode* insertIntoBST(TreeNode* root, int val)
    {
        if (root == nullptr)
            return new TreeNode(val);
        TreeNode* cur = root;
        while (cur)
        {
            if (cur->val > val)
            {
                if (cur->left)
                {
                    cur = cur->left;
                }
                else
                {
                    cur->left = new TreeNode(val);
                    return root;
                }
            }
            else if (cur->val < val)
            {
                if (cur->right)
                {
                    cur = cur->right;
                }
                else
                {
                    cur->right = new TreeNode(val);
                    return root;
                }
            }
        }

        return root;
    }
};


class Solution701
{
public:
    TreeNode* insertIntoBST(TreeNode* root, int val)
    {
        if (root == nullptr)
        {
            TreeNode* newNode = new TreeNode(val);
            return newNode;
        }
        else if (root->val > val)
        {
            root->left = insertIntoBST(root->left, val);
        }
        else if (root->val < val)
        {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
};


class Solution701
{
public:
    TreeNode* insertIntoBST(TreeNode* root, int val)
    {
        if (root == nullptr)
            root = new TreeNode(val);
        else if (root->val < val)
        {
            if (root->right == nullptr)
            {
                root->right = new TreeNode(val);
            }
            else
                insertIntoBST(root->right, val);
        }
        else if (root->val > val)
        {
            if (root->left == nullptr)
            {
                root->left = new TreeNode(val);
            }
            else
                insertIntoBST(root->left, val);
        }

        return root;
    }
};

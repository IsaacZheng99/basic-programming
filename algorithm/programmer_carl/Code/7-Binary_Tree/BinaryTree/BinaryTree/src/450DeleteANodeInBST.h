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


class Solution450
{
public:
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        if (root == nullptr)
            return root;

        TreeNode* cur = root;
        TreeNode* parent = nullptr;
        while (cur)
        {
            if (cur->val > key)
            {
                parent = cur;
                cur = cur->left;
            }
            else if (cur->val < key)
            {
                parent = cur;
                cur = cur->right;
            }
            else
            {
                TreeNode* newHead = nullptr;

                if (cur->left && cur->right == nullptr)
                    newHead = cur->left;
                else if (cur->left == nullptr && cur->right)
                    newHead = cur->right;
                else if (cur->left && cur->right)
                {
                    newHead = cur->right;
                    TreeNode* curRight = newHead;
                    while (curRight->left)
                        curRight = curRight->left;
                    curRight->left = cur->left;
                }

                if (parent)
                {
                    if (parent->val > cur->val)
                        parent->left = newHead;
                    else if (parent->val < cur->val)
                        parent->right = newHead;

                    return root;
                }
                else
                    return newHead;
            }
        }

        return root;
    }
};


class Solution450
{
public:
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        if (root == nullptr)
            return root;

        if (root->val > key)
            root->left = deleteNode(root->left, key);
        else if (root->val < key)
            root->right = deleteNode(root->right, key);
        else
        {
            if (root->left && root->right == nullptr)
                return root->left;
            else if (root->left == nullptr && root->right)
                return root->right;
            else if (root->left == nullptr && root->right == nullptr)
                return nullptr;
            else
            {
                /*TreeNode* newHead = root->right;
                TreeNode* curRight = newHead;
                while (curRight->left)
                    curRight = curRight->left;
                curRight->left = root->left;

                return newHead;*/

                TreeNode* newHead = root->left;
                TreeNode* curLeft = newHead;
                while (curLeft->right)
                    curLeft = curLeft->right;
                curLeft->right = root->right;

                return newHead;
            }
        }
        return root;
    }
};


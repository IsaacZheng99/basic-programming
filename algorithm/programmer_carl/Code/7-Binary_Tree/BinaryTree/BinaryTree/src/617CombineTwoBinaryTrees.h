#pragma once

#include <queue>


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


class Solution617
{
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2)
    {
        std::queue<TreeNode*> queue;
        if (root2 == nullptr)
            return root1;
        else if (root1 == nullptr)
            return root2;

        queue.push(root1);
        queue.push(root2);

        while (!queue.empty())
        {
            TreeNode* cur1 = queue.front();
            queue.pop();
            TreeNode* cur2 = queue.front();
            queue.pop();
            cur1->val += cur2->val;

            if (cur1->left && cur2->left)
            {
                queue.push(cur1->left);
                queue.push(cur2->left);
            }
            else if (!cur1->left && cur2->left)
                cur1->left = cur2->left;

            if (cur1->right && cur2->right)
            {
                queue.push(cur1->right);
                queue.push(cur2->right);
            }
            else if (!cur1->right && cur2->right)
                cur1->right = cur2->right;
        }

        return root1;
    }
};


class Solution617
{
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2)
    {
        if (root1 == nullptr && root2 == nullptr)
            return nullptr;
        else if (root1 != nullptr && root2 == nullptr)
            return root1;
        else if (root1 == nullptr && root2 != nullptr)
            return root2;

        TreeNode* newNode = new TreeNode(root1->val + root2->val);

        TreeNode* left = mergeTrees(root1->left, root2->left);
        TreeNode* right = mergeTrees(root1->right, root2->right);

        newNode->left = left;
        newNode->right = right;

        return newNode;
    }
};
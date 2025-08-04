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


class Solution222
{
public:
    int countNodes(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        int leftDepth = 0;
        int rightDepth = 0;
        TreeNode* leftNode = root->left;
        TreeNode* rightNode = root->right;
        while (leftNode)
        {
            leftDepth += 1;
            leftNode = leftNode->left;
        }
        while (rightNode)
        {
            rightDepth += 1;
            rightNode = rightNode->right;
        }
        if (leftDepth == rightDepth)
            return (2 << leftDepth) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

#pragma once

#include <vector>
#include <algorithm>


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


class Solution106
{
public:
    TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder)
    {
        if (inorder.empty() || postorder.empty())
            return nullptr;

        int rootValue = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(rootValue);

        auto rootIt = std::find(inorder.begin(), inorder.end(), rootValue);
        std::vector<int> leftInorder(inorder.begin(), rootIt);
        std::vector<int> rightInorder(rootIt + 1, inorder.end());


        std::vector<int> leftPostorder;
        std::vector<int> rightPostorder;
        if (rootIt == inorder.end() - 1)
        {
            leftPostorder = std::vector(postorder.begin(), postorder.end() - 1);
        }
        else if (rootIt == inorder.begin())
        {
            rightPostorder = std::vector(postorder.begin(), postorder.end() - 1);
        }
        else
        {
            int leftLength = rootIt - inorder.begin();
            leftPostorder = std::vector(postorder.begin(), postorder.begin() + leftLength);
            rightPostorder = std::vector(postorder.begin() + leftLength, postorder.end() - 1);
        }


        TreeNode* left = buildTree(leftInorder, leftPostorder);
        TreeNode* right = buildTree(rightInorder, rightPostorder);

        root->left = left;
        root->right = right;
        
        return root;
    }
};
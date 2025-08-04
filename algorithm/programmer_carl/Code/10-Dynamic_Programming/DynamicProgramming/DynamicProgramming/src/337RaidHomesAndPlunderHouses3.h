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


class Solution337
{
public:
    std::vector<int> PostOrderTraverse(TreeNode* root)
    {
        std::vector<int> dp(2, 0);
        if (root == nullptr)
            return dp;

        dp[0] = 0;
        dp[1] = root->val;
        std::vector<int> dpLeft = PostOrderTraverse(root->left);
        std::vector<int> dpRight = PostOrderTraverse(root->right);
        dp[0] += std::max(dpLeft[0], dpLeft[1]) + std::max(dpRight[0], dpRight[1]);
        dp[1] += dpLeft[0] + dpRight[0];

        return dp;
    }

    int rob(TreeNode* root)
    {
        std::vector<int> dp = PostOrderTraverse(root);
        return std::max(dp[0], dp[1]);
    }
};
#pragma once

#include <vector>


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
    TreeNode* sortedArrayToBST(std::vector<int>& nums)
    {
        if (nums.empty())
            return nullptr;
        else if (nums.size() == 1)
            return new TreeNode(nums[0]);

        int rootIndex = nums.size() / 2;
        TreeNode* root = new TreeNode(nums[rootIndex]);
        
        std::vector<int> leftNums(nums.begin(), nums.begin() + rootIndex);
        root->left = sortedArrayToBST(leftNums);

        std::vector<int> rightNums(nums.begin() + rootIndex + 1, nums.end());
        root->right = sortedArrayToBST(rightNums);

        return root;
    }
};
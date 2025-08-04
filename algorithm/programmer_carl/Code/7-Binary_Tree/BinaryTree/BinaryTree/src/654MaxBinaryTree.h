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


class Solution654
{
public:
    TreeNode* Construct(std::vector<int>& nums, int begin, int end)
    {
        if (end >= begin)
            return nullptr;

        int maxIdx = -1;
        int curMax = INT_MIN;
        for (int i = begin; i < end; i++)
        {
            if (nums[i] > curMax)
            {
                curMax = nums[i];
                maxIdx = i;
            }
        }
        TreeNode* cur = new TreeNode(curMax);
        TreeNode* left = Construct(nums, begin, maxIdx);
        TreeNode* right = Construct(nums, maxIdx + 1, end);
        cur->left = left;
        cur->right = right;
        return cur;
    }

    TreeNode* constructMaximumBinaryTree(std::vector<int>& nums)
    {
        return Construct(nums, 0, nums.size());
    }
};
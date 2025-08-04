#pragma once

#include <vector>
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


class Solution637
{
public:
    std::vector<double> averageOfLevels(TreeNode* root)
    {
        std::vector<double> result;
        if (!root)
            return result;

        std::queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty())
        {
            double curLevelSum = 0.0;
            int curLevelSize = queue.size();
            for (int i = 0; i < curLevelSize; i++)
            {
                TreeNode* cur = queue.front();
                queue.pop();
                curLevelSum += cur->val;
                if (cur->left)
                    queue.push(cur->left);
                if (cur->right)
                    queue.push(cur->right);
            }
            result.push_back(curLevelSum / curLevelSize);
        }
        
        return result;
    }
};
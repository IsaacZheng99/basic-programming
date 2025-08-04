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


class Solution107
{
public:
    std::vector<std::vector<int>> levelOrderBottom(TreeNode* root)
    {
        std::vector<std::vector<int>> result;
        if (!root)
            return result;
        
        std::queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty())
        {
            std::vector<int> curLevel;
            int cueLevelSize = queue.size();
            for (int i = 0; i < cueLevelSize; i++)
            {
                TreeNode* cur = queue.front();
                queue.pop();
                curLevel.push_back(cur->val);
                if (cur->left)
                    queue.push(cur->left);
                if (cur->right)
                    queue.push(cur->right);
            }
            result.push_back(curLevel);
        }

        std::reverse(result.begin(), result.end());
        return result;
    }
};
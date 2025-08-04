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


class Solution515
{
public:
    std::vector<int> largestValues(TreeNode* root)
    {
        std::vector<int> result;
        std::queue<TreeNode*> queue;
        if (root)
            queue.push(root);

        while (!queue.empty())
        {
            int curLevelSize = queue.size();
            int curMax = INT_MIN;
            for (int i = 0; i < curLevelSize; i++)
            {
                TreeNode* cur = queue.front();
                queue.pop();
                curMax = cur->val > curMax ? cur->val : curMax;
                if (cur->left)
                    queue.push(cur->left);
                if (cur->right)
                    queue.push(cur->right);
            }
            result.push_back(curMax);
        }

        return result;
    }
};

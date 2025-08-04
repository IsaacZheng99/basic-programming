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



class Solution513
{
public:
    void Traverse(TreeNode* cur, int depth)
    {
        if (cur == nullptr)
            return;
        if (cur->left == nullptr && cur->right == nullptr && depth > m_MaxDepth)
        {
            m_MaxDepth = depth;
            m_Result = cur->val;
        }
        Traverse(cur->left, depth + 1);
        Traverse(cur->right, depth + 1);
    }

    int findBottomLeftValue(TreeNode* root)
    {
        Traverse(root, 0);
        return m_Result;
    }
private:
    int m_MaxDepth = INT_MIN;
    int m_Result;
};


class Solution513
{
public:
    int findBottomLeftValue(TreeNode* root)
    {
        std::queue<TreeNode*> queue;
        if (root)
            queue.push(root);
        int result = 0;

        while (!queue.empty())
        {
            int curLevelSize = queue.size();
            for (int i = 0; i < curLevelSize; i++)
            {
                TreeNode* cur = queue.front();
                queue.pop();

                if (i == 0)
                    result = cur->val;

                if (cur->left)
                    queue.push(cur->left);
                if (cur->right)
                    queue.push(cur->right);
            }
        }
        return result;
    }
};
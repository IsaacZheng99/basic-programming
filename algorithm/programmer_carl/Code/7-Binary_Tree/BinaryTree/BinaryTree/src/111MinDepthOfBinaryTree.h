#pragma once

#include <queue>
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


class Solution111
{
public:
    int minDepth(TreeNode* root)
    {
        if (!root)
            return 0;

        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);
        
        if (root->left && !root->right)
            return 1 + leftDepth;
        else if (!root->left && root->right)
            return 1 + rightDepth;
        else
            return std::min(1 + leftDepth, 1 + rightDepth);
    }
};


//class Solution111
//{
//public:
//    int minDepth(TreeNode* root)
//    {
//        int depth = 0;
//        std::queue<TreeNode*> queue;
//        if (root)
//            queue.push(root);
//
//        while (!queue.empty())
//        {
//            depth += 1;
//
//            int curLevelSize = queue.size();
//            for (int i = 0; i < curLevelSize; i++)
//            {
//                TreeNode* cur = queue.front();
//                queue.pop();
//                if (!cur->left && !cur->right)
//                    return depth;
//                else
//                {
//                    if (cur->left)
//                        queue.push(cur->left);
//                    if (cur->right)
//                        queue.push(cur->right);
//                }
//            }
//
//        }
//
//        return depth;
//    }
//};
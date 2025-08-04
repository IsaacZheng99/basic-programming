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


class Solution104
{
public:
    int CalDepth(TreeNode* cur, int depth)
    {
        if (!cur)
            return depth;

        depth += 1;

        return std::max(CalDepth(cur->left, depth), CalDepth(cur->right, depth));
    }


    int maxDepth(TreeNode* root)
    {
        int depth = 0;
        return CalDepth(root, depth);
    }
};


//class Solution104
//{
//public:
//    int maxDepth(TreeNode* root)
//    {
//        int depth = 0;
//        std::queue<TreeNode*> queue;
//        if (root)
//            queue.push(root);
//
//        while (!queue.empty())
//        {
//            depth += 1;
//            int curLevelSize = queue.size();
//            for (int i = 0; i < curLevelSize; i++)
//            {
//                TreeNode* cur = queue.front();
//                queue.pop();
//                if (cur->left)
//                    queue.push(cur->left);
//                if (cur->right)
//                    queue.push(cur->right);
//            }
//        }
//
//        return depth;
//    }
//};

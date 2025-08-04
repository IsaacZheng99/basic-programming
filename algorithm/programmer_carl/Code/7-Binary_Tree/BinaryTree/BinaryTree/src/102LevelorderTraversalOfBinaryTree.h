#pragma once

#include <iostream>
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


//class Solution102
//{
//public:
//
//    void Traverse(TreeNode* cur, std::vector<std::vector<int>>& result, int depth)
//    {
//        if (!cur)
//            return;
//        
//        if (result.size() == depth)
//            result.push_back(std::vector<int>());
//        result[depth].push_back(cur->val);
//        Traverse(cur->left, result, depth + 1);
//        Traverse(cur->right, result, depth + 1);
//    }
//
//    std::vector<std::vector<int>> levelOrder(TreeNode* root)
//    {
//        std::vector<std::vector<int>> result;
//        int depth = 0;
//        Traverse(root, result, depth);
//        return result;
//    }
//};


//class Solution102
//{
//public:
//    std::vector<std::vector<int>> levelOrder(TreeNode* root)
//    {
//        std::vector<std::vector<int>> result;
//        if (root == nullptr)
//            return result;
//        
//        std::queue<TreeNode*> queue;
//        queue.push(root);
//        while (!queue.empty())
//        {
//            std::vector<int> curLevel;
//            int curLevelSize = queue.size();
//            for (int i = 0; i < curLevelSize; i++)
//            {
//                TreeNode* cur = queue.front();
//                queue.pop();
//                curLevel.push_back(cur->val);
//                if (cur->left)
//                    queue.push(cur->left);
//                if (cur->right)
//                    queue.push(cur->right);
//            }
//
//            result.push_back(curLevel);
//        }
//
//        return result;
//    }
//};
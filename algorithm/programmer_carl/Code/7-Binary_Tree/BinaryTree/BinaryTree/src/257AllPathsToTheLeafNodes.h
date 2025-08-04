#pragma once

#include <vector>
#include <string>


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
    void DFS(TreeNode* cur, std::vector<int>& curPathValues, std::vector<std::string>& result)
    {
        curPathValues.push_back(cur->val);

        if (cur->left == nullptr && cur->right == nullptr)
        {
            std::string curPath;
            for (int i = 0; i < curPathValues.size(); i++)
            {
                curPath += std::to_string(curPathValues[i]);
                if (i != curPathValues.size() - 1)
                    curPath += "->";
            }
            result.push_back(curPath);
            return;
        }

        if (cur->left)
        {
            DFS(cur->left, curPathValues, result);
            curPathValues.pop_back();
        }
        if (cur->right)
        {
            DFS(cur->right, curPathValues, result);
            curPathValues.pop_back();
        }
    }


    std::vector<std::string> binaryTreePaths(TreeNode* root)
    {
        std::vector<std::string> result;
        if (root == nullptr)
            return result;

        std::vector<int> curPathValues;
        DFS(root, curPathValues, result);

        return result;
    }
};
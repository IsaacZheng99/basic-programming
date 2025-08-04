#pragma once

#include <vector>
#include <stack>


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


class Solution501
{
public:
    std::vector<int> findMode(TreeNode* root)
    {
        std::vector<int> result;
        int curMaxCount = 0;
        int curCount = 0;
        TreeNode* pre = nullptr;

        std::stack<TreeNode*> stack;
        TreeNode* cur = root;
        while (cur || !stack.empty())
        {
            if (cur)
            {
                stack.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = stack.top();
                stack.pop();

                if (pre == nullptr)
                    curCount = 1;
                else if (cur->val == pre->val)
                    curCount += 1;
                else
                    curCount = 1;


                if (curCount > curMaxCount)
                {
                    result.clear();
                    result.push_back(cur->val);
                    curMaxCount = curCount;
                }
                else if (curCount == curMaxCount)
                    result.push_back(cur->val);

                pre = cur;
                cur = cur->right;
            }
        }

        return result;
    }
};


class Solution501
{
public:
    void Traverse(TreeNode* cur, std::vector<int>& result, int& curMaxCount, int& curCount, TreeNode*& pre)
    {
        if (cur == nullptr)
            return;

        Traverse(cur->left, result, curMaxCount, curCount, pre);

        if (pre == nullptr)
            curCount = 1;
        else if (cur->val == pre->val)
            curCount += 1;
        else
            curCount = 1;

        pre = cur;

        if (curCount > curMaxCount)
        {
            result.clear();
            result.push_back(cur->val);
            curMaxCount = curCount;
        }
        else if (curCount == curMaxCount)
            result.push_back(cur->val);

        Traverse(cur->right, result, curMaxCount, curCount, pre);
    }

    std::vector<int> findMode(TreeNode* root)
    {
        std::vector<int> result;
        int curMaxCount = 0;
        int curCount = 0;
        TreeNode* pre = nullptr;
        Traverse(root, result, curMaxCount, curCount, pre);
        
        return result;
    }
};
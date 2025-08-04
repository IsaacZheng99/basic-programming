#pragma once


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution235
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        TreeNode* cur = root;
        
        while (cur)
        {
            if (cur->val > p->val && cur->val > q->val)
                cur = cur->left;
            else if (cur->val < p->val && cur->val < q->val)
                cur = cur->right;
            else
                return cur;
        }

        return nullptr;
    }
};


class Solution235
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root == nullptr)
            return nullptr;

        if (root->val >= p->val && root->val <= q->val || root->val <= p->val && root->val >= q->val)
            return root;

        else if (root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);

        else
            return lowestCommonAncestor(root->right, p, q);
    }
};


//class Solution235
//{
//public:
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
//    {
//        if (root == p || root == q || root == nullptr)
//            return root;
//
//        TreeNode* left = nullptr;
//        TreeNode* right = nullptr;
//        if (root->val > p->val && root->val > q->val)
//            left = lowestCommonAncestor(root->left, p, q);
//        else if (root->val < p->val && root->val < q->val)
//            right = lowestCommonAncestor(root->right, p, q);
//        else
//        {
//            left = lowestCommonAncestor(root->left, p, q);
//            right = lowestCommonAncestor(root->right, p, q);
//        }
//
//        if (left && right)
//            return root;
//        else if (left)
//            return left;
//        else if (right)
//            return right;
//
//
//        return nullptr;
//    }
//};
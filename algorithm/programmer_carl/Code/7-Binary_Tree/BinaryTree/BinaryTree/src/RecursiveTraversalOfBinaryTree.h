#pragma once

#include <iostream>
#include <vector>


struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val)
		: val(val), left(NULL), right(NULL) {}
};


// Leetcode 144
void PreorderTraversal(TreeNode* cur, std::vector<int>& nodes)
{
	if (cur == nullptr)
		return;
	nodes.push_back(cur->val);
	PreorderTraversal(cur->left, nodes);
	PreorderTraversal(cur->right, nodes);
}


// Leetcode 145
void PostorderTraversal(TreeNode* cur, std::vector<int>& nodes)
{
	if (cur == nullptr)
		return;
	PostorderTraversal(cur->left, nodes);
	PostorderTraversal(cur->right, nodes);
	nodes.push_back(cur->val);
}


// Leetcode 94
void InorderTraversal(TreeNode* cur, std::vector<int>& nodes)
{
	if (cur == nullptr)
		return;
	InorderTraversal(cur->left, nodes);
	nodes.push_back(cur->val);
	InorderTraversal(cur->right, nodes);
}
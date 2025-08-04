#pragma once

#include <iostream>
#include <stack>
#include <vector>


struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val)
		: val(val), left(NULL), right(NULL) {
	}
};


// Leetcode 144
void PreorderTraversal(TreeNode* root)
{
	std::stack<TreeNode*> stack;
	if (root)
		stack.push(root);
	std::vector<int> result;

	while (!stack.empty())
	{
		TreeNode* cur = stack.top();
		stack.pop();
		if (cur)
		{
			if (cur->right)
				stack.push(cur->right);
			if (cur->left)
				stack.push(cur->left);
			stack.push(cur);
			stack.push(nullptr);
		}
		else
		{
			cur = stack.top();
			stack.pop();
			result.push_back(cur->val);
		}
	}
}


// Leetcode 145
void PostorderTraversal(TreeNode* root)
{
	std::stack<TreeNode*> stack;
	if (root)
		stack.push(root);
	std::vector<int> result;

	while (!stack.empty())
	{
		TreeNode* cur = stack.top();
		stack.pop();
		if (cur)
		{
			stack.push(cur);
			stack.push(nullptr);
			if (cur->right)
				stack.push(cur->right);
			if (cur->left)
				stack.push(cur->left);
		}
		else
		{
			cur = stack.top();
			stack.pop();
			result.push_back(cur->val);
		}
	}
}


// Leetcode 94
void InorderTraversal(TreeNode* root)
{
	std::stack<TreeNode*> stack;
	if (root)
		stack.push(root);
	std::vector<int> result;

	while (!stack.empty())
	{
		TreeNode* cur = stack.top();
		stack.pop();
		if (cur)
		{
			if (cur->right)
				stack.push(cur->right);
			stack.push(cur);
			stack.push(nullptr);
			if (cur->left)
				stack.push(cur->left);
		}
		else
		{
			cur = stack.top();
			stack.pop();
			result.push_back(cur->val);
		}
	}
}

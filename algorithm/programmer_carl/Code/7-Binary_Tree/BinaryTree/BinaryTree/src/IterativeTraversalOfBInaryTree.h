#pragma once

#include <iostream>
#include <vector>
#include <stack>


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
	stack.push(root);
	std::vector<int> result;

	while (!stack.empty())
	{
		TreeNode* cur = stack.top();
		stack.pop();
		if (cur == nullptr)
			continue;

		result.push_back(cur->val);

		stack.push(cur->right);
		stack.push(cur->left);
	}
}


// Leetcode 145
void PostorderTraversal(TreeNode* root)
{
	std::stack<TreeNode*> stack;
	stack.push(root);
	std::vector<int> result;

	while (!stack.empty())
	{
		TreeNode* cur = stack.top();
		stack.pop();
		if (cur == nullptr)
			continue;
		result.push_back(cur->val);
		stack.push(cur->left);
		stack.push(cur->right);
	}

	std::reverse(result.begin(), result.end());
}


// Leetcode 94
void InorderTraversal(TreeNode* root)
{
	std::stack<TreeNode*> stack;
	std::vector<int> result;

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
			result.push_back(cur->val);
			stack.pop();
			cur = cur->right;
		}
	}
}

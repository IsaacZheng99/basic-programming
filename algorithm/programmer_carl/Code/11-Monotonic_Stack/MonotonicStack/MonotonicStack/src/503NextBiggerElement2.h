#pragma once

#include <vector>
#include <stack>
#include <algorithm>


class Solution503
{
public:
    std::vector<int> nextGreaterElements(std::vector<int>&nums)
    {
        std::vector<int> result(nums.size(), -1);

        std::stack<int> stack;
        
        for (int i = 0; i < nums.size() * 2 - 1; i++)
        {
            while (!stack.empty() && nums[stack.top() % nums.size()] < nums[i % nums.size()])
            {
                int curTopIndex = stack.top() % nums.size();
                stack.pop();
                result[curTopIndex] = nums[i % nums.size()];
            }

            stack.push(i);
        }

        return result;
    }
};
#pragma once

#include <vector>
#include <stack>
#include <algorithm>


class Solution496
{
public:
    std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        std::vector<int> result(nums1.size(), -1);

        std::stack<int> stack;

        for (int i = 0; i < nums2.size(); i++)
        {
            while (!stack.empty() && nums2[i] > stack.top())
            {
                int curTopVal = stack.top();
                stack.pop();

                auto it = std::find(nums1.begin(), nums1.end(), curTopVal);
                if (it != nums1.end())
                {
                    result[it - nums1.begin()] = nums2[i];
                }
            }

            stack.push(nums2[i]);
        }

        return result;
    }
};
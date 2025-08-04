#pragma once

#include <vector>
#include <algorithm>


class Solution53
{
public:
    int maxSubArray(std::vector<int>& nums)
    {
        int result = nums[0];
        int curSum = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] >= curSum + nums[i])
                curSum = nums[i];
            else
                curSum = curSum + nums[i];

            result = std::max(result, curSum);
        }

        return result;
    }
};
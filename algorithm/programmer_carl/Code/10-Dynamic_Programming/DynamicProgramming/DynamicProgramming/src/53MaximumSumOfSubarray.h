#pragma once

#include <vector>


class Solution53
{
public:
    int maxSubArray(std::vector<int>& nums)
    {
        int result = nums[0];

        std::vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = std::max(nums[i], dp[i - 1] + nums[i]);
            result = std::max(result, dp[i]);
        }

        return result;
    }
};
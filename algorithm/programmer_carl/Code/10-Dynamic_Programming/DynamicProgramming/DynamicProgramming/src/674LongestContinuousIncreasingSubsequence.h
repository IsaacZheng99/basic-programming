#pragma once

#include <vector>
#include <algorithm>


class Solution674
{
public:
    int findLengthOfLCIS(std::vector<int>& nums)
    {
        std::vector<int> dp(nums.size(), 1);
        int result = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
                dp[i] = dp[i - 1] + 1;

            result = std::max(result, dp[i]);
        }

        return result;
    }
};
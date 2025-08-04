#pragma once

#include <vector>


class Solution377
{
public:
    int combinationSum4(std::vector<int>& nums, int target)
    {
        std::vector<uint64_t> dp(target + 1, 0);
        dp[0] = 1;
        for (int j = 0; j <= target; j++)
            for (int i = 0; i < nums.size(); i++)
            {
                if (j >= nums[i])
                    dp[j] += dp[j - nums[i]];
            }

        return dp[target];
    }
};
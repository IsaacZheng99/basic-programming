#pragma once

#include <vector>
#include <numeric>
#include <algorithm>


class Solution416
{
public:
    bool canPartition(std::vector<int>& nums)
    {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1)
            return false;
        int target = sum / 2;

        std::vector<int> dp(target + 1, 0);

        for (int i = 0; i < nums.size(); i++)
            for (int j = target; j >= 1; j--)
            {
                if (j >= nums[i])
                    dp[j] = std::max(dp[j], dp[j - nums[i]] + nums[i]);
            }

        if (dp[target] == target)
            return true;
        return false;
    }
};


class Solution416
{
public:
    bool canPartition(std::vector<int>& nums)
    {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1)
            return false;
        int target = sum / 2;

        std::vector<std::vector<int>> dp(nums.size(), std::vector<int>(target + 1, 0));

        for (int i = nums[0]; i <= target; i++)
            dp[0][i] = nums[0];

        for (int i = 1; i < nums.size(); i++)
            for (int j = 1; j <= target; j++)
            {
                if (j < nums[i])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i]);
            }

        if (dp[nums.size() - 1][target] == target)
            return true;
        return false;
    }
};

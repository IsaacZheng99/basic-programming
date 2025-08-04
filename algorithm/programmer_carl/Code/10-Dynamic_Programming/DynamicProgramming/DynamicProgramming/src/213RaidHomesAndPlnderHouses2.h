#pragma once

#include <vector>
#include <algorithm>


class Solution213
{
public:
    int robRange(std::vector<int>& nums, int begin, int end)
    {
        if (end - begin == 0)
            return nums[begin];
        std::vector<int> dp(end - begin + 1, 0);
        dp[0] = nums[begin];
        dp[1] = std::max(nums[begin], nums[begin + 1]);

        for (int i = 2; i < dp.size(); i++)
            dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[begin + i]);

        return dp[end - begin];
    }

    int rob(std::vector<int>& nums)
    {
        if (nums.size() == 1)
            return nums[0];

        int result1 = robRange(nums, 0, nums.size() - 2);
        int result2 = robRange(nums, 1, nums.size() - 1);

        return std::max(result1, result2);
    }
};


class Solution213
{
public:
    int rob(std::vector<int>& nums)
    {
        if (nums.size() == 1)
            return nums[0];

        std::vector<int> dp0(nums.size(), 0);
        std::vector<int> dp1(nums.size(), 0);
        dp0[0] = nums[0];
        dp0[1] = nums[0];
        dp1[0] = 0;
        dp1[1] = nums[1];
        
        for (int i = 2; i < nums.size(); i++)
        {
            if (i == nums.size() - 1)
                dp0[i] = dp0[i - 1];
            else
                dp0[i] = std::max(dp0[i - 1], dp0[i - 2] + nums[i]);
            dp1[i] = std::max(dp1[i - 1], dp1[i - 2] + nums[i]);
        }

        return std::max(dp0[nums.size() - 1], dp1[nums.size() - 1]);
    }
};
#pragma once

#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>


class Solution494
{
public:
    int findTargetSumWays(std::vector<int>& nums, int target)
    {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);

        if (sum < std::abs(target))
            return 0;

        if ((sum + target) % 2 == 1)
            return 0;

        int left = (sum + target) / 2;
        std::vector<std::vector<int>> dp(nums.size(), std::vector<int>(left + 1, 0));
        if (nums[0] <= left)
            dp[0][nums[0]] = 1;
        if (nums[0] == 0)
            dp[0][0] = 2;
        else
            dp[0][0] = 1;


        for (int i = 1; i < nums.size(); i++)  // traverse from 1
            for (int j = 0; j <= left; j++)
            {
                if (j >= nums[i])
                    dp[i][j] = dp[i - 1][j - nums[i]] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }

        return dp[nums.size() - 1][left];
    }
};


class Solution494
{
public:
    int findTargetSumWays(std::vector<int>& nums, int target)
    {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);

        if (sum < std::abs(target))
            return 0;

        if ((sum + target) % 2 == 1)
            return 0;

        int left = (sum + target) / 2;
        std::vector<int> dp(left + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++)  // traverse from 0
            for (int j = left; j >= 0; j--)
            {
                if (j >= nums[i])
                    dp[j] += dp[j - nums[i]];
            }

        return dp[left];
    }
};


//class Solution494
//{
//public:
//    int findTargetSumWays(std::vector<int>& nums, int target)
//    {
//        int sum = std::accumulate(nums.begin(), nums.end(), 0);
//
//        if (target < -sum)
//            return 0;
//
//		  // initially, we take all the elements as -nums[i] and take this state as dp[0]
//        target = target + sum;
//
//        std::vector<int> dp(target + 1);
//        dp[0] = 1;
//
//        for (int i = 0; i < nums.size(); i++)
//            for (int j = target; j >= 0; j--)
//            {
//				  // each time we make one element be nums[i] and the difference is nums[i] - (-nums[i]) = 2 * nums[i]
//                if (j >= 2 * nums[i])
//                    dp[j] += dp[j - 2 * nums[i]];
//            }
//
//        return dp[target];
//    }
//};

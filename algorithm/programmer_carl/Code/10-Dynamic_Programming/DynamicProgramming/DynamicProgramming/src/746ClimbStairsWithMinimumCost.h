#pragma once

#include <vector>
#include <algorithm>


class Solution746
{
public:
    int minCostClimbingStairs(std::vector<int>& cost)
    {
        std::vector<int> dp;
        int size = cost.size();
        dp.reserve(size + 1);
        dp[0] = 0;
        dp[1] = 0;

        for (int i = 2; i < size + 1; i++)
            dp[i] = std::min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);

        return dp[size];
    }
};
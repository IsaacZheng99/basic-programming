#pragma once

#include <vector>
#include <numeric>
#include <algorithm>


class Solution1049
{
public:
    int lastStoneWeightII(std::vector<int>& stones)
    {
        int sum = std::accumulate(stones.begin(), stones.end(), 0);
        int target = sum / 2;

        std::vector<int> dp(target + 1, 0);
        for (int i = 0; i < stones.size(); i++)
            for (int j = target; j >= 1; j--)
            {
                if (j >= stones[i])
                    dp[j] = std::max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        return std::abs(sum - 2 * dp[target]);
    }
};

#pragma once

#include <vector>


class Solution322
{
public:
    int coinChange(std::vector<int>& coins, int amount)
    {
        std::vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        
        for (int i = 0; i < coins.size(); i++)
            for (int j = 0; j <= amount; j++)
            {
                if (j >= coins[i])
                {
                    if (dp[j - coins[i]] == INT_MAX)
                        continue;
                     dp[j] = std::min(dp[j], dp[j - coins[i]] + 1);
                }
            }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
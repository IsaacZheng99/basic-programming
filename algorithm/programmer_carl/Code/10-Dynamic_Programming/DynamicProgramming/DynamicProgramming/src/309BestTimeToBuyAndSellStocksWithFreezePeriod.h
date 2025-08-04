#pragma once

#include <vector>


class Solution
{
public:
    int maxProfit(std::vector<int>& prices)
    {
        // 0 chiyou
        // 1 dangtianmaichu
        // 2 baochibuchiyou
        std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(3, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = 0;

        for (int i = 1; i < prices.size(); i++)
        {
            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
            dp[i][1] = dp[i - 1][0] + prices[i];
            dp[i][2] = std::max(dp[i - 1][2], dp[i - 1][1]);
        }

        return std::max(dp[prices.size() - 1][1], dp[prices.size() - 1][2]);
    }
};
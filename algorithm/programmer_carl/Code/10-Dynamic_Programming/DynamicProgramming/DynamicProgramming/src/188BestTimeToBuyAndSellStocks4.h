#pragma once

#include <vector>


class Solution188
{
public:
    int maxProfit(int k, std::vector<int>& prices)
    {
        std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(k * 2, 0));
        for (int i = 0; i < 2 * k; i++)
        {
            if (i % 2 == 1)
                dp[0][i] = 0;
            else
                dp[0][i] = -prices[0];
        }

        for (int i = 1; i < prices.size(); i++)
            for (int j = 0; j < 2 * k; j++)
            {
                if (j == 0)
                    dp[i][j] = std::max(dp[i - 1][j], -prices[i]);
                else if (j % 2 == 1)
                    dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - 1] + prices[i]);
                else
                    dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
            }

        int result = INT_MIN;
        for (int i = 1; i < 2 * k; i += 2)
            result = std::max(result, dp[prices.size() - 1][i]);
        
        return result;
    }
};
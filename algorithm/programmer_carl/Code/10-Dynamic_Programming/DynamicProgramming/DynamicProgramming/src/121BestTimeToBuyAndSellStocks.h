#pragma once

#include <vector>


class Solution121
{
public:
    int maxProfit(std::vector<int>& prices)
    {
        std::vector<int> dp(2, 0);
        dp[0] = -prices[0];
        dp[1] = 0;

        for (int i = 1; i < prices.size(); i++)
        {
            dp[1] = std::max(dp[1], dp[0] + prices[i]);
            dp[0] = std::max(dp[0], -prices[i]);
        }

        return dp[1];
    }
};

class Solution121
{
public:
    int maxProfit(std::vector<int>& prices)
    {
        std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(2, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;

        for (int i = 1; i < prices.size(); i++)
        {
            dp[i][0] = std::max(dp[i - 1][0], -prices[i]);
            dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }

        return dp[prices.size() - 1][1];
    }
};


class Solution121
{
public:
    int maxProfit(std::vector<int>& prices)
    {
        int dp = 0;
        int curMin = prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > curMin)
                dp = std::max(dp, prices[i] - curMin);
            else
                curMin = prices[i];
        }

        return dp;
    }
};


class Solution121
{
public:
    int maxProfit(std::vector<int>& prices)
    {
        std::vector<int> dp(prices.size(), 0);
        int curMin = prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > curMin)
                dp[i] = std::max(dp[i - 1], prices[i] - curMin);
            else
            {
                dp[i] = dp[i - 1];
                curMin = prices[i];
            }
        }

        return dp[prices.size() - 1];
    }
};
#pragma once

#include <iostream>
#include <vector>


class Solution518
{
public:
    void PrintDP(std::vector<std::vector<uint64_t>>& dp)
    {
        for (int i = 0; i < dp.size(); i++)
        {
            for (int j = 0; j < dp[0].size(); j++)
            {
                std::cout << dp[i][j]<<",";
            }
            std::cout << std::endl;
        }
    }

    int change(int amount, std::vector<int>& coins)
    {
        std::vector<std::vector<uint64_t>> dp(coins.size(), std::vector<uint64_t>(amount + 1, 0));
        
        for (int i = 0; i < coins.size(); i++)
            dp[i][0] = 1;

        for (int i = 0; i <= amount; i++)
        {
            if (i >= coins[0])
                dp[0][i] = dp[0][i - coins[0]];
        }

        PrintDP(dp);
        std::cout << "------------------" << std::endl;
        for (int j = 0; j <= amount; j++)
        {
            std::cout << "j: " << j << std::endl;
            for (int i = 1; i < coins.size(); i++)
            {
                if (j >= coins[i])
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i]];
                else
                    dp[i][j] = dp[i - 1][j];
            }
            PrintDP(dp);
            std::cout << "------------------" << std::endl;

        }

        return dp[coins.size() - 1][amount];
    }
};


class Solution518
{
public:
    void PrintDP(std::vector<uint64_t>& dp)
    {
        for (int i = 0; i < dp.size(); i++)
            std::cout << dp[i] << ", ";
        std::cout << std::endl;
    }

    int change(int amount, std::vector<int>& coins)
    {
        std::vector<uint64_t> dp(amount + 1, 0);
        dp[0] = 1;
        PrintDP(dp);
        std::cout << "----------------" << std::endl;
        for (int i = 0; i < coins.size(); i++)
        {
            std::cout << "i: " << i << std::endl;
            for (int j = 0; j <= amount; j++)
            {
                if (j >= coins[i])
                    dp[j] += dp[j - coins[i]];
            }
            PrintDP(dp);
            std::cout << "----------------" << std::endl;

        }

        return dp[amount];
    }
};

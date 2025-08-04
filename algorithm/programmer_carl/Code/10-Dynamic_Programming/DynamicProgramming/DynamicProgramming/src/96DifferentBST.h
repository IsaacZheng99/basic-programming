#pragma once

#include <vector>


class Solution96
{
public:
    int numTrees(int n)
    {
        std::vector<int> dp(n + 1);
        dp[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
                    dp[i] += dp[j - 1] * dp[i - j];
        }

        return dp[n];
    }
};


class Solution96
{
public:
    int numTrees(int n)
    {
        if (n <= 2)
            return n;

        std::vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                if (j == 1 || j == i)
                    dp[i] += dp[i - 1];
                else
                    dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        
        return dp[n];
    }
};
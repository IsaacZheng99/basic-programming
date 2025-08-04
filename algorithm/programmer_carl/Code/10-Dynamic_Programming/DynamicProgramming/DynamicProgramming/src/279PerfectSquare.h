#pragma once

#include <vector>
#include <cmath>


class Solution279
{
public:
    int numSquares(int n)
    {
        std::vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= std::sqrt(n); i++)
            for (int j = 1; j <= n; j++)
            {
                if (j >= i * i)
                    dp[j] = std::min(dp[j], dp[j - i * i] + 1);
            }

        return dp[n];
    }
};
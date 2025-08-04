#pragma once

#include <vector>
#include <algorithm>


class Solution343
{
public:
    int integerBreak(int n)
    {
        if (n == 2)
            return 1;

        std::vector<int> dp(n + 1);
        dp[2] = 1;

        for (int i = 3; i <= n; i++)
        {
            for (int j = 1; j < i - 1; j++)
                dp[i] = std::max({ dp[i],
                                   dp[j] * dp[i - j],
                                   dp[j] * (i - j),
                                   j * dp[i - j],
                                   j * (i - j) });
        }

        return dp[n];
    }
};
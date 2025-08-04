#pragma once

#include <string>
#include <vector>
#include <algorithm>


class Solution
{
public:
    int longestPalindromeSubseq(std::string s)
    {
        std::vector<std::vector<int>> dp(s.size(), std::vector<int>(s.size(), 0));

        for (int i = s.size() - 1; i >= 0; i--)
            for (int j = i; j < s.size(); j++)
            {
                if (s[i] == s[j])
                {
                    if (j - i <= 1)
                        dp[i][j] = j - i + 1;
                    else
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else
                {
                    dp[i][j] = std::max(dp[i + 1][j], dp[i][j - 1]);
                }
            }

        return dp[0][s.size() - 1];
    }
};
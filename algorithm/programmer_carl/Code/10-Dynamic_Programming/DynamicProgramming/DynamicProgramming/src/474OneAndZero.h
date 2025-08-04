#pragma once

#include <vector>
#include <string>
#include <algorithm>


class Solution474
{
public:
    std::pair<int, int> GetNumZeroAndOne(std::string& str)
    {
        int numZero = 0;
        int numOne = 0;
        for (char c : str)
        {
            if (c == '0')
                numZero += 1;
            else if (c == '1')
                numOne += 1;
        }

        return { numZero, numOne };
    }

    int findMaxForm(std::vector<std::string>& strs, int m, int n)
    {
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
        auto [numZero, numOne] = GetNumZeroAndOne(strs[0]);

        for (int i = 0; i < strs.size(); i++)
            for (int j = m; j >= 0; j--)
                for (int k = n; k >= 0; k--)
                {
                    auto [numZero, numOne] = GetNumZeroAndOne(strs[i]);
                    if (j >= numZero && k >= numOne)
                        dp[j][k] = std::max(dp[j][k], dp[j - numZero][k - numOne] + 1);
                    else
                        dp[j][k] = dp[j][k];
                }

        return dp[m][n];
    }
};


class Solution474
{
public:
    std::pair<int, int> GetNumZeroAndOne(std::string& str)
    {
        int numZero = 0;
        int numOne = 0;
        for (char c : str)
        {
            if (c == '0')
                numZero += 1;
            else if (c == '1')
                numOne += 1;
        }

        return { numZero, numOne };
    }

    int findMaxForm(std::vector<std::string>& strs, int m, int n)
    {
        std::vector<std::vector<std::vector<int>>> dp(strs.size(),
            std::vector<std::vector<int>>(m + 1, std::vector<int>(n + 1, 0)));
        auto [numZero, numOne] = GetNumZeroAndOne(strs[0]);
        for (int i = numZero; i <= m; i++)
            for (int j = numOne; j <= n; j++)
                dp[0][i][j] = 1;

        for (int i = 1; i < strs.size(); i++)
            for (int j = 0; j <= m; j++)
                for (int k = 0; k <= n; k++)
                {
                    auto [numZero, numOne] = GetNumZeroAndOne(strs[i]);
                    if (j >= numZero && k >= numOne)
                        dp[i][j][k] = std::max(dp[i - 1][j][k], dp[i - 1][j - numZero][k - numOne] + 1);
                    else
                        dp[i][j][k] = dp[i - 1][j][k];
                }

        return dp[strs.size() - 1][m][n];
    }
};

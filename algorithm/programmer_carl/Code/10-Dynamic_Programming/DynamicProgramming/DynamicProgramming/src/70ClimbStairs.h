#pragma once

#include <vector>


class Solution70
{
public:
    int climbStairs(int n)
    {
        if (n <= 2)
            return n;

        int num1 = 1;
        int num2 = 2;

        for (int i = 3; i <= n; i++)
        {
            int temp = num2;
            num2 += num1;
            num1 = temp;
        }

        return num2;
    }
};

class Solution70
{
public:
    int climbStairs(int n)
    {
        if (n <= 2)
            return n;

        std::vector<int> dp;
        dp.reserve(n + 1);
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];

        return dp[n];
    }
};
#pragma once

#include <vector>


class Solution509
{
public:
    int fib(int n)
    {
        if (n <= 1)
            return n;

        int num1 = 0;
        int num2 = 1;

        for (int i = 2; i <= n; i++)
        {
            int temp = num2;
            num2 += num1;
            num1 = temp;
        }

        return num2;
    }
};


class Solution509
{
public:
    int fib(int n)
    {
        if (n == 0)
            return 0;

        std::vector<int> dp;
        dp.reserve(n + 1);
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        
        return dp[n];
    }
};
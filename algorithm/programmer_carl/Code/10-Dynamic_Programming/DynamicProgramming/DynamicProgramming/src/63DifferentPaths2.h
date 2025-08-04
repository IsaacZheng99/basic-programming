#pragma once

#include <vector>


class Solution63
{
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        std::vector<int> dp(n);

        for (int i = 0; i < n; i++)
        {
            if (obstacleGrid[0][i] == 1)
                break;
            dp[i] = 1;
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1)
                    dp[j] = 0;
                else if (j != 0)
                    dp[j] += dp[j - 1];
            }
        }

        return dp[n - 1];
    }
};


class Solution63
{
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        std::vector<int> dp(n);

        for (int i = 0; i < n; i++)
        {
            if (obstacleGrid[0][i] == 1)
                break;
            dp[i] = 1;
        }

        for (int i = 1; i < m; i++)
        {
            if (obstacleGrid[i][0] == 1)
                dp[0] = 0;

            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1)
                    dp[j] = 0;
                else if (obstacleGrid[i - 1][j] == 1 && obstacleGrid[i][j - 1] == 1)
                    dp[j] = 0;
                else if (obstacleGrid[i - 1][j] == 1)
                    dp[j] = dp[j - 1];
                else if (obstacleGrid[i][j - 1] == 1)
                    dp[j] = dp[j];
                else
                    dp[j] += dp[j - 1];
            }
        }

        return dp[n - 1];
    }
};


class Solution63
{
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        std::vector<std::vector<int>> dp(m, std::vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            if (obstacleGrid[0][i] == 1)
                break;
            dp[0][i] = 1;
        }
        for (int i = 0; i < m; i++)
        {
            if (obstacleGrid[i][0] == 1)
                break;
            dp[i][0] = 1;
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1)
                    continue;
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};


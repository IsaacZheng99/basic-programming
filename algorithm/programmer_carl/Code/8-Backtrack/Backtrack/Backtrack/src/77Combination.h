#pragma once

#include <vector>


class Solution
{
public:
    void Backtracking(int begin, int n, int k, std::vector<int>& curNums, std::vector<std::vector<int>>& result)
    {
        if (curNums.size() == k)
        {
            result.push_back(curNums);
            return;
        }
        for (int i = begin; i <= n - k + curNums.size() + 1; i++)
        {
            curNums.push_back(i);
            Backtracking(i + 1, n, k, curNums, result);
            curNums.pop_back();
        }
    }

    std::vector<std::vector<int>> combine(int n, int k)
    {
        std::vector<std::vector<int>> result;
        std::vector<int> curNums;
        Backtracking(1, n, k, curNums, result);
        return result;
    }
};

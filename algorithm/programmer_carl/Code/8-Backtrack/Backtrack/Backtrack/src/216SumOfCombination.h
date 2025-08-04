#pragma once

#include <vector>


class Solution
{
public:
    void Backtracking(int startIndex, int k, int n)
    {
        if (m_CurSum > n || m_CurNums.size() > k)
            return;
        if (m_CurSum == n && m_CurNums.size() == k)
        {
            m_Result.push_back(m_CurNums);
            return;
        }

        for (int i = startIndex; i <= 9 - (k - m_CurNums.size()) + 1; i++)
        {
            m_CurSum += i;
            m_CurNums.push_back(i);
            Backtracking(i + 1, k, n);
            m_CurSum -= i;
            m_CurNums.pop_back();
        }
    }

    std::vector<std::vector<int>> combinationSum3(int k, int n)
    {
        Backtracking(1, k, n);

        return m_Result;
    }
private:
    std::vector<std::vector<int>> m_Result;
    std::vector<int> m_CurNums;
    int m_CurSum = 0;
};
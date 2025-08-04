#pragma once

#include <vector>
#include <algorithm>


class Solution
{
public:
    void Backtracking(int startIndex, std::vector<int>& candidates, int target)
    {
        if (m_CurSum == target)
        {
            m_Result.push_back(m_CurNums);
            return;
        }

        for (int i = startIndex; i < candidates.size() && m_CurSum + candidates[i] <= target; i++)
        {
            if (i && i != startIndex && candidates[i] == candidates[i - 1])
                continue;
            m_CurNums.push_back(candidates[i]);
            m_CurSum += candidates[i];
            Backtracking(i + 1, candidates, target);
            m_CurNums.pop_back();
            m_CurSum -= candidates[i];
        }
    }


    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target)
    {
        std::sort(candidates.begin(), candidates.end());
        Backtracking(0, candidates, target);
        return m_Result;
    }
private:
    std::vector<std::vector<int>> m_Result;
    std::vector<int> m_CurNums;
    int m_CurSum = 0;
};
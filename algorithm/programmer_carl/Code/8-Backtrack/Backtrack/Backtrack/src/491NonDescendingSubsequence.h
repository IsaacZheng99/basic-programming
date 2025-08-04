#pragma once

#include <vector>
#include <unordered_set>


class Solution491
{
public:
    void Backtracking(int startIndex, std::vector<int>& nums)
    {
        if (m_CurNums.size() >= 2)
        {
            m_Result.push_back(m_CurNums);
        }

        std::unordered_set<int> levelNums;

        for (int i = startIndex; i < nums.size(); i++)
        {
            if (!m_CurNums.empty() && nums[i] < m_CurNums[m_CurNums.size() - 1])
                continue;
            if (levelNums.find(nums[i]) != levelNums.end())
                continue;
            levelNums.insert(nums[i]);
            m_CurNums.push_back(nums[i]);
            Backtracking(i + 1, nums);
            m_CurNums.pop_back();
        }
    }

    std::vector<std::vector<int>> findSubsequences(std::vector<int>& nums)
    {
        Backtracking(0, nums);
        return m_Result;
    }
private:
    std::vector<std::vector<int>> m_Result;
    std::vector<int> m_CurNums;
};
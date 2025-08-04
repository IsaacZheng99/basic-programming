#pragma once

#include <vector>


class Solution
{
public:
    void Backtracking(int startIndex, std::vector<int>& nums)
    {
        m_Result.push_back(m_CurNums);

        if (startIndex == nums.size())
            return;

        for (int i = startIndex; i < nums.size(); i++)
        {
            m_CurNums.push_back(nums[i]);
            Backtracking(i + 1, nums);
            m_CurNums.pop_back();
        }
    }

    std::vector<std::vector<int>> subsets(std::vector<int>& nums)
    {
        Backtracking(0, nums);
        return m_Result;
    }
private:
    std::vector<std::vector<int>> m_Result;
    std::vector<int> m_CurNums;
};
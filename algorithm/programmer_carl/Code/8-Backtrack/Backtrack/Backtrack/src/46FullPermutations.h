#pragma once

#include <vector>


class Solution46
{
public:
    void Backtracking(std::vector<int> nums, std::vector<bool>& used)
    {
        if (m_CurNums.size() == nums.size())
        {
            m_Result.push_back(m_CurNums);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (used[i])
                continue;
            used[i] = true;
            m_CurNums.push_back(nums[i]);
            Backtracking(nums, used);
            m_CurNums.pop_back();
            used[i] = false;
        }
    }

    std::vector<std::vector<int>> permute(std::vector<int>& nums)
    {
        std::vector<bool> used(nums.size(), false);
        Backtracking(nums, used);
        return m_Result;
    }
private:
    std::vector<std::vector<int>> m_Result;
    std::vector<int> m_CurNums;
};
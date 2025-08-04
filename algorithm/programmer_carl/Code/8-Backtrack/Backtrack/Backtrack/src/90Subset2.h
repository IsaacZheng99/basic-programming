#pragma once

#include <vector>
#include <algorithm>


class Solution
{
public:
    void Backtracking(int startIndex, std::vector<int>& nums)
    {
        m_Result.push_back(m_CurNums);

        if (startIndex >= nums.size())
            return;

        for (int i = startIndex; i < nums.size(); i++)
        {
            if (i && i != startIndex && nums[i] == nums[i - 1])
                continue;

            m_CurNums.push_back(nums[i]);
            Backtracking(i + 1, nums);
            m_CurNums.pop_back();
        }
    }

    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums)
    {
        std::sort(nums.begin(), nums.end());
        Backtracking(0, nums);
        return m_Result;
    }
private:
    std::vector<std::vector<int>> m_Result;
    std::vector<int> m_CurNums;
};

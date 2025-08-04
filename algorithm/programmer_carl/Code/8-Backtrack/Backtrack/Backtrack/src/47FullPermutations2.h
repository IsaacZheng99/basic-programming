#pragma once

#include <vector>
#include <unordered_set>
#include <algorithm>


class Solution47
{
public:
    void Backtracking(std::vector<int>& nums, std::vector<bool>& used)
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
            if (i && nums[i] == nums[i - 1] && used[i - 1] == false)
                continue;

            used[i] = true;
            m_CurNums.push_back(nums[i]);
            Backtracking(nums, used);
            m_CurNums.pop_back();
            used[i] = false;
        }
    }

    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums)
    {
        std::vector<bool> used(nums.size(), false);
        std::sort(nums.begin(), nums.end());
        Backtracking(nums, used);
        return m_Result;
    }
private:
    std::vector<std::vector<int>> m_Result;
    std::vector<int> m_CurNums;
};


class Solution47
{
public:
    void Backtracking(std::vector<int>& nums, std::vector<bool>& used)
    {
        if (m_CurNums.size() == nums.size())
        {
            m_Result.push_back(m_CurNums);
            return;
        }

        std::unordered_set<int> levelUsed;

        for (int i = 0; i < nums.size(); i++)
        {
            if (used[i])
                continue;
            if (levelUsed.find(nums[i]) != levelUsed.end())
                continue;

            levelUsed.insert(nums[i]);
            used[i] = true;
            m_CurNums.push_back(nums[i]);
            Backtracking(nums, used);
            m_CurNums.pop_back();
            used[i] = false;
        }
    }

    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums)
    {
        std::vector<bool> used(nums.size(), false);
        Backtracking(nums, used);
        return m_Result;
    }
private:
    std::vector<std::vector<int>> m_Result;
    std::vector<int> m_CurNums;
};
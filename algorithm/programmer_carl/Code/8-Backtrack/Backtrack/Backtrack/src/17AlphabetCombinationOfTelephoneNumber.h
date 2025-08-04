#pragma once

#include <vector>
#include <string>
#include <unordered_map>


class Solution {
public:
    void Backtracking(int curIndex, std::string digits)
    {
        if (m_CurCharaters.size() && m_CurCharaters.size() == digits.size())
        {
            m_Result.push_back(m_CurCharaters);
            return;
        }

        for (int j = 0; j < m_Map[digits[curIndex]].size(); j++)
        {
            m_CurCharaters += m_Map[digits[curIndex]][j];
            Backtracking(curIndex + 1, digits);
            m_CurCharaters.pop_back();
        }

    }

    std::vector<std::string> letterCombinations(std::string digits)
    {
        Backtracking(0, digits);

        return m_Result;
    }
private:
    std::vector<std::string> m_Result;
    std::string m_CurCharaters;
    static std::unordered_map<char, std::string> m_Map;
};

std::unordered_map<char, std::string> Solution::m_Map =
{
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
};

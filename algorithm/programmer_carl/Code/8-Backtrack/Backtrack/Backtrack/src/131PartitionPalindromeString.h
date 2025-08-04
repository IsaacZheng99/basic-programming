#pragma once

#include <vector>
#include <string>


class Solution131
{
public:
    bool CheckPalindrome(std::string s, int left, int right)
    {
        while (left < right)
        {
            if (s[left] != s[right])
                return false;
            left += 1;
            right -= 1;
        }

        return true;
    }


    void Backtracking(int startIndex, std::string s)
    {
        if (startIndex == s.size())
        {
            m_Result.push_back(m_CurStrings);
            return;
        }
        for (int i = startIndex; i < s.size(); i++)
        {
            if (!CheckPalindrome(s, startIndex, i))
                continue;
            m_CurStrings.push_back(std::string(s.begin() + startIndex, s.begin() + i + 1));
            Backtracking(i + 1, s);
            m_CurStrings.pop_back();
        }
    }

    std::vector<std::vector<std::string>> partition(std::string s)
    {
        Backtracking(0, s);
        return m_Result;
    }
private:
    std::vector<std::vector<std::string>> m_Result;
    std::vector<std::string> m_CurStrings;
};

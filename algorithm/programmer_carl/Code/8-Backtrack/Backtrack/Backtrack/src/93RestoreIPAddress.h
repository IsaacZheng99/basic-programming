#pragma once

#include <vector>
#include <string>


class Solution93
{
public:
    bool Check(std::string s, int left, int right)
    {
        if (s[left] == '0' && right - left >= 1)
            return false;
        if (right - left >= 3)
            return false;
        int curNum = std::stoi(s.substr(left, right - left + 1));
        if (curNum < 0 || curNum > 255)
            return false;
        return true;
    }

    void Backtracking(int startIndex, std::string s)
    {
        if (m_CurIP.size() > 4)
            return;
        if (startIndex == s.size() && m_CurIP.size() == 4)
        {
            std::string curString;
            for (int i = 0; i < m_CurIP.size(); i++)
            {
                curString += m_CurIP[i];
                if (i != m_CurIP.size() - 1)
                    curString += ".";
            }
            m_Result.push_back(curString);
            return;
        }

        for (int i = startIndex; i < s.size(); i++)
        {
            if (!Check(s, startIndex, i))
                continue;
            m_CurIP.push_back(s.substr(startIndex, i - startIndex + 1));
            Backtracking(i + 1, s);
            m_CurIP.pop_back();
        }
    }

    std::vector<std::string> restoreIpAddresses(std::string s)
    {
        Backtracking(0, s);
        return m_Result;
    }
private:
    std::vector<std::string> m_Result;
    std::vector<std::string> m_CurIP;
};

#pragma once

#include <string>
#include <vector>


class Solution647
{
public:
    int countSubstrings(std::string s)
    {
        int result = 0;

        for (int i = 0; i < s.size(); i++)
        {
            result += extend(i, i, s);
            result += extend(i, i + 1, s);
        }

        return result;
    }

    int extend(int left, int right, std::string& s)
    {
        int result = 0;

        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            result += 1;
            left -= 1;
            right += 1;
        }

        return result;
    }
};


class Solution647
{
public:
    int countSubstrings(std::string s)
    {
        int result = 0;
        
        std::vector<std::vector<bool>> dp(s.size(), std::vector<bool>(s.size(), false));

        for (int i = s.size() - 1; i >= 0; i--)
            for (int j = i; j < s.size(); j++)
            {
                if (s[i] == s[j])
                {
                    if (j - i <= 1 || dp[i + 1][j - 1])
                    {
                        dp[i][j] = true;
                        result += 1;
                    }
                }
            }

        return result;
    }
};


//class Solution
//{
//public:
//    int countSubstrings(std::string s)
//    {
//        std::vector<std::vector<bool>> dp(s.size(), std::vector<bool>(s.size(), false));
//
//        for (int i = 0; i < s.size(); i++)
//            dp[i][i] = true;
//
//        for (int i = s.size() - 1; i >= 0; i--)
//            for (int j = i + 1; j < s.size(); j++)
//            {
//                if (s[i] == s[j])
//                {
//                    if (j == i + 1)
//                        dp[i][j] = true;
//                    else
//                        dp[i][j] = dp[i + 1][j - 1];
//                }
//            }
//
//        int result = 0;
//        for (int i = 0; i < s.size(); i++)
//            for (int j = 0; j < s.size(); j++)
//            {
//                if (dp[i][j])
//                    result += 1;
//            }
//
//        return result;
//    }
//};

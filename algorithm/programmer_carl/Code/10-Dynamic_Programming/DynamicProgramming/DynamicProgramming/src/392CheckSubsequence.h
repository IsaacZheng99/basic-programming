#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


class Solution392
{
public:
    bool isSubsequence(std::string s, std::string t)
    {
        std::vector<std::vector<int>> dp(s.size() + 1, std::vector<int>(t.size() + 1, 0));

        for (int i = 1; i <= s.size(); i++)
            for (int j = 1; j <= t.size(); j++)
            {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                {
                    //dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                    dp[i][j] = dp[i][j - 1];

                }
            }

        return dp[s.size()][t.size()] == s.size();
    }
};


//class Solution
//{
//public:
//    bool isSubsequence(std::string s, std::string t)
//    {
//        if (s.size() > t.size())
//            return false;
//
//        std::vector<std::vector<bool>> dp(s.size() + 1, std::vector<bool>(t.size() + 1, false));
//
//        for (int i = 0; i <= t.size(); i++)
//            dp[0][i] = true;
//
//        for (int i = 1; i <= s.size(); i++)
//            for (int j = 1; j <= t.size(); j++)
//            {
//                if (s[i - 1] == t[j - 1] && dp[i - 1][j - 1])
//                    dp[i][j] = true;
//                else
//                {
//                    for (int k = 0; k < j; k++)
//                    {
//                        if (dp[i][k])
//                        {
//                            dp[i][j] = true;
//                            break;
//                        }
//                    }
//                }
//            }
//
//        return dp[s.size()][t.size()];
//    }
//};
#pragma once

#include <string>
#include <vector>
#include <algorithm>


class Solution1143
{
public:
    int longestCommonSubsequence(std::string text1, std::string text2)
    {
        std::vector<std::vector<int>> dp(text1.size() + 1, std::vector<int>(text2.size() + 1, 0));
        for (int i = 1; i <= text1.size(); i++)
        {
            for (int j = 1; j <= text2.size(); j++)
            {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = std::max({ dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1] });
            }
        }
            
        return dp[text1.size()][text2.size()];
    }
};


//class Solution
//{
//public:
//    int longestCommonSubsequence(std::string text1, std::string text2)
//    {
//        int result = 0;
//
//        std::vector<std::vector<int>> dp(text1.size() + 1, std::vector<int>(text2.size() + 1, 0));
//        for (int i = 1; i <= text1.size(); i++)
//        {
//            for (int j = 1; j <= text2.size(); j++)
//            {
//                if (text1[i - 1] == text2[j - 1])
//                {
//                    for (int k = 1; k <= i; k++)
//                        for (int l = 1; l <= j; l++)
//                            dp[i][j] = std::max(dp[i][j], dp[k - 1][l -1] + 1);
//
//                    result = std::max(result, dp[i][j]);
//                }
//            }
//        }
//            
//        return result;
//    }
//};
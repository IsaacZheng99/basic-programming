#pragma once

#include <string>
#include <vector>


class Solution
{
public:
    bool wordBreak(std::string s, std::vector<std::string>& wordDict)
    {
        std::vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for (int j = 1; j <= s.size(); j++)
            for (int i = 0; i < wordDict.size(); i++)
            {
                if (j >= wordDict[i].size() &&
                    dp[j - wordDict[i].size()] &&
                    s.substr(j - wordDict[i].size(), wordDict[i].size()) == wordDict[i])
                    dp[j] = true;
            }

        return dp[s.size()];
    }
};
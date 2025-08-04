#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>


class Solution763
{
public:
    std::vector<int> partitionLabels(std::string s)
    {
        std::unordered_map<char, int> letterMaxPosition;

        for (int i = 0; i < s.size(); i++)
            letterMaxPosition[s[i]] = i;

        std::vector<int> result;
        int curPosition = 0;
        int preMax = 0;
        int curMax = letterMaxPosition[s[0]];

        while (curPosition <= curMax)
        {
            if (curPosition == curMax)
            {
                result.push_back(curMax - preMax + 1);
                preMax = curMax;
                curPosition += 1;
                curMax = letterMaxPosition[s[curPosition]];
            }
            else
            {
                curPosition += 1;
                curMax = std::max(curMax, letterMaxPosition[s[curPosition]]);
            }
        }

        return result;
    }
};
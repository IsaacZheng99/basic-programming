#pragma once

#include <vector>
#include <algorithm>


class Solution455
{
public:
    int findContentChildren(std::vector<int>& g, std::vector<int>& s)
    {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());

        int result = 0;
        int childIndex = 0;
        int cookieIndex = 0;
        while (childIndex < g.size() && cookieIndex < s.size())
        {
            if (s[cookieIndex] >= g[childIndex])
            {
                result += 1;
                childIndex += 1;
                cookieIndex += 1;
            }
            else
                cookieIndex += 1;
        }

        return result;
    }
};
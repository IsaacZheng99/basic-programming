#pragma once

#include <string>
#include <algorithm>


class Solution541
{
public:
    std::string reverseStr(std::string s, int k)
    {
        for (int cur = 0; cur < s.size(); cur += 2 * k)
        {
            int right = std::min(int(s.size() - 1), cur + k - 1);
            for (int i = cur, j = right; i < (right + cur + 1) / 2; i++, j--)
                std::swap(s[i], s[j]);
        }

        return s;
    }
};
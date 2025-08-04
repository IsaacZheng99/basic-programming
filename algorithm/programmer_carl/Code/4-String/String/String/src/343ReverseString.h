#pragma once

#include <vector>
#include <utility>


class Solution343
{
public:
    void reverseString(std::vector<char>& s)
    {
        for (int i = 0, int j = s.size() - 1; i < s.size() / 2; i++, j--)
            std::swap(s[i], s[j]);
    }
};
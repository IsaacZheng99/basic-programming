#pragma once

#include <vector>
#include <algorithm>


class Solution56
{
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals)
    {
        if (intervals.size() <= 1)
            return intervals;

        std::vector<std::vector<int>> result;
        std::sort(intervals.begin(), intervals.end(), Compare);

        int left = intervals[0][0];
        int right = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= right)
            {
                left = std::min(left, intervals[i][0]);
                right = std::max(right, intervals[i][1]);
            }
            else
            {
                result.push_back(std::vector<int>({ left, right }));
                left = intervals[i][0];
                right = intervals[i][1];
            }

            if (i == intervals.size() - 1)
                result.push_back(std::vector<int>({ left, right }));
        }

        return result;
    }

    static bool Compare(std::vector<int>& left, std::vector<int>& right)
    {
        return left[0] < right[0];
    }
};
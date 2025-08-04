#pragma once

#include <vector>
#include <algorithm>


class Solution435
{
public:
    int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals)
    {
        std::sort(intervals.begin(), intervals.end(), Compare);

        int result = 0;
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] < intervals[i - 1][1])
            {
                result += 1;
                
                if (intervals[i][1] > intervals[i - 1][1])
                {
                    intervals[i][0] = intervals[i - 1][0];
                    intervals[i][1] = intervals[i - 1][1];
                }
                
            }
        }

        return result;
    }

    static bool Compare(std::vector<int>& left, std::vector<int>& right)
    {
        if (left[0] == right[0])
            return left[1] < right[1];
        return left[0] < right[0];
    }
};

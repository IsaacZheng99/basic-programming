#pragma once

#include <vector>
#include <algorithm>


class Solution452
{
public:
    int findMinArrowShots(std::vector<std::vector<int>>& points)
    {
        std::sort(points.begin(), points.end(), Compare);

        int result = 1;
        int left = points[0][0];
        int right = points[0][1];

        for (int i = 1; i < points.size(); i++)
        {
            if (points[i][0] > right)
            {
                result += 1;
                left = points[i][0];
                right = points[i][1];
            }
            else
            {
                left = std::max(left, points[i][0]);
                right = std::min(right, points[i][1]);
            }
        }

        return result;
    }

    static bool Compare(std::vector<int>& left, std::vector<int>& right)
    {
        return left[0] < right[0];
    }
};
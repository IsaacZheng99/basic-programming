#pragma once

#include <vector>


class Solution376
{
public:
    int wiggleMaxLength(std::vector<int>& nums)
    {
        int result = 1;
        bool flag = false;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1] && (i == 1 || !flag))
            {
                result += 1;
                flag = true;
            }
            else if (nums[i] < nums[i - 1] && (i == 1 || flag))
            {
                result += 1;
                flag = false;
            }
        }

        return result;
    }
};
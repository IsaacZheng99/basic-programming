#pragma once

#include <vector>
#include <algorithm>


class Solution45
{
public:
    int jump(std::vector<int>& nums)
    {
        if (nums.size() == 1)
            return 0;

        int result = 0;
        
        int curDistance = 0;
        int nextDistance = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            nextDistance = std::max(nextDistance, nums[i] + i);

            if (i == curDistance)
            {
                result += 1;
                if (nextDistance >= nums.size() - 1)
                    break;
                curDistance = nextDistance;
            }
        }

        return result;
    }
};
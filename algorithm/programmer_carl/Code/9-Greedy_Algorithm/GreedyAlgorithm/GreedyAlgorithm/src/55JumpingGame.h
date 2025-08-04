#pragma once

#include <vector>
#include <algorithm>


class Solution55
{
public:
    bool canJump(std::vector<int>& nums)
    {
        int curIndex = 0;

        while (true)
        {
            int curMax = INT_MIN;
            int nextIndex = 0;
            for (int i = 0; i <= nums[curIndex]; i++)
            {
                if (curIndex + i + nums[i + curIndex] >= nums.size() - 1)
                    return true;

                if (curIndex + i + nums[i + curIndex] > curMax)
                {
                    curMax = curIndex + i + nums[i + curIndex];
                    nextIndex = i + curIndex;
                }
            }

            if (nextIndex == curIndex)
                return false;

            curIndex = nextIndex;
        }

        return false;
    }
};

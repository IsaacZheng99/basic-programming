#pragma once
#include <vector>


class Solution27
{
public:
    int removeElement(std::vector<int>& nums, int val)
    {
        int fast = 0;
        int slow = 0;
        while (fast < nums.size())
        {
            if (nums[fast] != val)
            {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }

        return slow;

    }
};
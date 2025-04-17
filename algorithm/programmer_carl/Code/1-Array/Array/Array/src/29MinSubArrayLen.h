#pragma once
#include <vector>
#include <numeric>


class Solution29
{
public:
    int minSubArrayLen(int target, std::vector<int>& nums)
    {
        int result = INT32_MAX;
        int left = 0;
        int right = 0;
        int sum = 0;
        while (right < nums.size())
        {
            sum += nums[right];
            while (sum >= target)
            {
                int subLength = right - left + 1;
                result = result < subLength ? result : subLength;
                sum -= nums[left];
                left++;
            }
            right++;
        }
        return result == INT32_MAX ? 0 : result;
    }
};

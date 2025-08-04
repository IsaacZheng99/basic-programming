#pragma once

#include <vector>
#include <algorithm>


class Solution300
{
public:
    int lengthOfLIS(std::vector<int>& nums)
    {
        std::vector<int> dp(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                    dp[i] = std::max(dp[i], dp[j] + 1);
            }
            
        }

        auto max_it = std::max_element(dp.begin(), dp.end());

        return *max_it;
    }
};
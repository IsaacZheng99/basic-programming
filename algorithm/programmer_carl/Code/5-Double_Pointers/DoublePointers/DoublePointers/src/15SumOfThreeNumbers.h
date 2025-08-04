#pragma once

#include <vector>
#include <algorithm>


class Solution15
{
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
    {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> result;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i && nums[i] == nums[i - 1])
                continue;
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    result.push_back({ nums[i], nums[j], nums[k] });
                    while (j < k && nums[j] == nums[j + 1])
                        j++;
                    while (j < k && nums[k] == nums[k - 1])
                        k--;
                    j++;
                    k--;
                }
                else if (nums[i] + nums[j] + nums[k] < 0)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }
        return result;
    }
};
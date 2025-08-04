#pragma once

#include <vector>
#include <algorithm>


class Solution18
{
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target)
    {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> result;

        for (int a = 0; a < nums.size(); a++)
        {
            if (nums[a] >= 0 && nums[a] > target)
                return result;
            if (a != 0 && nums[a] == nums[a - 1])
                continue;
            for (int b = a + 1; b < nums.size(); b++)
            {
                if (nums[b] >= 0 && nums[a] + nums[b] > target)
                    break;
                
                if (b != a + 1 && nums[b] == nums[b - 1])
                    continue;

                int c = b + 1;
                int d = nums.size() - 1;

                while (c < d)
                {
                    if (nums[a] + nums[b] == target - nums[c] - nums[d])
                    {
                        result.push_back(std::vector<int>({ nums[a], nums[b], nums[c], nums[d] }));

                        while (c < d && nums[c] == nums[c + 1])
                            c++;
                        while (c < d && nums[d] == nums[d - 1])
                            d--;
                        c++;
                        d--;
                    }
                    else if (nums[a] + nums[b] > target - nums[c] - nums[d])
                        d--;
                    else
                        c++;
                }
            }
        }

        return result;
    }
};
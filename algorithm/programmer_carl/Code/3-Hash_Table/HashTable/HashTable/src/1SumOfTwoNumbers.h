#pragma once

#include <vector>
#include <unordered_map>


class Solution1
{
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        std::vector<int> result(2);
        std::unordered_map<int, int> pairs;
        for (int i = 0; i < nums.size(); i++)
        {
            auto it = pairs.find(target - nums[i]);
            if (it != pairs.end())
            {
                result[0] = it->second;
                result[1] = i;
                return result;
            }
            
            pairs[nums[i]] = i;
        }

        return result;
    }
};
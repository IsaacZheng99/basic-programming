#pragma once

#include <vector>
#include <unordered_map>


class Solution454
{
public:
    int fourSumCount(std::vector<int>& nums1, std::vector<int>& nums2, std::vector<int>& nums3, std::vector<int>& nums4)
    {
        std::unordered_map<int, int> groups;

        for (int num1 : nums1)
            for (int num2 : nums2)
                    groups[num1 + num2] += 1;

        int result = 0;
        for (int num3 : nums3)
            for (int num4 : nums4)
            {
                auto it = groups.find(0 - num3 - num4);
                if (it != groups.end())
                    result += it->second;
            }

        return result;


    }
};
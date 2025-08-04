#pragma once

#include <vector>
#include <algorithm>
#include <numeric>


class Solution1005
{
public:
    int largestSumAfterKNegations(std::vector<int>& nums, int k)
    {
        std::sort(nums.begin(), nums.end(), Compare);

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0 && k)
            {
                nums[i] = -nums[i];
                k -= 1;
            }
        }

        if (k % 2 == 1)
            nums[nums.size() - 1] *= -1;

        return std::accumulate(nums.begin(), nums.end(), 0);
    }
private:
    static bool Compare(int a, int b)
    {
        return std::abs(a) > std::abs(b);
    }
};


class Solution1005
{
public:
    int largestSumAfterKNegations(std::vector<int>& nums, int k)
    {
        std::sort(nums.begin(), nums.end());

        int curIndex = 0;
        while (k && curIndex < nums.size() && nums[curIndex] < 0)
        {
            nums[curIndex] = -nums[curIndex];
            k -= 1;
            curIndex += 1;
        }

        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (k % 2 == 0 || curIndex != nums.size() && nums[curIndex] == 0)
            return sum;
        else
        {
            if (curIndex == 0 || curIndex != nums.size() && nums[curIndex] <= nums[curIndex - 1])
                return sum - 2 * nums[curIndex];
            else
                return sum - 2 * nums[curIndex - 1];
        }
    }
};
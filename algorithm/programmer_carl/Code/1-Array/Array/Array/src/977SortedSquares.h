#pragma once
#include <vector>
#include <cmath>

class Solution977
{
public:
    std::vector<int> sortedSquares(std::vector<int>& nums)
    {
        int size = nums.size();
        int left = 0;
        int right = size - 1;
        int current = size - 1;
        std::vector<int> result;
        result.resize(size);
        while (left <= right)
        {
            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];
            if (leftSquare <= rightSquare)
            {
                result[current] = rightSquare;
                right--;
            }
            else
            {
                result[current] = leftSquare;
                left++;
            }
            current--;
        }
        return result;
    }
};
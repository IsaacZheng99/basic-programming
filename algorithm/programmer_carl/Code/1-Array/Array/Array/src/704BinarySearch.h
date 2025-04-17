#pragma once
#include <vector>


//// solution 1
//class Solution704
//{
//public:
//    int search(std::vector<int>& nums, int target)
//    {
//        int left = 0;
//        int right = nums.size() - 1;
//        while (left <= right)
//        {
//            if (nums[left] == target)  // no need to judge every time
//                return left;
//            else if (nums[right] == target)
//                return right;
//            else if (nums[left] > target || nums[right] < target)
//                return -1;
//            else
//            {
//                int mid = (right + left) / 2;
//                if (nums[mid] == target)
//                    return mid;
//                else if (nums[mid] < target)
//                    left = mid + 1;
//                else if (nums[mid] > target)
//                    right = mid - 1;
//            }
//        }
//
//        return -1;
//    }
//};

// solution 2
class Solution704
{
public:
    int search(std::vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + ((right - left) >> 1);

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }
};
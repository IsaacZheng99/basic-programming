#pragma once
#include <vector>
#include <unordered_set>

class Solution349
{
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        std::unordered_set<int> set1(nums1.begin(), nums1.end());
        std::unordered_set<int> result;
        
        for (int num : nums2)
            if (set1.find(num) != set1.end())
                result.insert(num);

        return std::vector<int>(result.begin(), result.end());
    }
};


//class Solution349
//{
//public:
//    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2)
//    {
//        std::unordered_set<int> set1;
//        std::unordered_set<int> set2;
//        for (int num : nums1)
//            set1.insert(num);
//        for (int num : nums2)
//            set2.insert(num);
//
//        std::vector<int> result;
//        for (int num : set1)
//            if (set2.find(num) != set2.end())
//                result.push_back(num);
//
//        return result;
//    }
//};
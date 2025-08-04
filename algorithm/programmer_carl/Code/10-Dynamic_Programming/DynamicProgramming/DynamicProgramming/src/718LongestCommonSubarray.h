#pragma once

#include <vector>
#include <algorithm>


class Solution718
{
public:
    int findLength(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        int result = 0;
        std::vector<int> dp(nums2.size() + 1, 0);

        for (int i = 1; i <= nums1.size(); i++)
        {
            for (int j = nums2.size(); j >= 1; j--)
            {
                if (nums1[i - 1] == nums2[j - 1])
                {
                    dp[j] = dp[j - 1] + 1;
                    result = std::max(result, dp[j]);
                }
                else
                    dp[j] = 0;
            }
        }

        return result;
    }
};


class Solution718
{
public:
    int findLength(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        int result = 0;
        std::vector<std::vector<int>> dp(nums1.size() + 1, std::vector<int>(nums2.size() + 1, 0));

        for (int i = 1; i <= nums1.size(); i++)
        {
            for (int j = 1; j <= nums2.size(); j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    result = std::max(result, dp[i][j]);
                }
            }
        }

        return result;
    }
};


class Solution718
{
public:
    int findLength(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        int result = 0;
        std::vector<std::vector<int>> dp(nums1.size(), std::vector<int>(nums2.size(), 0));
        
        for (int i = 0; i < nums1.size(); i++)
        {
            if (nums1[i] == nums2[0])
            {
                dp[i][0] = 1;
                result = 1;
            }
        }

        for (int i = 0; i < nums2.size(); i++)
        {
            if (nums2[i] == nums1[0])
            {
                dp[0][i] = 1;
                result = 1;
            }
        }

        for (int i = 1; i < nums1.size(); i++)
        {
            for (int j = 1; j < nums2.size(); j++)
            {
                if (nums1[i] == nums2[j])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    result = std::max(result, dp[i][j]);
                }
            }
        }

        return result;
    }
};
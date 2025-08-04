#pragma once

#include<vector>
#include <algorithm>


class Solution738
{
public:
    int monotoneIncreasingDigits(int n)
    {
        if (n < 10)
            return n;

        std::vector<int> nums;

        while (n)
        {
            nums.push_back(n % 10);
            n = n / 10;
        }

        int flag = -1;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] < nums[i + 1])
            {
                nums[i + 1] -= 1;
                flag = i;
            }
        }

        for (int i = flag; i >= 0; i--)
            nums[i] = 9;

        std::reverse(nums.begin(), nums.end());
        int result = 0;
        long long time = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            result += nums[i] * time;
            time *= 10;
        }

        return result;

    }
};


//class Solution738
//{
//public:
//    int monotoneIncreasingDigits(int n)
//    {
//        if (n < 10)
//            return n;
//
//        std::vector<int> nums;
//
//        while (n)
//        {
//            nums.push_back(n % 10);
//            n = n / 10;
//        }
//
//        std::reverse(nums.begin(), nums.end());
//
//        for (int i = 0; i < nums.size() - 1; i++)
//        {
//            if (nums[i] > nums[i + 1])
//            {
//                for (int j = i + 1; j < nums.size(); j++)
//                    nums[j] = 9;
//                
//                int k = i;
//                if (k == 0 || nums[k] != nums[k - 1])
//                    nums[k] = nums[k] - 1;
//                else
//                {
//                    int temp = nums[k];
//                    nums[k] = 9;
//
//                    for (int l = k - 1; l >= 0; l--)
//                    {
//                        if (l == 0)
//                        {
//                            nums[l] -= 1;
//                            break;
//                        }
//                        else if (nums[l] == temp)
//                        {
//                            if (nums[l] != nums[l - 1])
//                            {
//                                nums[l] -= 1;
//                                break;
//                            }
//                            else
//                                nums[l] = 9;
//                        }
//                    }
//                }
//            }
//        }
//
//        int result = 0;
//        long long time = 1;
//        for (int i = nums.size() - 1; i >= 0; i--)
//        {
//            result += nums[i] * time;
//            time *= 10;
//        }
//
//        return result;
//
//    }
//};

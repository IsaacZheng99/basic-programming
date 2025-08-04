#pragma once

#include<unordered_set>


class Solution202
{
public:
    bool isHappy(int n)
    {
        std::unordered_set<int> nums;
        while (true)
        {
            if (n == 1)
                return true;
            else if (nums.find(n) != nums.end())
                return false;
            nums.insert(n);
            n = square(n);
        }
    }

    int square(int n)
    {
        int result = 0;
        while (n)
        {
            result += (n % 10) * (n % 10);
            n = n / 10;
        }

        return result;
    }
};
#pragma once

#include <vector>
#include <unordered_map>


class Solution860
{
public:
    bool lemonadeChange(std::vector<int>& bills)
    {
        std::unordered_map<int, int> changes;

        for (int bill : bills)
        {
            if (bill == 5)
                changes[5] += 1;
            else if (bill == 10)
            {
                if (!changes[5])
                    return false;

                changes[5] -= 1;
                changes[10] += 1;
            }
            else
            {
                if (changes[10] && changes[5])
                {
                    changes[10] -= 1;
                    changes[5] -= 1;
                    changes[20] += 1;
                }
                else if (changes[5] >= 3)
                {
                    changes[5] -= 3;
                    changes[20] += 1;
                }
                else
                    return false;
            }
        }
        
        return true;
    }
};


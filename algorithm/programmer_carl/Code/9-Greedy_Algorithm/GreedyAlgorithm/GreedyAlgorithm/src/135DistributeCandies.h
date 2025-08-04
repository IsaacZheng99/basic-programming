#pragma once

#include <vector>
#include <algorithm>
#include <numeric>


class Solution135
{
public:
    int candy(std::vector<int>& ratings)
    {
        if (ratings.size() == 1)
            return 1;

        std::vector<int> candies(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++)
        {
            if (ratings[i] > ratings[i - 1])
                candies[i] = candies[i - 1] + 1;
        }

        for (int i = ratings.size() - 1; i >= 1; i--)
        {
            if (ratings[i] < ratings[i - 1])
                candies[i - 1] = std::max(candies[i] + 1, candies[i - 1]);
        }

        return std::accumulate(candies.begin(), candies.end(), 0);
    }
};
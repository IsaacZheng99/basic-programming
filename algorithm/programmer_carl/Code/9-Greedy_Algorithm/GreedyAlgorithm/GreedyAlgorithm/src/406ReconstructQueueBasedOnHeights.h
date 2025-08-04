#pragma once

#include <vector>
#include <algorithm>
#include <list>


class Solution406
{
public:
    std::vector<std::vector<int>> reconstructQueue(std::vector<std::vector<int>>& people)
    {
        std::sort(people.begin(), people.end(), Compare);

        std::list<std::vector<int>> result;

        for (auto& person : people)
        {
            int position = person[1];
            auto it = result.begin();
            while (position--)
            {
                it++;
            }
            result.insert(it, person);
        }

        return std::vector<std::vector<int>>(result.begin(), result.end());

    }

    bool static Compare(std::vector<int>& left, std::vector<int>& right)
    {
        if (left[0] == right[0])
            return left[1] < right[1];

        return left[0] > right[0];
    }
};


class Solution406
{
public:
    std::vector<std::vector<int>> reconstructQueue(std::vector<std::vector<int>>& people)
    {
        std::sort(people.begin(), people.end(), Compare);

        std::vector<std::vector<int>> result;
        result.reserve(people.size());

        for (auto& person : people)
        {
            result.insert(result.begin() + person[1], person);
        }

        return result;

    }

    bool static Compare(std::vector<int>& left, std::vector<int>& right)
    {
        if (left[0] > right[0])
            return true;
        else if (left[0] == right[0] && left[1] < right[1])
            return true;

        return false;
    }
};